
#ifndef CT_DUP_H
#define CT_DUP_H

template <class R> class Dup {
  public:
    // Virtual deep-copy method; 
    // so it can't be applied to a NULL pointer. 
    virtual R * dup0 (void) const = 0 ;
    
    // Nonvirtual deep-copy (calling the virtual one)
    // such that it can be applied to a NULL pointer.
    R * dup (void) const { return this ? dup0() : (R *) NULL ; } ;
} ;

#endif
