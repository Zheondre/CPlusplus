// Copyright 2015 <Angel Z'heondre Calcano>
// PS2a
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include "LFSR.hpp"

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {
  LFSR l("00111", 2);

  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);  // boost finds an error here
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  LFSR l2("00111", 2); 
  BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(sevenBitsTapAtfive) {
  LFSR s("1101010", 5);
  BOOST_REQUIRE(s.generate(4) != 102);
}

BOOST_AUTO_TEST_CASE(sevenBitsTapAtfivea) {
  LFSR s("1101010", 5);
  BOOST_REQUIRE(s.step() == 0);
  BOOST_REQUIRE(s.step() == 1);
  BOOST_REQUIRE(s.step() == 1);
  BOOST_REQUIRE(s.step() == 1);
  BOOST_REQUIRE(s.step() == 1);
  std::stringstream sng;
  sng << s;
  BOOST_CHECK_EQUAL(sng.str(), "1001111");
}

BOOST_AUTO_TEST_CASE(elevenbitsatseven) {
  LFSR l("11101000111", 7);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  LFSR l2("11101000111", 7);
}
