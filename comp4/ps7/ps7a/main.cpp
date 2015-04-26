#include <fstream>
#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

string tme(string& linefromfile){
  //get time and date from current file
 
  string tandmm = "([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])(?:\\.([0-9]{1,4}))?";
  string t =  "^(?:(?:([01]?\\d|2[0-3]):)?([0-5]?\\d):)?([0-5]?\\d)$";
  string Date = "[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])";
  //std::regex e ("(sub)(.*)"); example
  
  regex e (Date);
smatch sm;    // same as std::match_results<string::const_iterator> sm;
  regex_match (linefromfile,sm,e);
  string temp = sm[0] ;
  cout << temp<<endl;
}

void parse(string &fn){ 
int linenum; 
regex e;
string filename, lif, rs;
rs = "(log.c.166) server started";

std::ifstream infile(fn.c_str());

e = regex(rs);

while( getline(infile, lif)){

if( regex_match (lif,e) )
  tme(lif); // if there is a match get date and time
linenum++;
cout << linenum << " "<< lif << endl;
} 
}

int totaltime(){ 
}

int main (int argc, char *argv[]) {
  int linenum; string filename, lif,rs;
  
  filename = argv[1];  
  parse(filename);
  return 0;
  //ofstream resultsfile;
  //myfile.open(filename) creatingfile for log but needs some work
}
