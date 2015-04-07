#include <iostream>
#include <string>
#include <iostream>
#include "a.hpp" 
using namespace std;

int main( int argc, char *argv[] ) {

  string a, b ;

  cin >> a ; cin >> b ;

  //check if they are null if so cancel program.                                                                                
  Edist test( a, b ) ;

  cout << "Edit distance" << test.OptDistance() << endl ;
  return 0 ;
}
