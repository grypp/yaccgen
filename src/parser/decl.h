
#ifndef    DECL_H
#define    DECL_H

#include <iostream>
#include <vector>
#include <cassert>

#include "symbol.h"
#include "callback.h"
#include "location.h"

#include "dup.h"

#include "Traversal.h"

class Constant;
class Expression;
class EnumConstant;



typedef unsigned long BaseTypeSpec;

const BaseTypeSpec BT_NoType       = 0x00000000;  // no type provided
const BaseTypeSpec BT_Void         = 0x00000001;  // explicitly no type
const BaseTypeSpec BT_Bool         = 0x00000002;
const BaseTypeSpec BT_Char         = 0x00000004;
const BaseTypeSpec BT_Short        = 0x00000008;
const BaseTypeSpec BT_Int          = 0x00000010;
const BaseTypeSpec BT_Int64        = 0x00000020;
const BaseTypeSpec BT_Int32        = 0x00000040;
const BaseTypeSpec BT_Int16        = 0x00000080;
const BaseTypeSpec BT_Int8         = 0x00000100;
const BaseTypeSpec BT_Long         = 0x00000200;
const BaseTypeSpec BT_LongLong     = 0x00000400;  // a likely C9X addition
const BaseTypeSpec BT_Float        = 0x00000800;
const BaseTypeSpec BT_Double       = 0x00001000;
const BaseTypeSpec BT_Ellipsis     = 0x00002000;

const BaseTypeSpec BT_Struct       = 0x00008000;
const BaseTypeSpec BT_Union        = 0x00010000;
const BaseTypeSpec BT_Enum         = 0x00020000;
const BaseTypeSpec BT_UserType     = 0x00040000;
const BaseTypeSpec BT_BaseMask     = 0x0004FFFF;

// Sign indicator
const BaseTypeSpec BT_Signed       = 0x00100000;
const BaseTypeSpec BT_UnSigned     = 0x00200000;
const BaseTypeSpec BT_SignMask     = 0x00300000;

const BaseTypeSpec BT_TypeError    = 0x10000000;


typedef unsigned short TypeQual;

const TypeQual TQ_None         = 0x0000;
const TypeQual TQ_Const        = 0x0001;
const TypeQual TQ_Volatile     = 0x0002;


enum StorageType
{
    ST_None  = 0,
    ST_Auto,
    ST_Extern,
    ST_Register,
    ST_Static,
    ST_Typedef
};


enum TypeKind
{
    TK_Base = 0,
    TK_TypeDef,
    TK_UserType
};


enum TypeType
{
    TT_Base,        // a simple base type, T
    TT_Pointer,     // pointer to T
    TT_Array,       // an array of T
    TT_BitField,    // a bitfield
    TT_Function     // <args> -> <result>

    /*    These are now considered TT_Base
    TT_Struct,     
    TT_Union,
    TT_Enum
    */
};


// For gcc extension __attribute__
enum GccAttribType
{
    GCC_Unsupported = 0,    // Not supported by cTool

    GCC_Aligned,
    GCC_Packed,
    GCC_CDecl,
    GCC_Mode,
    GCC_Format,
   
    GCC_Const,
    GCC_NoReturn,
    GCC_Malloc
};



class Decl;


class StructDef
{
  public:
    StructDef( bool _is_union = false );
    ~StructDef();

    bool    isUnion() const { return _isUnion; }

    StructDef*   dup0() const;
    StructDef*   dup() const;    // deep-copy

    void    print(std::ostream& out, Symbol *name, int level) const;

    void    findExpr( fnExprCallback cb );

    void    addComponent(Decl *comp);

    void    registerComponents();

    // Lookup this symbol in this struct/union and set its entry
    // if its a component of it.
    bool    lookup( Symbol* sym, Context& context ) const;

    bool            _isUnion;
    Symbol         *tag;

    int             size;          // size of the array.
    int             nComponents;
    Decl          **components;

