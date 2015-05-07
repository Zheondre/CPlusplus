// Copyright 2015 <Angel Z'heondre Calcano>
// PS2a
#include <iostream>
#include <string>
#include <vector>
#include "LFSR.hpp"

using namespace std;

int LFSR::stTodig(std::string &a) {
  char b; int d1, d2;
  b = a[0];
  if (b == '1') d1 = 1;
  else
    d1 = 0;
  b = a[a.length() - t - 1];
  if (b == '1') d2 = 1;
  else
    d2 = 0;
  return (d1 ^ d2);
}
int LFSR::step() {
  int bit; char c; char digits[3] = { '0', '1', '\0' };
  bit = stTodig(unit);
  c = digits[bit];
  unit.erase(unit.begin());
  unit.push_back(c);
  return bit;
}
int LFSR::generate(int k) {
  int i, num, total,count;
  vector< int > reg;
  reg.resize(k);
  total = count =0;
  num = 1;
  for(i = 0; i < k; i++) {
    reg[i] = step();
  }
  for ( i = k - 1; -1 < i; i--) { 
    if( i != k - 1 ) 
      num = num * 2;
    if( reg[i] == 1){ 
      total += num;
    };
  }
  return total;
}
std::string LFSR::prtln(const LFSR &temp, int bit) {
  std::cout << temp << " " << bit;
  return "";
}



