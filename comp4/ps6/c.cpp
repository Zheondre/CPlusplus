#include <sstream>
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

using namespace std; 
int main( int argc, char *argv[] ) { 

  vector< string > hold;
  string input = "hello";

  //string ksub; 

  hold.push_back(input.substr(0,1));
  hold.push_back(input.substr(1,1));
  hold.push_back(input.substr(2,1));

  cout<< hold[0]<< endl;
  cout<< hold[1]<< endl;
  cout<< hold[2]<< endl;
}
