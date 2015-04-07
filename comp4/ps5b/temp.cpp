#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define SAMPLES_PER_SEC 44100

vector<sf::Int16> makeSamplesFromString(GuitarString gs) {
  std::vector<sf::Int16> samples;
  gs.pluck();
  int duration = 8; // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }
  return samples;
}

int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
  sf::Event event;
double freq;
int i;  
  vector< vector< sf::Int16 >  > ado_smpl_strm;
  vector< sf::SoundBuffer > ado_smpl;
  vector< sf::Sounds > SndBffer;
  vector< sf::Int16 > samples; 
  string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

  for (i = 0; i < 37; i++) {
    freq = 440*pow(2, (i-24)/12.0);
    samples = makeSamplesFromString(gs1);
    GuitarString gs1(freq);
    ado_smpl_strm.push_back(samples);
    sf::SoundBuffer buf1;
    sf::Sound sound1;
    if (!buf1.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
      throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
    sound1.setBuffer(buf1);
    ado_smpl.push_back(buf1);
    SndBffer.push_back(sound1);
  }
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::Text.Entered:
	index::keyboard.find(event.txt.unicode);
	if(index != std::string::npos)
	  SndBffer[index].play();
	break;
      default:
	break;
      }
    }
    window.clear();
    window.display();
  }
  return 0;
}