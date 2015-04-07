/* Angel Zheondre Calcano */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include "func.hpp"

using namespace sf ;
using namespace std ;

int main(int argc, char* argv[]) {

  if( argc < 3 ) {
    cout << "sierpinski [recursion-depth][side-length]" << endl ;
    return -1 ;
  }
  int depth = atoi(argv[1]) ;
  int  w = atoi(argv[2]) ;

  RenderWindow window(VideoMode(w,w), "Angel Zheondre Calcano ID# 01141688" ) ;
  window.setFramerateLimit(1) ;

  CircleShape circle ; 
  circle.setRadius(w/2) ; 
  circle.setPosition(0, 0) ; 
  circle.setFillColor(Color::Yellow);
 
 
  while( window.isOpen()){

    Event event ;
    while( window.pollEvent(event)) {
      if(event.type == Event::Closed )
        window.close() ;
    }
   
    window.clear(Color::Blue) ;
    window.draw(circle);
    Sierpinski((.5)*(w/3), depth, w/2, w/2, window) ;
    //Sierpinski( 250, 5, 250, 433, window) ;                                                                              
    window.display() ;
  }

  return 0 ;
}
