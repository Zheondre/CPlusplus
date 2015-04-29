//  Copyright 2015 Zheondre Calcano
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include <boost/date_time.hpp>
// g++ main.cpp -lboost_regex

using namespace std; //NOLINT
using namespace boost; //NOLINT

void efname( string &name ) { name += ".out";}
void wtof( string name, string info){
  std::fstream outfile;
  outfile.open(name.c_str(), std::fstream::app);
  cout << info;
  outfile << info;
  outfile.close();
}
void parse(string fn ){ 
  int linenum, completeboot; 
  vector< int > holdval;
  holdval.push_back(0);
  holdval.push_back(0);
  holdval.push_back(0);  
  string ufn, filename, lif, rs, rsa, temp,boottime;
  ufn = fn;
  efname(fn);
 
  rs = ".*log.c.166.*";
  rsa = ".*oejs.AbstractConnector:Started SelectChannelConnector.*";
  string t = "(\\d{2}):(\\d{2}):(\\d{2})";
  //(\d{2}):(\d{2}):(\d{2})
  string tmm= "(\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3})";
  //(\d{2}):(\d{2}):(\d{2})\.(\d{3})
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";
  
  boottime= "Boot Time: ";
  wtof(fn,"Device Boot Repot \n " + ufn + "\n"); 
  std::ifstream infile(ufn.c_str());
  smatch sm, sn, so,sp;
  regex e = regex(rs);
  regex ea = regex(rsa); 
  regex etime(t);
  regex f(tmm);
  regex getdate(gd);
  regex getdatea(gd);
  std::ostringstream ss;
  
  linenum = completeboot = 0; 
  
  while(getline(infile, lif)){
    linenum++;
    if(regex_match(lif,e)){
      if( completeboot == 1){ //badboot
	wtof(fn, "**** Incomplete boot ****\n");
	  completeboot = 0;
      } else{ // startboot
	wtof(fn, "=== Device boot ===\n");
	regex_search(lif, sm, etime);
	regex_search(lif, so, getdate);
	holdval[0] = boost::lexical_cast<int>(sm[1]);
	holdval[1] = boost::lexical_cast<int>(sm[2]);
	holdval[2] = boost::lexical_cast<int>(sm[3]);	
	ss << linenum ;
	temp = ss.str();
	temp += "(" + ufn + "):";
	temp += so[0] + " " + sm[0] + " Boot Start \n";
	wtof(fn,temp);
	completeboot = 1;
	temp.clear();
      }
    }
    if(regex_match(lif,ea)){ //good boot

      ss << linenum;
      temp = ss.str(); // linenum
      temp += "(" + ufn + "):";
      regex_search(lif, sn, f);
      regex_search(lif, sp, getdatea);
      //I should put a case to check to see if the vector values are 
      //equvalent to 0 but I ran out of time.
      boost::posix_time::time_duration ta(holdval[0],holdval[1],holdval[2]);
      boost::posix_time::time_duration tb(boost::lexical_cast<int>(sn[1]),
					  boost::lexical_cast<int>(sn[2]),
					  boost::lexical_cast<int>(sn[3]));
      //tb += boost::posix_time::millisec(boost::lexical_cast<int>(sn[4]));
      tb = tb - ta;
      temp += sp[0] + " " + sn[0] + " " + "Boot Completed \n";
      wtof(fn,temp);
      ss << tb.total_milliseconds();
      wtof(fn, boottime + ss.str()+"\n");
      completeboot = 0;
      temp.clear();
	}
    // cout<< "No match on current line."<<endl;
  }  
}
int main(int argc, char *argv[]) {
  string filename;
  filename = argv[1];
  if (filename.size() < 1)
    throw
      std::runtime_error("Null string for file name");  
  parse(filename);
  return 0;
}
