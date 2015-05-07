// Copyright 2015 <Angel Z'heondre Calcano>
// PS2b
/*#include <iostream>
#include <string>
#include "LFSR.hpp"
using namespace std ;
int main( int argc, char *argv[] ) { 

  int amount ; 
  LFSR *test  = new LFSR( "1101", 2 ) ; 

  //amount = test->step() ; 
  //cout << *test << endl ; 
  //cout << amount << endl ; 

  amount = test->generate(3) ; 
  cout << amount << endl ; 
  cout << *test << endl  ; 
  delete test ; 
} */

// pixels.cpp: 
// using SFML to load a file, manipulate its pixels, write it to disk
// Fred Martin, fredm@cs.uml.edu, Sun Mar  2 15:57:08 2014

// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LFSR.hpp"
int main(int argc, char *argv[] ) {
  int n = atoi(argv[4]) ;  
  LFSR *pow = new LFSR( argv[3], n  ) ; 
  sf::Image image;
  sf::Image image2; 
  if (!image.loadFromFile(argv[1]))  return -1;
  if (!image2.loadFromFile(argv[1])) return -1 ; 
  // p is a pixel
  sf::Color p;
  sf::Vector2u size = image.getSize();

  for (int x=0; (unsigned) x< size.x; x++) {
    for (int y= 0;(unsigned) y< size.y; y++) {
      p = image.getPixel(x, y);
      p.r =  p.r ^ pow->generate(8) ;
      p.g =  p.g ^ pow->generate(8) ;
      p.b =  p.b ^ pow->generate(8);
      image.setPixel(x, y, p);
    }
  }

  sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Angel C. LFSR");
  sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Angel C. LFSR");
  sf::Texture texture;
  sf::Texture t2; 
  
  texture.loadFromImage(image);
  t2.loadFromImage(image2) ;

  sf::Sprite sprite;
  sf::Sprite s2 ; 

  sprite.setTexture(texture);
  s2.setTexture(t2 ) ; 

  while (window.isOpen() && window2.isOpen()){
      sf::Event event;
      while (window.pollEvent(event)) {
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
	while (window2.pollEvent(event)) {
	  if (event.type == sf::Event::Closed)
	    window.close();
	}	
      window.clear();
      window.draw(sprite);
      window.display();
      window2.clear();
      window2.draw(s2);
      window2.display();
    }
  if (!image.saveToFile(argv[2]))
    return -1;
delete pow ;  
  return 0;
}