  private:
    Decl   *lastDecl();
};


class EnumDef
{
  public:
    EnumDef();
    ~EnumDef();

    EnumDef*   dup0() const;
    EnumDef*   dup() const;    // deep-copy

    void print(std::ostream& out, Symbol *name, int level) const;
    void findExpr( fnExprCallback cb );

    void addElement( Symbol *nme, Expression *val = NULL );

    void addElement( EnumConstant* ec );

    Symbol         *tag;

    int             size;       // size of the arrays.
    int             nElements;
    Symbol        **names;
    Expression    **values;
};



class Type;
typedef Dup<Type> DupableType;

class Type : public DupableType
{
  public:
    Type(TypeType _type=TT_Base);
    virtual ~Type();

    virtual void accept(Traversal *) = 0;

    virtual int     precedence() const { return 16; }
    virtual Type*   dup0() const =0;    // deep-copy

    virtual Type*   extend(Type *extension)=0;

    // This function handles the complexity of printing a type.
    void    printType( std::ostream& out, Symbol *name,
                       bool showBase, int level ) const;

    virtual void printBase( std::ostream& out, int level ) const {}
    virtual void printBefore( std::ostream& out, Symbol *name, int level) const {}
    virtual void printAfter( std::ostream& out ) const {}

    virtual void printForm(std::ostream& out) const { out << "-[ABT]"; }

    virtual void registerComponents() {}

    virtual void findExpr( fnExprCallback cb ) {}

    virtual bool lookup( Symbol* sym, Context& context ) const { return false; }

    bool    isBaseType() const { return (type == TT_Base); }
    bool    isPointer() const { return (type == TT_Pointer); }
    bool    isFunction() const { return (type == TT_Function); }
    bool    isArray() const { return (type == TT_Array); }

    // Delete all types stored in this list.
    static void    DeleteTypeList(Type* typelist);


    TypeType        type;

    // Temporary - is moved into the declaration (Decl).
    StorageType     storage;

  private:
    Type*           link;    // For linking all type classes togather.
};


class BaseType : public Type
{
  public:
    BaseType( BaseTypeSpec = BT_NoType );
    BaseType( StructDef *sd );
    BaseType( EnumDef *ed );
    ~BaseType();

    virtual void accept(Traversal *t) { t->traverse_base(this);}

    Type* dup0() const;    // deep-copy

    Type* extend(Type *extension) { assert(0); return NULL; }

    void printBase( std::ostream& out, int level ) const;
    void printBefore( std::ostream& out, Symbol *name, int level) const;
    void printAfter( std::ostream& out ) const;

    void printForm(std::ostream& out) const;

    void registerComponents();

    bool lookup( Symbol* sym, Context& context ) const;

    BaseTypeSpec    typemask;

    TypeQual        qualifier;

    Symbol          *tag;        // tag for struct/union/enum
    Symbol          *typeName;   // typedef name for a UserType

    StructDef       *stDefn;     // optional definition of struct/union
    EnumDef         *enDefn;     // optional definition of enum 
};


class PtrType : public Type
{
  public:
    PtrType(TypeQual qual = TQ_None)
        : Type(TT_Pointer), qualifier(qual), subType(NULL){};
    ~PtrType(){};

    virtual void accept(Traversal *t) { t->traverse_ptr(this);}

    int    precedence() const { return 15; }

    Type* dup0() const;    // deep-copy

    Type* extend(Type *extension);

    void printBase( std::ostream& out, int level ) const;
    void printBefore( std::ostream& out, Symbol *name, int level) const;
    void printAfter( std::ostream& out ) const;

    void printForm(std::ostream& out) const;

    void registerComponents() { if (subType) subType->registerComponents(); }

    void findExpr( fnExprCallback cb );

    bool lookup( Symbol* sym, Context& context ) const;

    TypeQual        qualifier;
    Type           *subType;
};


class ArrayType : public Type
{
  public:
    ArrayType(Expression *s)
          : Type(TT_Array), subType(NULL), size(s) {};

