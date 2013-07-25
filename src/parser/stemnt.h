


#ifndef    STEMNT_H
#define    STEMNT_H

#include <cstdlib>
#include <iostream>
#include <vector>

#include "symbol.h"
#include "express.h"
#include "decl.h"
#include "callback.h"
#include "location.h"
#include "dup.h"

#include "Traversal.h"


enum StatementType
{
    ST_NullStemnt=0,              // The null statement.

    ST_DeclStemnt,
    ST_TypedefStemnt,
    ST_ExpressionStemnt,

    ST_IfStemnt,
    ST_SwitchStemnt,

    ST_ForStemnt,
    ST_WhileStemnt,
    ST_DoWhileStemnt,

    ST_ContinueStemnt,
    ST_BreakStemnt,
    ST_GotoStemnt,
    ST_ReturnStemnt,

    ST_Block,

    ST_FileLineStemnt,       // #line #file
    ST_InclStemnt,           // #include
    ST_EndInclStemnt
};


enum LabelType
{
    LT_None=0,              // No label - invalid.

    LT_Default,             // default:
    LT_Case,                // case <expr>:
    LT_CaseRange,           // case <expr> ... <expr>: (gcc extension)

    LT_Goto                 // A named label (goto destination).
};


class Label
{
  public:
    Label( LabelType labelType );
    Label( Expression *_expr );
    Label( Expression *_begin, Expression *_end );
    Label( Symbol *sym );
   ~Label();

    Label*  dup0() const;
    Label*  dup() const; 
    void    print(std::ostream& out, int level) const;

    void    findExpr( fnExprCallback cb );

    LabelType    type;

    union
    {
      Expression    *begin;   // for LT_Case, LT_CaseRange
      Symbol        *name;    // for LT_Goto
    };

    Expression    *end;       // for LT_CaseRange

    SymEntry      *syment;
};



typedef    std::vector<Label*>    LabelVector;



class Statement;
typedef Dup<Statement> DupableStatement;

class Statement : public DupableStatement 
{
  public:
    Statement(StatementType stemntType, const Location& location);
    virtual ~Statement();

    virtual void accept(Traversal *t) { t->traverse_statement(this);}

    void addLabel( Label *lbl );    // Add a label to this statement.
    void addHeadLabel( Label *lbl ); 

    virtual bool isBlock() const { return false; }
    virtual bool isFuncDef() const { return false; }
    virtual bool isDeclaration() const { return false; }
    virtual bool isTypedef() const { return false; }

    virtual bool needSemicolon() const { return (type != ST_NullStemnt); }

    virtual bool isFileLine() const { return false; }
    virtual bool isInclude() const { return false; }
    virtual bool isEndInclude() const { return false; }

    virtual Statement *dup0() const; 
    virtual void print(std::ostream& out, int level) const;

    virtual void findExpr( fnExprCallback cb );
    virtual void findStemnt( fnStemntCallback cb ) { (cb)(this); }

    StatementType    type;
    LabelVector      labels;
    Location         location;

    Statement       *next;     // For making a list of statements.

  friend std::ostream& operator<< (std::ostream& out, const Statement& stemnt);
};


class FileLineStemnt : public Statement
{
  public:
    FileLineStemnt(const std::string& incl, int lino, const Location& location);
    virtual ~FileLineStemnt();

    virtual void accept(Traversal *t) { t->traverse_file_line(this);}

    bool isFileline() const { return true; }
    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    std::string  filename;
    int          linenumber;
};

class InclStemnt : public Statement
{
  public:
    InclStemnt(const std::string& incl, const Location& location);
    virtual ~InclStemnt();

    virtual void accept(Traversal *t) { t->traverse_include(this);}

    bool isInclude() const { return true; }
    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    bool         isStandard;      // use brackets
    std::string  filename;
};

class EndInclStemnt : public Statement
{
  public:
    EndInclStemnt(const Location& location);
    virtual ~EndInclStemnt();

    virtual void accept(Traversal *t) { t->traverse_end_include(this);}

    bool isEndInclude() const { return true; }
    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;
};


class ExpressionStemnt : public Statement
{
  public:
    ExpressionStemnt( Expression *expr, const Location& location);
    virtual ~ExpressionStemnt();

    virtual void accept(Traversal *t) { t->traverse_expression(this);}

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );

    Expression    *expression;
};


class IfStemnt : public Statement
{
  public:
    IfStemnt( Expression *_cond,
              Statement *_thenBlk, const Location& location,
	      Statement *_elseBlk = NULL);
    ~IfStemnt();

    virtual void accept(Traversal *t) { t->traverse_if(this);}

    bool needSemicolon() const { return false; }

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );
    void findStemnt( fnStemntCallback cb );

    Expression    *cond;

    Statement     *thenBlk;
    Statement     *elseBlk;        // Can be NULL
};


