


#include <cstring>
#include <cassert>

#include "stemnt.h"
#include "symbol.h"
#include "decl.h"
#include "project.h"

#include "gram.h"

//#define PRINT_LOCATION


//  indent - 2 spaces per level.
void
indent(std::ostream& out, int level)
{
    if (level > 0)
    {
        for (int j=level; j > 0; j--)
          out << "  ";
    }
}


void
printNull(std::ostream& out, int level)
{
    indent(out,level);
    out << ";\n";
}


void
printBlock(std::ostream& out, int level, Statement *block)
{
    if (block == NULL)
        printNull(out,level+1);
    else if (block->isBlock())
        block->print(out,level);
    else
    {
        block->print(out,level+1);
        if (block->needSemicolon())
            out << ";";
    }
}


Statement*
ReverseList( Statement* sList )
{
    Statement*    head = NULL;

    while (sList != NULL)
    {
        Statement*    ste = sList;

        sList = sList->next;

        ste->next = head;
        head = ste;
    }

    return head; 
}


Label::Label( LabelType labelType )
{
    type  = labelType;
    begin = NULL;
    end   = NULL;
}   

Label::Label( Expression *expr )
{
    type = LT_Case;
    begin = expr;
    end   = NULL;
}   

Label::Label( Expression *_begin, Expression *_end )
{
    type = LT_CaseRange;
    begin = _begin;
    end   = _end;
}

Label::Label( Symbol *sym )
{
    type = LT_Goto;
    name = sym;
    end   = NULL;
}   


Label::~Label()
{
    switch (type)
    {
        case LT_Case:
        case LT_CaseRange:
            delete begin;
            delete end;
            break;

        case LT_Goto:
            delete name;
            break;

        default:
            break;
    }
}


Label*
Label::dup() const
{
    Label *ret = this ? dup0() : NULL;
    return ret;
}

Label*
Label::dup0() const
{
    Label *ret = new Label(type);

    switch (type)
    {
      default:
      case LT_None:
      case LT_Default:
        break;

      case LT_CaseRange:
        ret->end = end->dup();
      case LT_Case:
        ret->begin = begin->dup();
        break;

      case LT_Goto:
        ret->name = name->dup();
        break;
    }
    
    return ret;
}


void
Label::print(std::ostream& out, int level) const
{
    indent(out,level-1);

    switch (type)
    {
        case LT_None:
            assert(0);
            break;

        case LT_Default:
            out << "default";
            break;

        case LT_Case:
            assert(begin);
            out << "case " << *begin;
            break;

        case LT_CaseRange:
            assert(begin);
            assert(end);
            out << "case " << *begin << " ... " << *end;
            break;

        case LT_Goto:
            assert(name);
            out << *name;
            break;
    }

    out << ":\n";
}


void
Label::findExpr( fnExprCallback cb )
{
    switch (type)
    {
        default:
            break;

        case LT_CaseRange:
            end->findExpr(cb);
        case LT_Case:
            begin->findExpr(cb);
            break;
    }
}


Statement::Statement(StatementType stemntType, const Location& l)
  : location(l)
{
    type  = stemntType;
    next = NULL;
}


Statement::~Statement()
{
    LabelVector::iterator    j;

    for (j=labels.begin(); j != labels.end(); j++)
    {
        delete *j;
    }
}


void
Statement::addLabel( Label *lbl )
{
    labels.push_back(lbl);

    // Hook the label's symtable entry back to this statement.
    if (lbl->type == LT_Goto)
    {
        if (lbl->name->entry != NULL)
            lbl->name->entry->u2LabelPosition = this;
    }
}

void
Statement::addHeadLabel( Label *lbl )
{
    labels.insert(labels.begin(),lbl);

    // Hook the label's symtable entry back to this statement.
    if (lbl->type == LT_Goto)
    {
        if (lbl->name->entry != NULL)
	{
            lbl->name->entry->u2LabelPosition = this;
            lbl->name->entry->uLabelDef = lbl;
        }
    }
}


