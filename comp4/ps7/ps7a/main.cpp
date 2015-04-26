#include <fstream>
#include <iostream>
#include <string>
#include <boost/regex.hpp>
using namespace std;
using namespace boost;

void parse(string &filename){ 
  int linenum; 
  regex e;string filename, lif,rs;
  rs = "(log.c.166) server started";
  
  std::ifstream infile(filename.c_str());
  
  try{
    e = regex(rs);
  }catch(regex_error& exc){
    cout <<"Regex constructor failed with code" << exc.code() << endl;
    exit(1);
  }

  
  while( getline(infile, lif)){
   
    if( regex_match (lif,e) )
      time(lif ); // if there is a match get date and time
    linenum++;
    cout << linenum << " "<< lif << endl;
  }
} 

string time(string& linefromfile){
  //get time and date from current file
 
  string tandmm = "([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])(?:\\.([0-9]{1,4}))?";
  string t =  "^(?:(?:([01]?\d|2[0-3]):)?([0-5]?\d):)?([0-5]?\d)$";
  string Date = "[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])";
  //std::regex e ("(sub)(.*)"); example
  
  std::regex e (Date);
  std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
  std::regex_match (s,sm,e);
  std::cout << "the matches were: ";
  
  std::cout << "[" << sm[i] << "] ";
  string temp = sm[0] ;
  cout << temp<<endl;
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
