// Copyright 2015 <Angel Zheondre Calcano>
// PS5b
#ifndef _GuitarString_
#define _GuitarString_
#include <math.h>
#include <limits.h>
#include <SFML/System.hpp>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "RingBuffer.hpp"

class GuitarString{
  RingBuffer *_j; int _size, _ticCount;

 public:
  explicit GuitarString(double freq) {
    if (freq < 1)
      throw std::runtime_error("Constructor frequency must be > than 0");
    _size = ceil((48400/freq)); //48400
    _j = new RingBuffer(_size);
    _ticCount = 0;
     for (int i = 0 ; i < _size; i++)
       _j->enqueue(0);
  }
  explicit GuitarString(std::vector< sf::Int16 > j) {
    _size = j.size();
    if (_size < 1)
      throw std::runtime_error("Empty Vector, Size must be > than 0 ");
    _j = new RingBuffer(_size);
    _ticCount = 0;
    for (int i = 0; i < _size; i++) {
      _j->enqueue((int16_t)j[i]);
    }
  }
  ~GuitarString() {
    delete _j; // delete *_j made it fail the test.
  }
  void pluck();
  int time();
  void tic();
  sf::Int16 sample();
};
#endif
