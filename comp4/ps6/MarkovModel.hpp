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
  map < string, int > _kgrams;  // must #include <map>
  string _alphabet;
  vector< string > _s;
  
 public:
  MarkovModel(string text, int k);
  ~MarkovModel();
  int order();
  int freq(string kgram);
  int freq(string kgram, char c);
  char randk(string kgram);
  string gen(string kgram, int T);

  friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm){

    out << MarkovModel._order << "\n" << MarkovModel._alphabet << "\n"; 

    for(map< string,int>::iterator it = _kgrams.begin(); it != _kgrams.end(); ++it)
      out << it->first << " "<< it->second << "\n" ;
};

#endif 
