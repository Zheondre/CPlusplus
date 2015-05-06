#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <math.h>
#include <iostream>
#include "func.hpp"

using namespace sf ;
using namespace std ;

int Sierpinski( double side, double depth, double p2x, double p2y, sf::RenderWindow& a ) {
  //reminder side = side/3
  if(depth == 0) return 0 ;

  double p0y, p0x, p1y, p1x, p3y, p3x;
  
  double s = .866 ; 
  double c = .5 ; 

  //p0's values, left circ                         
  p0y = p2y - side*2*s ;
  p0x = p2x - side*2*c ;

  //p1's values, right circ pt                        
  p1y = p2y  ;
  p1x = p2x + side*2 ;
 
  //buttom circle 
  p3y = p2y + side*2*s ;  //side*2 - side*(1/3)  ; 
  p3x = p2x - side*2*c ; 
 
  CircleShape circle ;
  circle.setRadius(side) ;
  circle.setOrigin(side, side) ; 
  circle.setPosition( (float)p2x, (float)p2y) ;
  circle.setFillColor(Color::Black);
  a.draw(circle);
  
  CircleShape cb ;
  cb.setRadius(side) ;
  cb.setOrigin(side,side) ;
  cb.setPosition((float)p0x,(float)p0y) ;
  cb.setFillColor(Color::Green);
  cb.setOutlineThickness(1);
  cb.setOutlineColor(sf::Color(250, 255, 255));
  a.draw(cb);
  
  CircleShape cc ;
  cc.setRadius(side) ;
  cc.setOrigin(side,side) ;
  cc.setPosition(p1x, p1y) ;
  cc.setFillColor(Color::Blue);
  cc.setOutlineThickness(1);
  cc.setOutlineColor(sf::Color(250, 255, 255));
  a.draw(cc);

  CircleShape cd ;
  cd.setRadius(side) ;
  cd.setOrigin(side,side) ;
  cd.setPosition(p3x, p3y) ;
  cd.setFillColor(Color::Red);
  cd.setOutlineThickness(1);
  cd.setOutlineColor(sf::Color(250, 255, 255));
  a.draw(cd);
  //p2's val, bottum circ pt 

  /*    if( depth == 1 ) {                                           
      cout << "trval test " << endl ;                                
      cout << p0x << " "<< p0y << endl ;                             
      cout << p1x << " "<< p1y << endl ;                             
      cout << p2x << " "<< p2y << endl ;                             
      cout << side  << endl ; 
    } 
  */

  //Draw picture of middle tri                                                      
  ConvexShape T ;
  T.setPointCount(3) ;
  T.setPoint(0, Vector2f(p2x + side,p2y));
  T.setPoint(1, Vector2f(p2x - side*c,p2y - side*s));
  T.setPoint(2, Vector2f(p2x - side*c,p2y + side*s));
  T.setPosition(0,0);
  T.setFillColor(Color::Cyan);
  a.draw(T) ;

  Sierpinski( side/3 , depth - 1, p0x, p0y, a ) ;
  Sierpinski( side/3 , depth - 1, p1x, p1y, a ) ;
  Sierpinski( side/3 , depth - 1, p3x, p3y, a ) ;
  
  return 0 ; 

}
