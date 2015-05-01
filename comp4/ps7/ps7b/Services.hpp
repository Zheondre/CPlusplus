//  Copyright 2015 Zheondre Calcano
#ifndef _Kronos_
#define _kronos_

#include <boost/regex.hpp>
#include <boost/date_time.hpp>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;
class services{
  //vector< bool > CpServ;
  vector< string > sname, StartLN, CompleteLN, ElapsedT;
  string startservice, GoodStart, allfs;
  regex rs;
  int sofV;

public:
  services(){
    sname.push_back("Logging");
    sname.push_back("DatabaseInitialize");
    sname.push_back("MessagingService");
    sname.push_back("HealthMonitorService");
    sname.push_back("Persistence");
    sname.push_back("ConfigurationService");
    sname.push_back("LandingPadService");
    sname.push_back("PortConfigurationService");
    sname.push_back("CacheService");
    sname.push_back("ThemingService");
    sname.push_back("StagingService");
    sname.push_back("DeviceIOService");
    sname.push_back("BellService");
    sname.push_back("GateService");
    sname.push_back("ReaderDataService");
    sname.push_back("BiometricService");
    sname.push_back("StateManager");
    sname.push_back("OfflineSmartviewService");
    sname.push_back("AVFeedbackService");
    sname.push_back("DatabaseThreads");
    sname.push_back("SoftLoadService");
    sname.push_back("WATCHDOG");
    sname.push_back("ProtocolService");
    sname.push_back("DiagnosticsService");
    startservice = ".*Starting Service.  ";
    GoodStart = "Service started successfully.  ";
    sofV = sname.size();
    //throw an error if vector is empty
    allfs = "\t*** Services not successfully started: ";
    for( int i = 0; i < sofV; i++){
      StartLN.push_back("-1");
      CompleteLN.push_back("-1");
      ElapsedT("-1");
      allfs += sname[i]+", ";
    }
    allfs += "\n";
    //rs ="\\(([0-9]{1,})\\)";
    rs = "\\(([^()]*)\\)";
  }
  void ServiceSuccess(string, int);
  void ServiceStart(string, int);
  string getCompleteLN(int);
  string getStartLN(int); 
  string getElapsedT(int);
  string getsr(int);
  string AFail();
  string getSta();
  string getGS();
  regex getRS();
  int sz();
};
regex services::getRS() { return rs; }
string services::AFail() { return allfs; }
string services::getsr(int x) {
  if(x < 0)
    throw std::invalid_argument( "Value is less than 0");
  if(x > sofV)
    throw std::invalid_argument( "Value is greater than vector size");
  return sname[x];
}
string services::getSta() { return startservice; }
string services::getGS() { return GoodStart; }
string services::getCompleteLN(int x){ return CompleteLN[x]; }
string services::getStartLN(int x) { return StartLN[x]; }
string services::getElapsedT(int x) { return ElapsedT[x]; }
int services::sz() { return sofV; }
void services::ServiceStart(strin line, int linenum) { 
 int i;  std::ostringstream so;
 for (i = 0; i < s.sofV; i++) {
   regex e(s.getSta() + s.getsr(i) + ".*");
   if (regex_match (line,e)) {  //Success service found
     cout << lif << endl;
     so.str("");
     so << linenum;
     StartLN[i] = so.str();
   }
 }
 //starting service found
}
void services::ServiceSuccess(string line, int linenum) {
  int i; smatch sm; std::ostringstream so;
  for(i = 0; i < s.sofV; i++) {
    regex e(s.getGS() + s.getsr(i) + ".*");
    if (regex_match (line,e)){  //Success service found
      cout << lif << endl;
      if(regex_search(lif, sm, dig)){
	so.str("");
	so << linenum;
	ElapsedT[i] << boost::lexical_cast<string>(sm[1]);
	CompleteLN[i] = so.str();
      }
    }
  }
}
#endif
