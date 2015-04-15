/*
 * MarkovModel.hpp
 * Copyright Fred Martin, fredm@cs.uml.edu
 * Tue Apr  7 21:54:53 2015
 */

#include <string>
#include <map>
#include <vector>

class MarkovModel {
int _order;
  map <string, int> _kgrams;  // must #include <map>
  string _alphabet;
  vector< string > s;
  
 public:
  MarkovModel(string text, int k);
  ~MarkovModel();
  int order();
  int freq(string kgram);
  int freq(string kgram, char c);
  char randk(string kgram);
  string gen(string kgram, int T);

  friend std::ostream& operator<< (std::ostream &out, MarkovModel &mm);
 
};
