#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main( int argc, char *argv[] ) {

  string a;
  int i;
  map< string,int > k;
  string temp = "hello";
  for(map< string,int>::iterator it = k.begin(); it != k.end(); ++it) {
    // v.push_back(it->first);
    cout << it->first << "\n";
    cout << it->second<<endl;
  }

}
