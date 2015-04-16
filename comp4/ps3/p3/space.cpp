#include <iostream> 
#include <math.h> 
#include "space.hpp" 
#include <vector> 
using namespace sf ; 

body::body(double ss, double ws) { 
  ceny = cenx = ss/(1e+9) + 200;
  winsiz = ws;
}
void body::center(double x) { 
  ceny = cenx = x/(1e+9) + 200;
}  
void body::setpos(){
  xpos = radfromsun + cenx;
  ypos = ypos/(1e+9) + ceny;
} 
void body::setNotScaledPos(double x, double y) { 
  nsx = x;
  nsy = y;
} 
void body::setpos(double x, double y) {
  xpos = x; 
  ypos = y;
  sprite.setPosition(xpos, ypos) ;
} 
void body::setfnx( double val ){ fnx = val ; } 
void body::setfny( double val ){ fny = val ; } 

double body::gspx(){return xpos ; } 
double body::gspy(){ return ypos ; } 
double body::getfnx(){ return fnx ; } 
double body::getfny(){ return fny ; }  
double body::getposx(){ return xpos*(1e+9); }  //return the unscaled x & y 
double body::getposy(){ return ypos*(1e+9); }  
double body::getnsx(){ return nsx; } 
double body::getnsy(){ return nsy; } 
void body::setV(double x, double y ){ xvel = x; yvel = y; }
double body::getxvel(){ return xvel; }
double body::getyvel(){ return yvel; }
double body::getmass(){ return mass; }
void body::setrSun(){ radfromsun = xpos/(1e+9) ; } 
double body::getrad(){ return radfromsun ; } 
string body::getfname(){ return fname; } 
void body::setImage(){ 
  texture.loadFromFile(fname) ; 
  sprite.setTexture(texture) ; 
  sprite.setPosition(xpos, ypos) ; // needs to be called every time position is changed.  
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

double body::grav(double r, double m2, double m1){
  
  if(r < 1) return -1; 
  return ((6.67e-11)*m1*m2)/(r*r);  
}

