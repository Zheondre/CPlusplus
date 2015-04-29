#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <boost/date_time.hpp)
using namespace std;
using namespace boost;

int main (){

  //using namespace boost::gregorian;
  //using namespace boost::posix_time;

  string t = "(\\d{2}):(\\d{2}):(\\d{2})";
  //(\d{2}):(\d{2}):(\d{2})
  string tmm= "(\\d{2}):(\\d{2}):(\\d{2}\\.\\d{3})";
  //(\d{2}):(\d{2}):(\d{2})\.(\d{3})
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";

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
    //bool match = regex_match (fs,sm,e);
    bool match = regex_search(fsb,sm, e);
    cout<<( match? "Matched" : "Not matched") <<endl<< endl;
    if (sm.size() > 0) {
      cout << "the matches were: "<<endl;
      for (unsigned i=0; i<sm.size(); ++i) {
	cout << "[" << sm[i] << "] " << endl;

      }
      /*
        boost::postix_time::time_duration ta(sm[1], sm[2], sm[3]);
	boost::postix_time::time_duration tb(sn[1], sn[2], sn[3]); 
	tb += milliseconds( (long)sn[4]);
	tb = tb - ta ;
	cout <<tb.total_miliseconds()<< endl;
      */
    }
  } 
}

/* 

time(){
using namespace boost::gregorian;
using namespace boost::posix_time;

boost::postix_time::time_duration ta(sm[1],sm[2],sm[3]) 
boost::postix_time::time_duration tb(sn[1], sn[2], sn[3]) 
tb = milliseconds( (long)sn[4])

ta = ta - tb ;

ta.total_miliseconds();
}
vector< strings > names
names.push_back("Logging");
names.push_back("DatabaseInitialize");
names.push_back("MessagingService");
names.push_back("HealthMonitorService");
names.push_back("Persistence");
names.push_back("ConfigurationService");
names.push_back("LandingPadService");
names.push_back("PortConfigurationService");
names.push_back("CacheService");
names.push_back("ThemingService");
names.push_back("StagingService");
names.push_back("DeviceIOService");
names.push_back("BellService");
names.push_back("GateService");
names.push_back("ReaderDataService");
names.push_back("BiometricService");
names.push_back("OfflineSmartviewService");
names.push_back("AVFeedbackService");
names.push_back("DatabaseThreads");
names.push_back("SoftLoadService");
names.push_back("WATCHDOG");
names.push_back("ProtocolService");
names.push_back("DiagnosticsService");




*/
