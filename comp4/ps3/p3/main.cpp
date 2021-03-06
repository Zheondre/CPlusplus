#include <iostream> 
#include <string> 
#include <vector> 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include "space.hpp" 

using namespace std ; 
using namespace sf ; 

int main( int argc, char *argv[] ) { 

  int n, i, ws ; double spcrdi, result; vector< body* > space ; 
  
  int et = atoi(argv[1]) ;   int ct = atoi(argv[2]) ;
 
  cin >> n ; cin >> spcrdi ; ws = 900 ; 

  for( i = 0 ; i < n ; i++ ) { 
    body *planet= new body( spcrdi, ws ) ; 
    cin >> planet; 
    space.push_back( planet )  ;   
   }
  result = 0 ; 
  RenderWindow window( VideoMode( ws, ws), "ps3 AC" ) ; 
  int test_num = 0 ; 

  while (window.isOpen()){
    test_num++ ; 
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    window.clear();
    for( i = 0 ; i < n ; i++ ) window.draw(*space[i]) ; 
    window.display();
    result = pl(space, result , ct ) ;
    if( test_num < 1000 ) { 
      cout << test_num<< endl ;
      // cout << space[0]->getposx() << " no scale"<< endl ;
      // cout << space[0]->gspx() << " Scaled x"<< endl ; 
      // cout << space[0]->gspy() << " Scaled y"<< endl ; 
      // cout << result << endl ; 
    }
    if( result == -1 ) return 0 ; 
    if( result > et ) return 0 ; 
  }
 
  return 0 ; 
} 
