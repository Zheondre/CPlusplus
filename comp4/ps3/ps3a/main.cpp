// Angel Zheondre Calcano 

#include <iostream> 
#include <string> 
#include <vector> 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include "space.hpp" 

using namespace std;
using namespace sf;

int main( int argc, char *argv[] ) { 
  
  int n, i, ws ; double spcrdi; vector< body* > space ; 
  cin >> n ; cin >> spcrdi ; ws = 900 ; 

  for( i = 0 ; i < n ; i++ ) { 
    body *planet= new body( spcrdi, ws ) ; 
    cin >> planet; 
    space.push_back( planet )  ;   
   }

  RenderWindow window( VideoMode( ws, ws), "ps3 AC" ) ; 
 
  while (window.isOpen()){
 
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    window.clear();
    for( i = 0 ; i < n ; i++ ) window.draw(*space[i]) ; 
    window.display();
  }
  return 0 ; 
} 
