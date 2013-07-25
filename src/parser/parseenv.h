#ifndef PARSEENV_H
#define PARSEENV_H

#include <cstdio>
#include <string>

#include "config.h"

#include "context.h"
#include "lexer.h"


#define    YYBUFF_SIZE    4096

    /*  Redefinition - original provided by flex/lex */
#ifndef    YY_BUFFER_STATE_DEFD
typedef  struct yy_buffer_state  *YY_BUFFER_STATE;
#endif


class TransUnit;
class Base;
class SymEntry;

class ParseEnv
{
  public:
    ParseEnv(std::istream *instream, std::ostream *errstream, const std::string &fname);
   ~ParseEnv();

    TransUnit         *transUnit;   // Pointer to the parsed translation unit

    std::string        realfile;    // The file _really_ being parsed.
    int                in_realfile;
    std::string        filename;

    std::istream       *yyinstream;  // A pointer to an open file
    std::ostream       *yyerrstream;

    int                yylineno;    // Line number
    int                yycolno;     // Column number
    int                yynxtcol;    // next Column number

    YY_BUFFER_STATE    yybuff;      // A buffer for the lexer

    ParseCtxt         *parseCtxt;

    std::string        line;
    std::string        last_line;
    
    // for the lexer
    int   err_top_level;
    int   err_cnt;
    int   err_tok;
    bool  possibleType;
    bool  possibleTag;
    bool  possibleLabel;

    bool file_ppln;
    int  in_preprocess;
    int  in_charconst;

    int  gcc2_paren_cnt;

    char  tokn_buff[MAX_TOKN_LEN];
    char *tokn_end;
    char *tokn_ptr;

    bool  isWide;
    
    bool cpp_comment_warn;
};


#endif    /* PARSEENV_H  */
