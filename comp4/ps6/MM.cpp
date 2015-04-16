//  Copyright 2015 Z'heondre Calcano 
 
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "MarkovModel.hpp"
#include <map>

string MarkovModel::gen(string kgram, int T) {
  if(kgram.size() != _order)
    throw
      std::runtime_error(" Kgram is not of length  k");
  if(kgram.size() > T)
    throw
      std::runtime_error(" T s less than K");
  int i;
  string tempst = kgram;
  for(i = 0; i < T; i++)
    tempst.append(randk(kgram));
  return tempst;
}

int MarkovModel::freq(string kgram) {
  if(kgram.size() != _order)
    throw
      std::runtime_error(" Kgram is not of length  k");
  return _kgram[kgram];
}

int freq(string kgram, char c){
  if(kgram.size() != _order)
    throw
      std::runtime_error(" Kgram is not of length  k");
  //if k == 0 return # of times c appears
  string kplus1; 
  kplus1 = kgram; 
  kgram.push_back(c);
  return _kgram[kgram];
}

char MarkovModel::randk(string kgram){
  if(kgram.size() != _order)
    throw
      std::runtime_error(" Kgram is not of length  k");

  if (_kgrams.find(kgram) == _kgrams.end())
    throw
      std::runtime_error(" Kgram doesn't exist in map");

  string check; vector< char > pbvc;
  int amount, i, totalfreq, j, randpos;
  totalfreq = amount = 0;
  for(map< string,int>::iterator it = _kgrams.begin(); it != _kgrams.end(); ++it) {    
    if (it->first == kgram) {
      for (i = 0; i < s.size(); i++) {
	check = kgram + _s[i];
	amount = _kgram[check];
	totalfreq += amount;
	for (j = 0; j < amount; j++)
	  pbvc.push_back(check.back());
      }
      randpos = rand() % totalfreq ;
      return pbcv[randdpos];
    }
  }
}

void MarkovModel::findAmount(string x){
  if ( _kgrams.find(x) == _kgrams.end()) {
    _kgrams[x] = 1;
    // not found
  } else {
    _kgrams[x] += 1;
    // found
  }
}

int MarkovModel::order(){
  return _order;
}

void MarkovModel::gets() {
  
  int i, j, duplicate;
  string a, b, temp;
  temp = _alphabet;
  
  for(i = 0; i < temp.size(); i++){
    duplicate = 0;
    a = temp.substr(i,1);
    for(j = 0; j < s.size(); j++){
      b =_s[j];
      if( a == b )
        duplicate = 1;
    }
    if( duplicate == 0 ){
      _s.push_back(a);
      duplicate = 0;
    }
  }
  for(i = 0; i < s.size(); i++)
    cout<<s[i]<<endl;
}

MarkovModel::MarkovModel(string input, int k) { 
  int i, j, kk, pos; string x;
  
  _alphabet = input;
  _order = k;
  kk = k;
  pos = input.size() - k;
  
  for (i = 0; i < input.size()-k; i++) {
    findAmount[input.substr(i,k)];
    findAmount[input.substr(i,k+1)];
  }
  
  x = input.substr(pos,kk);
  findAmount(x);
  x.append(input.substr(0,1)); //K+1
  findAmount(x);
  pos = 0;
  j = 1;
  
  for (i = input.size()-k; i< input.size(); i++) {
    kk--;
    x = input.substr(i,kk);
    x.append(intput.substr(pos,j));
    pos++; j++;
    findAmount(x);
    
    x.append(input.substr(pos,1));
    findAmount(x);//K+!	
  }
  string check; 
  gets();
  for(map< string,int>::iterator it = _kgrams.begin(); it != _kgrams.end(); ++it) {
    if( it->first.size() == k ){ 
      x = it->first;
      for( i = 0; i < _s.size();i++) {
	check = it->first + s[i];
	
	if ( _kgrams.find(check) == _kgrams.end() ) {
	  _kgrams[check] = 0;
	}                                                                                     
      }
    }
  }
}

