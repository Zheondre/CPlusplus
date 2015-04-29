#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <boost/date_time.hpp>

using namespace std;
using namespace boost;

int main (){

  //using namespace boost::gregorian;
  //using namespace boost::posix_time;

  string t = "(\\d{2}):(\\d{2}):(\\d{2})";
  //(\d{2}):(\d{2}):(\d{2})
  string tmm= "(\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3})";
  //(\d{2}):(\d{2}):(\d{2})\.(\d{3})
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";

  //string ft = ".*log.c.166.*"; // will only find line with this text in it use regmatch
  string fs = "2014-01-26 09:55:07: (log.c.166) server started";
  //use regmatch
  string fsa = "oejs.AbstractConnector:Started SelectChannelConnector"; 
  string fsb = "2014-01-26 09:58:04.362:INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";
  string s, rs;
 
  smatch sm, sn, so;
 
  regex e(t);
  regex f(tmm);
  regex getdate(gd);
  //bool match = regex_match (fs,sm,e);
  bool match = regex_search(fs,sm, e);
  bool matcha = regex_search(fsb,sn, f);
  bool gooddate = regex_search(fs, so, getdate);
  
  if(gooddate)
    cout << so[0] << endl;
  cout<<( match? "Matched" : "Not matched") <<endl<< endl;
  cout<<( matcha? "Matched A" : "Not matched A") <<endl<< endl;

  if (match && matcha) {     
    
    int ha,hb,hc,hd, he, hf, hg;
    string example ;

    example = so[0] + " " + sm[0] + " Boot Start \n";

    cout << example ;
    ha = boost::lexical_cast<int>(sm[1]);
    hb = boost::lexical_cast<int>(sm[2]);
    hc = boost::lexical_cast<int>(sm[3]);
    hd = boost::lexical_cast<int>(sn[1]);
    he = boost::lexical_cast<int>(sn[2]);
    hf = boost::lexical_cast<int>(sn[3]);
    hg = boost::lexical_cast<int>(sn[4]);
    //ha = atoi( h.c_str());
    boost::posix_time::time_duration ta(ha, hb, hc);
    boost::posix_time::time_duration tb(hd, he, hf); 
    tb += boost::posix_time::millisec(hg);
    tb = tb - ta ;
    cout <<tb.total_milliseconds()<< endl;
  }
}
