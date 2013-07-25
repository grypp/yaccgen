#ifndef    CALLBACK_H
#define    CALLBACK_H

class Decl;
class Type;

class Expression;
class Statement;
class FunctionDef;



typedef void (*fnExprCallback)(Expression *expr);

typedef void (*fnStemntCallback)(Statement *stemnt);

typedef void (*fnFunctionCallback)(FunctionDef *function);



#endif  /* CALLBACK_H */

