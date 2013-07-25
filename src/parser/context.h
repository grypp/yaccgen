
#ifndef CT_CONTEXT_H
#define CT_CONTEXT_H

#include <cstdio>
#include <string>

#include "config.h"
#include "decl.h"



class SymEntry ;
class Symbol ;
class Label ;

class ParseEnvCtxt {
  public:
    ParseEnvCtxt (void) {} ;
   ~ParseEnvCtxt (void) {} ;

    BaseType     *decl_specs ;         // Pointer to the parsed decl_specs
    int           nb_decl_uses ;       // Nb extend of the parsed decl_specs
    int           varParam ;           // value of varParam at decl_specs parsing
    SymEntry     *possibleDuplication ;// Pointer to the possible previous FctDeclEntry
    bool          isKnR ;              // true -> existing Parameter 
};

class ParseCtxt
{
  public:
    ParseCtxt (void) ;
   ~ParseCtxt (void) ;
   
    void PushCtxt (void) ;
    void PopCtxt (bool assert_checking) ;
    void ReinitializeCtxt (void) ;

    void SetDeclCtxt (BaseType *decl_specsCtxt) ;
    Type*UseDeclCtxt (void) ;
    void ResetDeclCtxt (void) ;

    void IncrVarParam (int incr) { 
      curCtxt->varParam += incr ; 
      } ;
    void SetVarParam (int val, bool assert_checking, int should_be) ;
    void ResetVarParam (void) { 
      curCtxt->varParam = 0 ; 
      } ;
    
    void SetIsFieldId (bool is) { 
      isFieldId = is ; 
      } ;
      
    void SetIsKnR (bool is) { 
      curCtxt->isKnR = is ; 
      } ;
    
    Label*    Mk_named_label (Symbol *labelSym, SymTbl *labels) ;
    BaseType* Mk_tag_ref (BaseTypeSpec tagType, Symbol *tagSym, SymTbl *tags) ;
    BaseType* Mk_tag_def (BaseTypeSpec tagType, Symbol *tagSym, SymTbl *tags) ;
    Decl*     Mk_direct_declarator_reentrance (Symbol *declSym, SymTbl *syms) ;
    void      Mk_declarator (Decl *decl) ;
    void      Mk_func_declarator (Decl *decl) ;
    
    ParseEnvCtxt *curCtxt ; // public for assertion checking! 
     
  protected:    
    bool IsTypedefDeclCtxt (void) { 
      return curCtxt->decl_specs && curCtxt->decl_specs->storage == ST_Typedef ; 
      } ;
  
    ParseEnvCtxt *tabCtxt ; 
    int           size ;    
    bool          isFieldId ; // true -> ComponentEntry, other -> otherEntry 
};

//  o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o

void yyCheckLabelsDefinition (SymTbl *labels) ;
//  o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o

#endif
