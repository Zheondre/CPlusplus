// Angel Zheondre Calcano Ps3a N-Body Simulation
#include <iostream> 
#include <math.h> 
#include "space.hpp" 

using namespace sf ; 

body::body(  double ss, double ws ) {
  ceny = cenx = ss/(1e+9) + 200;
  winsiz = ws; 
} 
void body::center( double x) { 
  ceny = cenx = x/(1e+9) + 200; 
}  
void body::setpos(){     
  radfromsun = xpos/(1e+9); 
  xpos = radfromsun + cenx; 
  ypos = ypos/(1e+9) + ceny;
  //grav(radfromsun) ; 
} 
double body::getposx(){ return xpos; } 
double body::getposy(){ return ypos; } 
double body::getxvel(){ return xvel; }
double body::getyvel(){ return yvel; }
double body::getmass(){ return mass; } 
double body::getrad(){ return radfromsun; } 
string body::getfname(){ return fname; } 
void body::setImage(){ 
  texture.loadFromFile(fname) ; 
  sprite.setTexture(texture) ; 
  sprite.setPosition(xpos, ypos ) ; 
} 
void body::newpos(){ 
  if( xpos > cenx && ypos <= ceny ) { 
    xpos = xpos - xvel; 
    ypos = ypos - yvel ; 
  }
  if( xpos < cenx && ypos <= ceny ) { 
    xpos = xpos - xvel; 
    ypos = ypos + yvel ; 
  }
  if( xpos >= cenx && ypos < ceny ) { 
    xpos = xpos + xvel; 
    ypos = ypos + yvel ; 
  }
  if( xpos >= cenx && ypos > ceny ) { 
    xpos = xpos + xvel; 
    ypos = ypos - yvel ; 
  }
} 
/*int body::grav(double r){ //implement later 
 //need grav pull to make circular motion
  if( r > 1 ) return -1 ; 
  xvel = (Grav*mass*m2)/(r * r) ; 
  return 0 ; 
} 
*/
 