Statement*
Statement::dup0() const
{
    Statement *ret = new Statement(type, location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
Statement::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* Statement:" ;
        location.printLocation(out) ;
        out << " */";
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    switch (type)
    {
      default:
        out << __PRETTY_FUNCTION__ << std::endl;
        out << nameOfStatementType(type) << std::endl;
        break;

      case ST_NullStemnt:          // The null statement.
        out << ";";
        break;

      case ST_ContinueStemnt:
        out << "continue";
        break;

      case ST_BreakStemnt:
        out << "break";
        break;
    }
}


void
Statement::findExpr( fnExprCallback cb )
{
    LabelVector::iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->findExpr(cb);
}


FileLineStemnt::FileLineStemnt(const std::string& incl, int lino, const Location& l):
  Statement( ST_FileLineStemnt, l ), filename(incl), linenumber(lino)
{
}


FileLineStemnt::~FileLineStemnt()
{
}


Statement*
FileLineStemnt::dup0() const
{
    FileLineStemnt *ret = new FileLineStemnt(filename, linenumber, location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
FileLineStemnt::print(std::ostream& out, int level) const
{
#ifdef PRINT_LOCATION
  out << "$<FileLineStemnt:" ;
  location.printLocation(out) ;
  out << ">$";
#endif

    if (linenumber > 0)
        out << "#line " << linenumber;
    else
        out << "#file";
      
    out << " \"" << filename << "\"" << std::endl;
}


InclStemnt::InclStemnt(const std::string& incl, const Location& l):
  Statement( ST_InclStemnt, l )
{
static const char  *NrmPath[] = { "./", NULL };

    int    j;

    isStandard = false;
    filename = incl;

    for (j=0; StdPath[j]; j++)
    {
        if (strncmp(filename.c_str(),StdPath[j],strlen(StdPath[j])) == 0)
        {
            isStandard = true;
            filename = &(filename.c_str()[strlen(StdPath[j])]);
        }
    }

    for (j=0; NrmPath[j]; j++)
    {
        if (strncmp(filename.c_str(),NrmPath[j],strlen(NrmPath[j])) == 0)
        {
            filename = &(filename.c_str()[strlen(NrmPath[j])]);
        }
    }
}


InclStemnt::~InclStemnt()
{
}


Statement*
InclStemnt::dup0() const
{
    InclStemnt *ret = new InclStemnt(filename, location);
    ret->isStandard = isStandard;
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
InclStemnt::print(std::ostream& out, int level) const
{
#ifdef PRINT_LOCATION
  out << "$<InclStemnt:" ;
  location.printLocation(out) ;
  out << ">$";
#endif

    out << "#include " << (isStandard ? '<' : '"');
    out << filename << (isStandard ? '>' : '"') << std::endl;
}


EndInclStemnt::EndInclStemnt(const Location& l)
           : Statement( ST_EndInclStemnt, l )
{
}


EndInclStemnt::~EndInclStemnt()
{
}


Statement*
EndInclStemnt::dup0() const
{
    EndInclStemnt *ret = new EndInclStemnt(location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
EndInclStemnt::print(std::ostream& out, int level) const
{
#ifdef PRINT_LOCATION
  out << "$<EndInclStemnt:" ;
  location.printLocation(out) ;
  out << ">$";
#endif
}


ExpressionStemnt::ExpressionStemnt( Expression *expr, const Location& l)
                 : Statement( ST_ExpressionStemnt, l )
{
    expression = expr;
}


ExpressionStemnt::~ExpressionStemnt()
{
    delete expression;
}


Statement*
ExpressionStemnt::dup0() const
{
    ExpressionStemnt *ret = new ExpressionStemnt(expression->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
ExpressionStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* ExpressionStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    assert(expression);
    out << *expression;
}


void
ExpressionStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);
    expression->findExpr(cb);
}


IfStemnt::IfStemnt( Expression *_cond,
                    Statement *_thenBlk, const Location& l,
                    Statement *_elseBlk /* =NULL */)
         : Statement( ST_IfStemnt, l )
{
    cond = _cond;
    thenBlk = _thenBlk;
    elseBlk = _elseBlk;
}


IfStemnt::~IfStemnt()
{
    delete cond;
    delete thenBlk;
    delete elseBlk;
}


Statement*
IfStemnt::dup0() const
{
    IfStemnt *ret = new IfStemnt(cond->dup(),thenBlk->dup(),location,elseBlk->dup());
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
IfStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* IfStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "if (" << *cond << ")\n";
    printBlock(out,level,thenBlk);

    if (elseBlk)
    {
        out << std::endl;
        indent(out,level);
        out << "else\n";
        printBlock(out,level,elseBlk);
    }
}


void
IfStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    cond->findExpr(cb);

    thenBlk->findExpr(cb);

    if (elseBlk)
        elseBlk->findExpr(cb);
}


void
IfStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    thenBlk->findStemnt(cb);

    if (elseBlk)
        elseBlk->findStemnt(cb);
}


SwitchStemnt::SwitchStemnt( Expression *_cond, Statement *_block,
			    const Location& l )
             : Statement( ST_SwitchStemnt, l )
{
    cond = _cond;
    block = _block;
}


SwitchStemnt::~SwitchStemnt()
{
    delete cond;
    delete block;
}


Statement*
SwitchStemnt::dup0() const
{
    SwitchStemnt *ret = new SwitchStemnt(cond->dup(),block->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
SwitchStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* SwitchStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "switch (" << *cond << ")\n";

    printBlock(out,level,block);
}


void
SwitchStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);
    cond->findExpr(cb);
    block->findExpr(cb);
}


void
SwitchStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    block->findStemnt(cb);
}


ForStemnt::ForStemnt( Expression *_init, Expression *_cond,
                      Expression *_incr, const Location& l,
		      Statement *_block /* =NULL */)
          : Statement( ST_ForStemnt, l )
{
    init = _init;
    cond = _cond;
    incr = _incr;

    block = _block;
}


ForStemnt::~ForStemnt()
{
    delete init;
    delete cond;
    delete incr;

    delete block;
}


Statement*
ForStemnt::dup0() const
{
    ForStemnt *ret = new ForStemnt(init->dup(),cond->dup(),incr->dup(),
                                   location,block->dup());
                                   
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
ForStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* ForStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "for (";

    if (init)
        out << *init;
    out << "; ";

    if (cond)
        out << *cond;
    out << "; ";

    if (incr)
        out << *incr;
    out << ")\n";

    printBlock(out,level,block);
}


void
ForStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    if (init != NULL)
        init->findExpr(cb);

    if (cond != NULL)
        cond->findExpr(cb);

    if (incr != NULL)
        incr->findExpr(cb);

    if (block != NULL)
        block->findExpr(cb);
}


