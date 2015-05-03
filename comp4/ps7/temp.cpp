//  Copyright 2015 Zheondre Calcano
#include <boost/regex.hpp>
#include <boost/date_time.hpp>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Services.hpp"

using namespace std;
using namespace boost;

void getl(string filename) {
  //int i;
  string lif, fn;
  services s;
  smatch sm;
  fn = filename;
  std::ifstream infile(fn.c_str()); // read test file contentsgit  
  //regex e(s.getSta() + s.getsr(0) + ".*");
  regex e(".*SOFTLOADSERVICE;Install started.*");
  regex rge("(\\s*\\w{3}\\s*[0-9]{2})");// works 
  regex rgd("([0-9]{2}):([0-9]{2}):([0-9]{2})");// works
  while (getline(infile, lif)) {
    if (regex_match (lif,e)){
      cout << lif << endl;
      if(regex_search(lif, sm, rge))
	cout << sm[0] <<endl;
      if(regex_search(lif, sm, rgd))
	cout << sm[0] << endl;
    }
  }
  infile.close();
}
int main(int argc, char *argv[]) {
  string filename;
  filename = argv[1];
  if (filename.size() < 1)
    throw
      std::runtime_error("Null string for file name");
  getl(filename);
  return 0;
}
