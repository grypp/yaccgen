
#ifndef    PROJECT_H
#define    PROJECT_H

#include <cstdlib>
#include <iostream>
#include <cassert>

#include "parseenv.h"
#include "symbol.h"
#include "callback.h"



#define    VERSION    "CTool Version 2.10"



extern void   InitStdPath(
         // String format for reprocessing command.
                // Default value = NULL string which implies
                // the use default preprocessing string format
                // specified by define USE_xxx_4_CPP
                // i.e. "gcc -E -DCTOOL -D__STDC__ %s > %s"
                const char* cpp_cmd=(const char *) NULL
    );

extern char  *StdPath[];



class Statement;

typedef    std::vector<TransUnit*>    TransUnitVector;

class TransUnit
{
  public:
    /* List of Statements */
    TransUnit(const std::string& fname);
    ~TransUnit();

    void findStemnt( fnStemntCallback cb );
    void findFunctionDef( fnFunctionCallback cb );

    void add( Statement *stemnt );
    void insert(Statement *stemnt, Statement *after=NULL);
	bool insertBefore(Statement *stemnt, Statement *before);

    const std::string  filename;   // The file we parsed this from.

    Statement         *head;       // The first statement in the list.
    Statement         *tail;       // The last statement in the list.

    // Hold onto this context.
    Context            contxt;

  friend std::ostream& operator<< (std::ostream& out, const TransUnit& tu);
};



class Project
{
  public:
    // List of TransUnit
    Project();
    ~Project();

    // Parse a file and add it to the list of stored TransUnits
    TransUnit *parse( const char *path, bool use_cpp = true,
                      // Directory for preprocessing.
                      // Default value = NULL string which implies
                      // the preprocessing in the current directory.
                      const char * cpp_dir=(const char *)NULL,

                      // To keep or remove output preprocessing file.
                      // Default value = remove
                      bool keep_cpp_file=false,

                      // Name of the output preprocessing file.
                      // Default value = NULL string which gives
                      // `dirname path`/`basename path .c`_pp
                      const char * cpp_file=(const char *)NULL,

               // String format for reprocessing command.
                      // Default value = NULL string which implies
                      // the use default preprocessing string format
                      // specified by define USE_xxx_4_CPP such as
                      // "gcc -E -DCTOOL -D__STDC__ %s > %s"
                      const char * cpp_cmd=(const char *)NULL,

               // String format used for changing directory
                      // when a preprocessing directory is given.
                      const char * cd_cmd="cd % ; "
                    );

    TransUnitVector units;
    
    // The stack and top of the stack
    ParseEnv     *Parse_TOS;

    // All types used in this project.
    Type         *typeList;
    
    void SetPrintOption(bool debug) { gDebug = debug; }

    static bool gDebug;
    
    // Warnings
    
    bool warn_variable;
    bool warn_cpp_comment;
};



extern Project *gProject;



#endif  /* PROJECT_H */

