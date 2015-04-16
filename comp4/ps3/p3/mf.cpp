// Copyright 2015 <Zheondre Calcano> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include "space.hpp" 
#include <math.h> 

using namespace std; 

double pl( vector< body* > &space, double ot, double deltat) { 
  int i, j;
  double x, y, F, Fx, Fy, ax, ay, Vx, Vy, r;
  x = y = F = Fx = Fy = ax = ay = Vx = Vy = r = 0;

  for( i = 0 ; (unsigned)i < space.size() ; i++ ) {

    space[i]->setfnx(0.0);
    space[i]->setfny(0.0);
    for( j = 0 ; (unsigned)j < space.size() ; j++ ) {

      if( i == j ) continue ;   
      else{ 
	 x = space[j]->getposx() - space[i]->getposx() ; 
	 y = space[j]->getposy() - space[i]->getposy() ;
	
	 r = sqrt( x * x + y * y ) ; 
	 if( r < 1 ) return -1 ; 
	 F = space[i]->grav( r, space[j]->getmass(), space[i]->getmass() ) ; 
	 Fx = (F*x)/r ; Fy = (F*y)/r ; 

	 space[i]->setfnx(space[i]->getfnx() + Fx) ;
	 space[i]->setfny(space[i]->getfny() + Fy) ;  
      }
    }
  }

  for (i = 0; (unsigned)i < space.size(); i++) {

    if( space[i]->getmass() < 1 ) return -1; // return error message throw exeception
    ax = (space[i]->getfnx() / space[i]->getmass()); 
    ay = (space[i]->getfny() / space[i]->getmass());

    Vx = space[i]->getxvel() + deltat*ax; 
    Vy = space[i]->getyvel() + deltat*ay;
    space[i]->setV( Vx, Vy );
    space[i]->setNotScaledPos(space[i]->getposx()+deltat*Vx,
			      space[i]->getposy() + deltat*Vy);     
    space[i]->setpos(space[i]->getnsx()/(1e+9), space[i]->getnsy()/(1e+9));

  }
  return deltat + ot ; 
} 
