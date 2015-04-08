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
  int i, sc; int16_t ran;
  sc = _size;
  for (i = 0 ; i < sc; i++)
    _j->dequeue();
  for (i = 0 ; i < sc; i++) {
    ran = (int16_t)(fmod(rand(), .10) - .5); //NOLINT
    _j->enqueue(ran);
  }
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
  for (i = 0 ; i < _size - 1; i++)
    _j->enqueue(_j->dequeue());
  _j->enqueue(result);
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
