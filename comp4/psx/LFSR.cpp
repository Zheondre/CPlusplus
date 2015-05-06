// Copyright 2015 <Angel Z'heondre Calcano>
#include <iostream>
#include <string>
#include "LFSR.hpp"

int LFSR::stTodig(std::string &a) {
  char b; int d1, d2;
  b = a[0];
  if (b == '1') d1 = 1;
  else
    d1 = 0;
  b = a[a.length() - t];
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
  int i, num, total;
  total = 0;
  for (i = 0; i < k; i++) step();
  for (i = 0; i < k; i++) {
    if (i == 0) num = 1;
    else
      num = 2 * num;
    if (unit[k-i] == '1') total = total + num;
  }
  return total;
}

std::string LFSR::prtln(const LFSR &temp, int bit) {
  std::cout << temp << " " << bit;
  return "";
}



