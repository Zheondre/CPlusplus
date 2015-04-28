#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

int main (){
  //to get time with out mm
  //month, day, year, hours, minutes, seconds
  string m, d, y, h, m,s;
  string t = ".*(\\d{2}):(\\d{2}):(\\d{2}).*";
  string tmm= "(\\d{2}):(\\d{2}):(\\d{2}\\.\\d{3})";
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";
 //will grab the time, and give you all the peices to the time and mm secs.
  string f = ".*log.c.166.*"; // will only find line with this text in it use regmatch
  string fs = "2014-01-26 09:55:07: (log.c.166) server started";
  //use regmatch
  string fsa = "oejs.AbstractConnector:Started SelectChannelConnector"; 
  string fsb = "2014-01-26 09:58:04.362:INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";
  string s, rs;
  regex e;
  smatch sm;
  string temp;
  while( true ) { 
    cin >> s; 
    regex e(s);
    bool match = regex_match (fsa,sm,e);
    //bool match = regex_search(fs,sm, e);
    cout<<( match? "Matched" : "Not matched") <<endl<< endl;
    if (sm.size() > 0) {
      cout << "the matches were: "<<endl;
      for (unsigned i=0; i<sm.size(); ++i) {
	cout << "[" << sm[i] << "] " << endl;
	temp =sm[0];
	cout << sm[0];
      }
    }
  } 
}
