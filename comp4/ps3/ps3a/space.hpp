#ifndef _space 
#define _space 

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream> 
#include <string> 

using namespace std; 
using namespace sf ; 
class body : public Drawable {

  double xpos, ypos, xvel, yvel, mass, radfromsun ; 
  double unir, cenx, ceny, winsiz ;
  string fname ;
  Sprite sprite ;
  Texture texture ; 
  //double Grav = 6.67e-11 ; //give weird error 

public : 
  body( double spacer, double winsize );  
  body():xpos(0), ypos(0),xvel(0), yvel(0), mass(0), fname("") {} ;  
  //body double x, double y, double z, double a, double b, string c ) : xpos(x), ypos(y), xvel(z), yvel(a), mass(b), fname(c) {} ;     
  
  void center( double x ) ;   
 
  double getposx(); 
  double getposy();
   
  double getxvel() ; 
  double getyvel() ; 
 
  double getmass() ; 
  double getrad() ; 
  string getfname() ; 
  
  void newpos() ;
  void setpos() ; 

  void setImage(); 

  friend istream &operator >> (istream &input, body *S) { 
    input >> S->xpos >> S->ypos >> S->xvel >> S->yvel >> S->mass >> S->fname ;
    S->setpos() ; 
    S->setImage(); 
    return input ; 
  } 
private:
  virtual void draw( RenderTarget& target, RenderStates states) const{ 

    target.draw( sprite, states) ; 
  }  ; 
} ;  

#endif