void
ForStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    if (block)
        block->findStemnt(cb);
}


WhileStemnt::WhileStemnt( Expression *_cond, Statement *_block,
			  const Location& l)
            : Statement( ST_WhileStemnt, l )
{
    cond = _cond;
    block = _block;
}


WhileStemnt::~WhileStemnt()
{
    delete cond;
    delete block;
}


Statement*
WhileStemnt::dup0() const
{
    WhileStemnt *ret = new WhileStemnt(cond->dup(),block->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
WhileStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* WhileStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "while (" << *cond << ")\n";

    printBlock(out,level,block);
}


void
WhileStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    cond->findExpr(cb);

    if (block)
        block->findExpr(cb);
}


void
WhileStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    if (block)
        block->findStemnt(cb);
}


DoWhileStemnt::DoWhileStemnt( Expression *_cond, Statement *_block,
			     const Location& l)
              : Statement( ST_DoWhileStemnt, l )
{
    cond = _cond;
    block = _block;
}


DoWhileStemnt::~DoWhileStemnt()
{
    delete cond;
    delete block;
}


Statement*
DoWhileStemnt::dup0() const
{
    DoWhileStemnt *ret = new DoWhileStemnt(cond->dup(),block->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
DoWhileStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* DoWhileStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "do ";

    if (!block->isBlock())
        out << std::endl;

    printBlock(out,level,block);

    if (!block->isBlock())
        out << std::endl;

    indent(out,level);
    out << "while (" << *cond << ")";
}


void
DoWhileStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    cond->findExpr(cb);

    if (block)
        block->findExpr(cb);
}


void
DoWhileStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    if (block)
        block->findStemnt(cb);
}


GotoStemnt::GotoStemnt( Symbol *_dest, const Location& l)
           : Statement( ST_GotoStemnt, l )
{
    dest = _dest;
}


GotoStemnt::~GotoStemnt()
{
    delete dest;
}


