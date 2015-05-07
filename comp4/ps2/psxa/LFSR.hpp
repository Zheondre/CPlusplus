// Copyright 2015 <Angel Z'heondre Calcano>
// PS2a

#ifndef _LFSR_
#define _LFSR_
#include <iostream>
#include <string>

class LFSR{
 protected:
  std::string unit; int t, bit;
 public :
  LFSR(std::string seed, int tap) : unit(seed), t(tap) {}
  int step();
  int generate(int k);
  int stTodig(std::string &a);
  friend std::ostream& operator<<(std::ostream &out , const LFSR& rhs) {
    out << rhs.unit;
    return out;
  }
  std::string prtln(const LFSR &t, int b);
};

#endif
