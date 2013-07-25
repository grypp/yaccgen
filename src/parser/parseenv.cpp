
#include <iostream>

#include "parseenv.h"
#include "project.h"
/* o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o */

extern int yyparse(void);

/* o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o */
ParseEnv::ParseEnv(std::istream *instream, std::ostream *errstream, const std::string& fname )
{
    yyinstream = instream;
    yyerrstream = errstream;

    yylineno = 1;
    yycolno  = 0;
    yynxtcol = 0;

    transUnit = new TransUnit(fname);
    realfile = transUnit->filename;
    in_realfile = 1;
    filename = transUnit->filename;
    
    parseCtxt = new ParseCtxt;

    err_top_level =0;
    err_cnt = 0;
    err_tok = 0;
    possibleType = true;
    possibleTag = false;
    possibleLabel = false;

    file_ppln=false;
    in_preprocess = 0;
    in_charconst = 0;

    gcc2_paren_cnt = 0;

    tokn_end = &tokn_buff[MAX_TOKN_LEN-1];
}

/* o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o */
ParseEnv::~ParseEnv()
{
    delete parseCtxt;
}

/* o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o */
