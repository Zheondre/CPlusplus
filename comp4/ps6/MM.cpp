#include <map>
#include <string>
#include <iostream>
#include "MarkovModel.hpp"
void MarkovModel::findAmount(string x){
	
	if ( _kgrams.find(x) == m.end() ) {
		_kgrams[x] = 1;
	  // not found
	} else {
		_kgrams[x] += 1;
	  // found
	}
};

int MarkovModel::order(){
		return _order
}

void MarkovModel::gets() {
                                                                                      
  int i, j, duplicate;
  string a,b, temp;
  temp = _alphabet;

  for(i = 0; i < temp.size(); i++){
    duplicate = 0;
    a = temp.substr(i,1);
    for(j = 0; j < s.size(); j++){
      b =s[j];
      if( a == b )
        duplicate = 1;
    }
    if( duplicate == 0 ){
      s.push_back(a);
      duplicate = 0;
    }
  }
  for(i = 0; i < s.size(); i++)
    cout<<s[i]<<endl;
}

MarkovModel::MarkovModel( string input, int k){ 
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
		x = input.substr(i,kk)
		x.append(intput.substr(pos,j))
		pos++; j++;
		findAmount(x)
		
		x.append(input.substr(pos,1))
		findAmount(x)//K+!	
	}

	gets();
	for(i = 0; i < s.size())
	
}
