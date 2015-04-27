#include <fstream>
#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

string tme(string& linefromfile){
  //get time and date from current file
  
  string tandmm = "([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])(?:\\.([0-9]{1,4}))?";
  string t = "^(?:(?:([01]?\\d|2[0-3]):)?([0-5]?\\d):)?([0-5]?\\d)$";
  string Da = "[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1]).";
  //std::regex e ("(sub)(.*)"); example
  
  regex e(Da);
  smatch sm;    // same as std::match_results<string::const_iterator> sm;
  regex_match (linefromfile,sm,e);
  string temp = sm[0] ;
  cout << temp << endl;
}

void parse(string &fn){ 
  int linenum; 
  regex e;
  string filename, lif, rs, temp;
  //string t = ("([0-9]+)-([0-9]+)-([0- 9]+)""([0-9]+):([0-9]+):([0-9]+)"".*AbstractConnector:Started SelectChannelConnector.*")
  // works "([0-9]+)-([0-9]+)-([0-9]+).*"
  
  //rs = "( )";
  //temp = "(bob)(.*)"; <- works
  std::ifstream infile(fn.c_str());
  e = regex("(\\W|^)(log)(\\W|$)");
 
  linenum = 0; 

  while(getline(infile, lif)){
   
    if(regex_match(lif,e)){
      cout << linenum << " "<< lif << endl;//works
      tme(lif);  
    }    
    linenum++;
    cout<< "No match on current line."<<endl;
  } 
}

//int totaltime(){ 
//}

int main (int argc, char *argv[]) {
  string filename;
  
  filename = argv[1];  
  parse(filename);
  return 0;
  //ofstream resultsfile;
  //myfile.open(filename) creatingfile for log but needs some work
}