    ~ArrayType();

    virtual void accept(Traversal *t) { t->traverse_array(this);}

    Type* dup0() const;    // deep-copy

    Type* extend(Type *extension);

    void printBase( std::ostream& out, int level ) const;
    void printBefore( std::ostream& out, Symbol *name, int level) const;
    void printAfter( std::ostream& out ) const;

    void printForm(std::ostream& out) const;

    void registerComponents() { if (subType) subType->registerComponents(); }

    void findExpr( fnExprCallback cb );

    bool lookup( Symbol* sym, Context& context ) const;

    Type           *subType;

    Expression     *size;
};


class BitFieldType : public Type
{
  public:
    BitFieldType(Expression * s = NULL)
          : Type(TT_BitField),size(s),subType(NULL) {};
    ~BitFieldType();

    virtual void accept(Traversal *t) { t->traverse_bit_field(this);}

    Type* dup0() const;    // deep-copy

    Type* extend(Type *extension);

    void printBase( std::ostream& out, int level ) const;
    void printBefore( std::ostream& out, Symbol *name, int level) const;
    void printAfter( std::ostream& out ) const;

    void printForm(std::ostream& out) const;

    void registerComponents() { if (subType) subType->registerComponents(); }

    void findExpr( fnExprCallback cb );

    bool lookup( Symbol* sym, Context& context ) const;

    Expression     *size;

    Type           *subType;
};


class FunctionType : public Type
{
  public:
    FunctionType(Decl *args_list = NULL);
    ~FunctionType();

    virtual void accept(Traversal *t) { t->traverse_function(this);}

    Type* dup0() const;    // deep-copy

    Type* extend(Type *extension);

    void printBase( std::ostream& out, int level ) const;
    void printBefore( std::ostream& out, Symbol *name, int level) const;
    void printAfter( std::ostream& out ) const;

    void printForm(std::ostream& out) const;

    void registerComponents() { if (subType) subType->registerComponents(); }

    void addArg(Decl *arg);
    void addArgs(Decl *args);

    void findExpr( fnExprCallback cb );

    bool lookup( Symbol* sym, Context& context ) const;

    bool            KnR_decl;    // old-style function declaration?
    int             nArgs;
    int             size;
    Decl          **args;

    Type           *subType;    // The return type
};


class GccAttrib
{
  public:
    GccAttrib( GccAttribType gccType );
    ~GccAttrib();

    GccAttrib* dup0() const;
    GccAttrib* dup() const;

    void    print( std::ostream& out ) const;

    GccAttribType    type;

    uint             value;    // For use with GCC_Aligned
    Symbol          *mode;     // For use with GCC_Mode, GCC_Format

    uint             strIdx;   // For use with GCC_Format
    uint             first;    // For use with GCC_Format
};


class Decl
{
  public:
    Decl( Symbol* sym = (Symbol*) NULL );
    Decl( Type* type );
    ~Decl();

    Type*   extend( Type* type );

    bool    isTypedef() const { return (storage == ST_Typedef); }
    bool    isStatic() const { return (storage == ST_Static); }

    void    clear();

    Decl*   dup0() const;
    Decl*   dup() const;        // deep-copy

    void    copy(const Decl& decl);    // shallow copy

    void    print(std::ostream& out, bool showBase, int level=0) const;
    void    printBase(std::ostream& out, Symbol *name,
                       bool showBase, int level) const;

    void    findExpr( fnExprCallback cb );

    bool lookup( Symbol* sym, Context& context ) const;

    StorageType     storage;

    Type            *form;    // i.e., int *x[5] 

    Symbol          *name;    // The symbol being declared.

    GccAttrib       *attrib;  // optional gcc attribute

    Expression      *initializer;

    Decl            *next;    // For linking into lists
};



typedef    std::vector<Decl*>    DeclVector;



Decl*	ReverseList( Decl* dList );



#endif  /* DECL_H */

