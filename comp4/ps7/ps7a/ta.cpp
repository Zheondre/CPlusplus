#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

int main (){


  string fs = "2014-01-26 09:55:07: (log.c.166) server started";
  string fsa = "oejs.AbstractConnector:Started SelectChannelConnector";
  string s, rs;
  regex e;
  smatch sm;

  while( true ) { 
    cin >> s; 
    regex e(s);
    bool match = regex_match (fs,sm,e);
    //bool match = regex_search(fsa, e);
    cout<<( match? "Matched" : "Not matched") <<endl<< endl;
    if (sm.size() > 0) {
      cout << "the matches were: "<<endl;
      for (unsigned i=0; i<sm.size(); ++i) {
	cout << "[" << sm[i] << "] " << endl;
      }
    }
  } 
}
