// Copyright 2015 <Angel Z'heondre Calcano>
// PS5b
#ifndef _RingBuffer_
#define _RingBuffer_
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class RingBuffer{
  int _size, _first, _last, _currentcapacity;
  std::vector< double > _buffer;
 public:
  explicit RingBuffer(int x): _size(x) {
    if (x < 1)
      throw std::runtime_error("Constructor capacity must be > than 0");
    _first = _last = _currentcapacity = 0;
    for (int i = 0 ; i < x; i++)
      _buffer.push_back(100);
   }
  void RB();
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
};
#endif
