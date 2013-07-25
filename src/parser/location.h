#ifndef CT_LOCATION_H
#define CT_LOCATION_H

#include <string>

class Location
{
 public:
  const int line, column;
  const std::string file;

  Location(int l, int c, const std::string& f):line(l),column(c),file(f) {}
  ~Location() {}

  void printLocation(std::ostream& p) const;
};

extern  Location NoLocation;

#endif

