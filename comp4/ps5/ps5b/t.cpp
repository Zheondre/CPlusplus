// Copyright 2015 < Angel Zheondre Calcano>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <vector>
#include "GuitarString.hpp"
using namespace std;
int main(){ 
  int16_t ran;
  int i; double hi;
	   i = 0;
  while( i != 60){ 
    hi = (rand() % 10 - 5);
    //std::cout << hi/10 <<std::endl;
    ran = (hi/10);
    //cout << ran<< "ran"<< endl;
    cout << (int16_t)( rand() & 0xffff) << endl;
    i++;
  } 

  return 0;
} 
