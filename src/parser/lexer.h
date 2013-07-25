#ifndef LEXER_H
#define LEXER_H

#include <cstdio>

#include "config.h"
#include "decl.h"
#include "express.h"

/**************************************************************************/

class Label;
class Statement;
class DeclStemnt;
class TransUnit;

/**************************************************************************/

/* Maximum length for strings and identifiers */
#define MAX_STRING_LEN      512

/* If we allow a comment as a token, we need to let them be larger. */
#define MAX_TOKN_LEN        512

/**************************************************************************/

typedef union
{
    Location        *loc;

    BinaryOp        binOp;
    RelOp           relOp;
    AssignOp        assignOp;

    Symbol          *symbol;

    BaseTypeSpec    typeSpec;
    TypeQual        typeQual;
    StorageType     storage;
    GccAttrib       *gccAttrib;

    Type            *type;
    PtrType         *ptr;
    FunctionType    *fct;
    BaseType        *base;
    Decl            *decl;
    StructDef       *strDef;
    EnumDef         *enDef;

    Expression      *value;
    Constant        *consValue;
    EnumConstant    *enConst;
    ArrayConstant   *arrayConst;

    Label           *label;
    Statement       *stemnt;

    DeclStemnt      *declStemnt;
    FunctionDef     *functionDef;

    TransUnit       *transunit;

} lex_union;

/******************************************************/

/*    For Flex compatibility  */

#undef  YYSTYPE
#define YYSTYPE lex_union

/******************************************************/

int  get_lineno (bool file_ppln,char *txt, Statement** stement);
void yywarn  (char *s);
int  yyerror (char *s);
int  yyerr   (char *s);
int  yyerr   (char *s, const std::string & str);

/******************************************************/

#endif  /* LEXER_H */