Statement*
GotoStemnt::dup0() const
{
    GotoStemnt *ret = new GotoStemnt(dest->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
GotoStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* GotoStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "goto " << *dest;
}


ReturnStemnt::ReturnStemnt( Expression *_result, const Location& l)
             : Statement( ST_ReturnStemnt, l )
{
    result = _result;
}


ReturnStemnt::~ReturnStemnt()
{
    delete result;
}


Statement*
ReturnStemnt::dup0() const
{
    ReturnStemnt *ret = new ReturnStemnt(result->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}


void
ReturnStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* ReturnStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "return";

    if (result)
        out << " " << *result;
}


void
ReturnStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    if (result)
        result->findExpr(cb);
}


DeclStemnt::DeclStemnt(const Location& l,
		       StatementType stype /* =ST_DeclStemnt */)
      : Statement( stype, l )
{
}


DeclStemnt::~DeclStemnt()
{
    DeclVector::iterator    j;

    for (j=decls.begin(); j != decls.end(); j++)
        delete *j;
}


void
DeclStemnt::addDecl(Decl *decl)
{
    decls.push_back(decl);
}

void
DeclStemnt::addDecls(Decl *decls)
{
    Decl    *decl = decls;

    while (decls != NULL)
    {
        decls = decls->next;
        decl->next = NULL;
        //std::cout << "Decl is: ";
        //decl->print(std::cout,true);
        //std::cout << std::endl;
        addDecl(decl);
        decl = decls;
    }
}


Statement*
DeclStemnt::dup0() const
{
    DeclStemnt *ret;
    if (type == ST_TypedefStemnt)
        ret = new TypedefStemnt(location);
    else
        ret = new DeclStemnt(location);

    DeclVector::const_iterator    j;
    for (j=decls.begin(); j != decls.end(); j++)
        ret->addDecl((*j)->dup());

    LabelVector::const_iterator    k;
    for (k=labels.begin(); k != labels.end(); k++)
        ret->addLabel((*k)->dup());

    return ret;
}


DeclStemnt*
DeclStemnt::convertToTypedef()
{
    // Nothing to do?
    if (isTypedef())
        return this;

    TypedefStemnt *ret = new TypedefStemnt(location);

    // Since we are really the same thing,
    // let's just steal the insides.
    LabelVector::iterator    k;
    for (k=labels.begin(); k != labels.end(); k++)
    {
        ret->addLabel(*k);
    }
    labels.clear();

    ret->next    = next;
    next = NULL;

    DeclVector::iterator    j;

    for (j=decls.begin(); j != decls.end(); j++)
    {
        ret->addDecl(*j);
    }

    decls.clear();

    delete this;        // Danger - Will Robinson!

    return ret;
}


void
DeclStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* DeclStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    if (!decls.empty())
    {
        DeclVector::const_iterator    j = decls.begin();

        (*j)->print(out,true,level);
        for (j++; j != decls.end(); j++)
        {
            out << ", ";
            (*j)->print(out,false,level);
        }
    }

    out << ";";
}


void
DeclStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    DeclVector::iterator    j;

    for (j = decls.begin(); j != decls.end(); j++)
    {
        (*j)->findExpr(cb);
    }
}


TypedefStemnt::TypedefStemnt(const Location& l)
              : DeclStemnt( l, ST_TypedefStemnt )
{
}

TypedefStemnt::~TypedefStemnt()
{
}


void
TypedefStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* TypedefStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "typedef ";

    if (!decls.empty())
    {
        DeclVector::const_iterator    j = decls.begin();

        (*j)->print(out,true,level);
        for (j++; j != decls.end(); j++)
        {
            out << ", ";
            (*j)->print(out,false,level);
        }
    }

    out << ";";
}


Block::Block(const Location& l)
      : Statement( ST_Block , l )
{
    head = tail = NULL;
}


Block::~Block()
{
    Statement *stemnt, *prevStemnt = NULL;

    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        delete prevStemnt;
        prevStemnt = stemnt;
    }
    delete prevStemnt;
}


void
Block::add(Statement *stemnt)
{
    if (stemnt)
    {
        stemnt->next = NULL;
    
        if (tail)
            tail->next = stemnt;
        else
            head = stemnt;
    
        tail = stemnt;
    }
}


void
Block::addStatements(Statement* stemnts)
{
    Statement*    stemnt;

    while (stemnts != NULL)
    {
        stemnt = stemnts;
        stemnts = stemnts->next;

        stemnt->next = NULL;
        add(stemnt);
    }
}

