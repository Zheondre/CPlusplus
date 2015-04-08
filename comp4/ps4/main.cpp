#include <SFML/System.hpp> 
#include <string>
#include <iostream>
#include "a.hpp"
 
using namespace std;

int main( int argc, char *argv[] ) {
  int count ; 
  sf::Clock clock ; 
  sf::Time t ; 

  string a, b ;

  cin >> a ; cin >> b ;

  //check if they are null if so cancel program.                                                                                
  Edist test( a, b ) ;


  count = test.OptDistance() ; 
  cout << "Edit distance " << count << endl ;
  
  test.Alignment( 0, 0 ) ; 

  t = clock.getElapsedTime() ; 

  cout << "Execution time is " << t.asSeconds() << " seconds \n" ; 
  cout << count << endl ; 
  return 0 ;
}
