#ifndef _space 
#define _space 

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 
using namespace sf ;
 
class body : public Drawable {
  double nsx, nsy; 
  double xpos, ypos, xvel, yvel, mass, radfromsun;
  double unir, cenx, ceny, winsiz, fnx, fny;
  string fname;
  Sprite sprite;
  Texture texture;
 
public :
  body(double spacer, double winsize);
  body():xpos(0), ypos(0), xvel(0), yvel(0), mass(0), fname("") {};
   
  void center(double); 
  void setrSun();
  void setfnx(double);
  void setfny(double);
  void setnsx(double);
  void setnsy(double);
  void setNotScaledPos(double, double); 
  void setV(double, double);
 
  double grav(double, double, double);
  double getfnx();
  double getfny();

  double gspx(); 
  double gspy(); 

  double getnsx();
  double getnsy();
  double getposx();
  double getposy();
   
  double getxvel();
  double getyvel();
 
  double getmass();
  double getrad();
  string getfname();
  
  void newpos();
  void setpos();
  void setpos(double, double); 
  void setImage(); 

  friend istream &operator >> (istream &input, body *S) { 
    input >> S->xpos >> S->ypos >> S->xvel >> S->yvel >> S->mass >> S->fname;
    S->setrSun();
    S->setpos();
    S->setImage();
    return input;
  }
private:
  virtual void draw(RenderTarget& target, RenderStates states) const{
    target.draw(sprite, states);
  }; 
};  

double pl(vector< body* > &x, double y, double z); 
#endif
