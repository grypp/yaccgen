
#include <iostream>

#include "location.h"

Location NoLocation(0,0,"");

void
Location::printLocation(std::ostream& p) const
{
//     p << '"' << file << '"';
    p << ", " << line << ", " << column;
}

