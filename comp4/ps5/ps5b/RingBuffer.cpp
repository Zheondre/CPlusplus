// Copyright 2015 <Angel Z'heondre Calcano>
// PS5b
#include <stdint.h>
#include <cstdlib>
#include <stdint.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include "RingBuffer.hpp"

int RingBuffer::size() { return _currentcapacity; }

bool RingBuffer::isEmpty() { return _buffer.empty(); }

bool RingBuffer::isFull() {
  if (_buffer.size() == (unsigned)_size)
    return true;
  if (_buffer.size() >(unsigned)_size)
    return false;
  else
    return false;
}

void RingBuffer::enqueue(int16_t x) {
  if (_currentcapacity == _size) {
    throw
      std::runtime_error("Can't enqueue on a full ring");
  }
  if( _currentcapacity > _size) { 
    throw
      std::runtime_error("Can't enqueue on a full ring");
  } 
  _buffer[_last] = x;
  _last++;
  _currentcapacity++;
  if (_last == _size)
    _last = 0;
}

int16_t RingBuffer::dequeue() {
  if (_currentcapacity <= 0)
    throw
      std::runtime_error(" Can't dequeue from empty ring");
  double _hold;
  _hold = _buffer[_first];
  _first++;
  _currentcapacity--;
  if (_first == _last) _first = _last = 0;
  if (_first == _size) _first = 0;
  return _hold;
}

int16_t RingBuffer::peek() {
  if (_currentcapacity == 0)
    throw
      std::runtime_error("Can't peek on an empty ring");
  if (_buffer.empty())
    throw
      std::runtime_error("Can't peek on an empty vector array");
  return _buffer[_first];
}
