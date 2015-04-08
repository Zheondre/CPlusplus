// Copyright 2015 <Angel Zheondre Calcano>
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
  explicit GuitarString(int freq) {
    // use resize ?
    if (freq < 1)
      throw std::invalid_argument("Constructor frequency must be > than 0");
    _size = ceil((44100/freq));
    _j = new RingBuffer(_size);
    _ticCount = 0;
     for (int i = 0 ; i < _size; i++)
       _j->enqueue(0);
  }
  explicit GuitarString(std::vector< sf::Int16 > j) {
    _size = j.size();
    if (_size < 1)
      throw std::invalid_argument("Empty Vector, Size must be > than 0 ");
    std::cout << _size << std::endl;
    _j = new RingBuffer(_size);
     // works
    _ticCount = 0;
    for (int i = 0; i < _size; i++) {
      _j->enqueue((int16_t)j[i]);
      std::cout << i << std::endl;
    }
    // works but segfaults afterwards.
  }
  ~GuitarString() {
    // make sure to free bytes for the pointer.
    delete[] _j;
  }
  void pluck();
  int time();
  void tic();
  sf::Int16 sample();
};
#endif