class SwitchStemnt : public Statement
{
  public:
    SwitchStemnt(Expression *_cond, Statement *_block,
		 const Location& location );
    ~SwitchStemnt();

    virtual void accept(Traversal *t) { t->traverse_switch(this);}

    bool needSemicolon() const { return false; }

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );
    void findStemnt( fnStemntCallback cb );

    Expression    *cond;

    Statement     *block;
};


class ForStemnt : public Statement
{
  public:
    ForStemnt( Expression *_init, Expression *_cond, Expression *_incr,
	       const Location& location, Statement *_block =NULL);
    ~ForStemnt();

    virtual void accept(Traversal *t) { t->traverse_for(this);}

    bool needSemicolon() const { return false; }

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );
    void findStemnt( fnStemntCallback cb );

    Expression    *init;
    Expression    *cond;
    Expression    *incr;

    Statement     *block;        // Can be NULL
};


class WhileStemnt : public Statement
{
  public:
    WhileStemnt( Expression *_cond, Statement *_block,
		 const Location& location);
    ~WhileStemnt();

    virtual void accept(Traversal *t) { t->traverse_while(this);}

    bool needSemicolon() const { return false; }

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );
    void findStemnt( fnStemntCallback cb );

    Expression    *cond;
    Statement     *block;
};


class DoWhileStemnt : public Statement
{
  public:
    DoWhileStemnt( Expression *_cond, Statement *_block,
		   const Location& location);
    ~DoWhileStemnt();

    virtual void accept(Traversal *t) { t->traverse_do_while(this);}

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );
    void findStemnt( fnStemntCallback cb );

    Expression    *cond;
    Statement     *block;
};


class GotoStemnt : public Statement
{
  public:
    GotoStemnt( Symbol *_dest, const Location& location);
    ~GotoStemnt();

    virtual void accept(Traversal *t) { t->traverse_goto(this);}

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    Symbol        *dest;
};


class ReturnStemnt : public Statement
{
  public:
    ReturnStemnt( Expression *_result, const Location& location);
    ~ReturnStemnt();

    virtual void accept(Traversal *t) { t->traverse_return(this);}

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );

    Expression    *result;        // Can be NULL.
};


class DeclStemnt : public Statement
{
  public:
    DeclStemnt(const Location& location, StatementType stype = ST_DeclStemnt);
    virtual ~DeclStemnt();

    virtual void accept(Traversal *t) { t->traverse_declaration(this);}

    // Declarations print their own semicolon.
    bool needSemicolon() const { return false; }
    bool isDeclaration() const { return true; }

    Statement *dup0() const; 
    virtual void print(std::ostream& out, int level) const;

    // Only converts if necessary.
    DeclStemnt *convertToTypedef();

    void addDecl(Decl *decl);
    void addDecls(Decl *decls);

    void findExpr( fnExprCallback cb );

    // The type(s).
    DeclVector    decls;
};

class TypedefStemnt : public DeclStemnt
{
  public:
    TypedefStemnt(const Location& location);
   ~TypedefStemnt();

    virtual void accept(Traversal *t) { t->traverse_typedef(this);}

    bool isTypedef() const { return true; }

    void print(std::ostream& out, int level) const;
};


class Block : public Statement
{
  public:
    Block(const Location& location);
    virtual ~Block();

    virtual void accept(Traversal *t) { t->traverse_block(this);}

    void add(Statement *stemnt);

    void addStatements(Statement *stemnt);
    void addDecls(Decl *decls);

    virtual bool isBlock() const { return true; }
    bool needSemicolon() const { return false; }

    virtual Statement *dup0() const; 
    virtual void print(std::ostream& out, int level) const;

    virtual void findExpr( fnExprCallback cb );
    void findStemnt( fnStemntCallback cb );

    void insert(Statement *stemnt, Statement *after=NULL);

    Statement     *head;    // List of statements in this block.
    Statement     *tail;
};


// Not really true, but this is very convienent.
class FunctionDef : public Block
{
  public:
    FunctionDef(const Location& location);
   ~FunctionDef();

    virtual void accept(Traversal *t) { t->traverse_function_definition(this);}

    bool isFuncDef() const { return true; }

    Statement *dup0() const; 
    void print(std::ostream& out, int level) const;

    void findExpr( fnExprCallback cb );

    Symbol  *FunctionName() const;

    Decl          *decl;    // The declaration.
};



Statement  *ReverseList( Statement* sList );

void        indent(std::ostream& out, int level);
void        printNull(std::ostream& out, int level);
void        printBlock(std::ostream& out, int level, Statement *block);


// For debugging.
char *nameOfStatementType( StatementType type );
char *nameOfLabelType( LabelType type );



#endif  /* STEMNT_H */

