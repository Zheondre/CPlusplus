#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <map>

using namespace std; 
int main( int argc, char *argv[] ) { 
  //string hold; 
  stringstream ss, check; int i, j, duplicate;
  string a,b;vector< string > s;string temp = "hello";
    
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

k(string input, int kkey){
  int i,kk; strin x;
  kk = kkey;

  // check to see if there is a duplicate, if so increment count
  for(i =0; i< input.size()-k; i++){
    k[input.substr(i,k)]= 1;
    k[input.substr(i,k+1)]= 1;
  }
  
  int pos = input.size()-k;

  x = input.substr(pos,kk);
  k[x] ;
  x.append(input,substr(0,1))
    k[x];
  for(i = input.size()-k; i< input.size(); i++){
    k[input.substr(i,k)]= 1;
  }
  // make sure to check for cycle
}
