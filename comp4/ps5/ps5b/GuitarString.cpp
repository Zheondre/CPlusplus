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

void GuitarString::pluck() {
  if (_j->isEmpty())
    throw
      std::runtime_error("Can't pluck, empty buffer.");
  int i; int16_t ran;
  for (i = 0 ; i < _size; i++)
    _j->dequeue(); // all 0s
  for (i = 0 ; i < _size; i++) {
    ran = (int16_t)(rand() & 0xffff);
    _j->enqueue(ran);
  }
  //std::cout << ran << " pluck" <<std::endl; //w
}
void GuitarString::tic() {
  if (_j->isEmpty())
    throw
      std::runtime_error("Can't tic, empty buffer.");
  double num1, num2, result;
  int i;
  num1 = _j->dequeue();
  num2 = _j->peek();
  result = .996*.5*(num1 + num2);
  //std::cout<< result << std::endl;
  for (i = 0 ; i < _size - 1; i++)// this function seems weird. 
       _j->enqueue(_j->dequeue());
  _j->enqueue(result);
  //std::cout<< _j->peek();
  _ticCount++;
}
int16_t GuitarString::sample() {
if (_j->isEmpty())
    throw
      std::runtime_error("Can't peek, empty buffer.");
return _j->peek();
}
int GuitarString::time() {
  return _ticCount;
}
