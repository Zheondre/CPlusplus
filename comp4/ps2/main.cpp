#include <iostream>
#include <string>
#include "LFSR.hpp"

using namespace std ;

int main( int argc, char *argv[] ) { 

  int amount ; 
  LFSR test( "1101", 2 ) ; 

  amount = test.step() ; 
  cout << amount << endl; 
  cout << test << endl  ;  

} 
