// Copyright 2015 <Angel Calcano>
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
#define SAMPLES_PER_SEC 48400

std::vector< sf::Int16 > makeSamplesFromString(GuitarString *gs) {
  std::vector< sf::Int16 > samples;
  gs->pluck();
  int duration = 8;
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs->tic();
    samples.push_back(gs->sample());
  }
  return samples;
}
int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
  sf::Event event;
  double freq;
  int i;
  std::vector< std::vector< int16_t >  > ado_smpl_strm;
  std::vector< sf::SoundBuffer > ado_smpl;
  std::vector< sf::Sound > SndBffer;
  std::vector< sf::Int16 > samples;
  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  ado_smpl_strm.resize(37);//ALWAYS USE resize 
  ado_smpl.resize(37);
  SndBffer.resize(37);
  for (i = 0; i < 37; i++) {
    freq = 220*pow(2, (i-24)/12.0);//changed from 440 to 220 
    //GuitarString gs1(freq); making shallow copy
    GuitarString *gs1 = new GuitarString(freq);
    samples = makeSamplesFromString(gs1);
    ado_smpl[i].loadFromSamples( &samples[0], samples.size(), 2, SAMPLES_PER_SEC); // y 
    SndBffer[i].setBuffer(ado_smpl[i]);
    //sf::SoundBuffer buf1;
    //sf::Sound sound1;
    //if (!buf1.loadFromSamples(&ado_smpl_strm[i][0], ado_smpl_strm[i].size(), 2, SAMPLES_PER_SEC))
    //throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
    //sound1.setBuffer(buf1);
    //ado_smpl.push_back(buf1);
    //sound1.setBuffer(ado_smpl[i]);
    //SndBffer.push_back(sound1);
  }
  int index;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::TextEntered:
        index = keyboard.find(event.text.unicode);
        if ((unsigned)index != std::string::npos){
           SndBffer[index].play();
	}
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