void
Block::addDecls(Decl* decls)
{
    Decl    *decl = decls;

    while (decls != NULL)
    {
        DeclStemnt*   ds = new DeclStemnt(location);

        decls = decls->next;
        decl->next = NULL;

        ds->addDecl(decl);
        add(ds);        

        decl = decls;
    }
}


Statement*
Block::dup0() const
{
    Block *ret = new Block(location);

    for (Statement *stemnt=head; stemnt; stemnt=stemnt->next)
        ret->add(stemnt->dup());

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());

    return ret;
}


void
Block::print(std::ostream& out, int level) const
{
    bool       isDecl;
    Statement *stemnt;

    if (Project::gDebug)
    {
        out << "/* BlockStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "{\n";

    isDecl = (head != NULL) ? head->isDeclaration() : false;
    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        if (isDecl && !stemnt->isDeclaration())
        {
            isDecl = false;
            out << std::endl;
        }

        stemnt->print(out,level+1);

        if (stemnt->needSemicolon())
            out << ";";
        out << std::endl;
    }

    indent(out,level);
    out << "}\n";
}


void
Block::findExpr( fnExprCallback cb )
{
    Statement *stemnt;

    Statement::findExpr(cb);

    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        stemnt->findExpr(cb);
    }
}


void
Block::findStemnt( fnStemntCallback cb )
{
    Statement *stemnt;

    (cb)(this);

    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        stemnt->findStemnt(cb);
    }
}


void
Block::insert(Statement *stemnt, Statement *after /* =NULL */)
{
    if (stemnt)
    {
        stemnt->next = NULL;
    
        if (tail)
        {
            if (after)
            {
                stemnt->next = after->next;
                after->next = stemnt;
            }
            else
            {
                stemnt->next = head;
                head = stemnt;
            }

            if (stemnt->next == NULL)
                tail = stemnt;
        }
        else
            head = tail = stemnt;
    }
}


FunctionDef::FunctionDef(const Location& l)
            : Block(l)
{
    decl = NULL;
}

FunctionDef::~FunctionDef()
{
    delete decl;
}


Statement*
FunctionDef::dup0() const
{
    FunctionDef *ret = new FunctionDef(location);
    ret->decl = decl->dup();

    for (Statement *stemnt=head; stemnt; stemnt=stemnt->next)
        ret->add(stemnt->dup());

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());

    return ret;
}


void
FunctionDef::print(std::ostream& out, int) const
{
    if (Project::gDebug)
    {
        out << "/* FunctionDef:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    decl->print(out,true); 
    out << std::endl;

    Block::print(out,0);
}


void
FunctionDef::findExpr( fnExprCallback cb )
{
    decl->findExpr(cb);

    Block::findExpr(cb);
}


Symbol*
FunctionDef::FunctionName() const
{
    return decl->name;
}


std::ostream&
operator<< (std::ostream& out, const Statement& stemnt)
{
    stemnt.print(out,0);
    return out;
}



#define  SHOW(X)  case X: return #X

char*
nameOfStatementType( StatementType type )
{
    switch (type)
    {
        default:
            return "Unknown StatementType";

        SHOW(ST_NullStemnt);
        SHOW(ST_DeclStemnt);
        SHOW(ST_ExpressionStemnt);
        SHOW(ST_IfStemnt);
        SHOW(ST_SwitchStemnt);
        SHOW(ST_ForStemnt);
        SHOW(ST_WhileStemnt);
        SHOW(ST_DoWhileStemnt);
        SHOW(ST_ContinueStemnt);
        SHOW(ST_BreakStemnt);
        SHOW(ST_GotoStemnt);
        SHOW(ST_ReturnStemnt);
        SHOW(ST_Block);
        SHOW(ST_InclStemnt);
        SHOW(ST_EndInclStemnt);
    }
}


char*
nameOfLabelType( LabelType type )
{
    switch (type)
    {
        default:
            return "Unknown LabelType";

        SHOW(LT_None);        // No label - invalid.
        SHOW(LT_Default);     // default:
        SHOW(LT_Case);        // case <expr>:
        SHOW(LT_Goto);        // A named label (goto destination).
    }
}

#undef SHOW


