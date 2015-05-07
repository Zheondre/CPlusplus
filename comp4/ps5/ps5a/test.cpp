// Copyright 2015 <Angel Z'heondre Calcano>
// PS5a
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RingBufferconsrtuct) {
  BOOST_REQUIRE_NO_THROW(RingBuffer(100));
  BOOST_CHECK_THROW(RingBuffer(0), std::exception);
  BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(Enqueue_Dequeue_peek) {
  RingBuffer a(3);
  a.enqueue(3);
  a.enqueue(2);
  a.enqueue(1);
  BOOST_REQUIRE(a.peek() == 3);
  BOOST_REQUIRE(a.dequeue() == 3);
  BOOST_REQUIRE(a.dequeue() == 2);
  BOOST_REQUIRE(a.dequeue() == 1);
  BOOST_REQUIRE_THROW(a.dequeue(), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(EnqueueFullbuffer) {
  RingBuffer b(3);
  b.enqueue(5);
  b.enqueue(9);
  b.enqueue(7);
  BOOST_REQUIRE_THROW(b.enqueue(9), std::runtime_error);
}
BOOST_AUTO_TEST_CASE(peekonemptybuffer) {
  RingBuffer c(1);
  c.enqueue(5);
  BOOST_REQUIRE(c.dequeue() == 5);
  BOOST_CHECK_THROW(c.peek(), std::runtime_error);
}
