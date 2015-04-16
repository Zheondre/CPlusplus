#ifndef _MarkovModel_
#define _MarkovModel_
//  Copyright 2015 Z'heondre Calcano
/*
 * MarkovModel.hpp
 * Copyright Fred Martin, fredm@cs.uml.edu
 * Tue Apr  7 21:54:53 2015
 */
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class MarkovModel {
  int _order;
  std::map< std::string, int> _kgrams;
  std::string _alphabet;
  std::vector< std::string > _s;
  
 public:
  MarkovModel(std::string text, int k);
  ~MarkovModel(){
    _kgrams.clear();
  };
  int order();
  int freq(std::string kgram);
  int freq(std::string kgram, char c);
  char randk(std::string kgram);
  std::string gen(std::string kgram, int T);
  void sets();
  void findAmount(std::string x);
  void printmap(std::ostream &out);
  friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm){

    out << mm._order << "\n" << mm._alphabet << "\n"; 
    mm.printmap(out); 
    return out;
  }
};

#endif 
