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
  string lif,fn;
  services s;
  fn = filename;
  //outfile.open(fn.c_str(), fstream::out); open and create file it it isnt there
  std::ifstream infile(fn.c_str()); // read test file contents 
  regex e(s.getSta() + s.getsr(0) + ".*");
  
  while (getline(infile, lif)) {
    
    if (regex_match (lif,e)) //starting service found
      cout << lif << endl;
    // if a successfull boot is found, but the service didnt finish report error
    /*if(bad boot){ 
      for (i = 0 ; i < s.sz(); i++) { 
	outfile << "Servces \n\t" + s.getsr(i) + "\n";
	outfile << "\t\t Start: Not started("+ fn +")\n";
	outfile << "\t\t Completed: Not Completed(" + fn + ")\n";
	outfile << "\t\t Elaplsed Time:\n"; 
      }
      //allfailed services 
      outfile << s.AFail();
    }
*/
  }
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
