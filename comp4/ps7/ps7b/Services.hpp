//  Copyright 2015 Zheondre Calcano
#ifndef _Services_
#define _Services_

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
  vector< int > start, end;
  vector< string > sname, StartLN, CompleteLN, ElapsedT;
  string startservice, GoodStart, allfs, fSM, startSoftload, EndSoftload;
  string l1, l2, l3, l4, l5;
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
    fSM = "\t*** Services not successfully started: ";
    allfs = "\t*** Services not successfully started: ";
    startSoftload = ".*SOFTLOADSERVICE;Install started.*";
    EndSoftload =".*ExitValue from install command : 0.*";
    for (int i; i < 3; i++) { 
      start.push_back(0);
      end.push_back(0);
    }
    for( int i = 0; i < sofV; i++){
      StartLN.push_back("-1");
      CompleteLN.push_back("-1");
      ElapsedT.push_back("-1");
      allfs += sname[i]+", ";
    }
    allfs += "\n";
    //rs ="\\(([0-9]{1,})\\)";
    rs = "\\(([^()]*)\\)";
  }
  void setNegvalues();
  void ServiceSuccess(string, int);
  void ServiceStart(string, int);
  void findOV(string);
  void findNV(string);
  void SoftloadS(string, int, string);
  void SoftloadEnd(string, int, string);
  string getfSM();
  string getCompleteLN(int);
  string getStartLN(int);
  string getElapsedT(int);
  string getsr(int);
  string AFail();
  string getSta();
  string getGS();
  void GetEtime();
  string getL1();
  string getL2();
  string getL3();
  string getL4();
  string getL5();
  regex getRS();
  int sz();
};
string services::getL1(){
  string t;
  t = l1;
  l1 = "";
  return t;
}
string services::getL2(){
  string t;
  t = l2;
  l2 = "";
  return t;
}
string services::getL3(){
  string t;
  t = l3;
  l3 = "";
  return t;
}
string services::getL4(){
  string t;
  t = l4;
  l4 = "";
  return t;
}
string services::getL5(){
  string t;
  t = l5;
  l5 = "";
  return t;
}
regex services::getRS() { return rs; }
string services::AFail() { return allfs; }
string services::getsr(int x) {
  if(x < 0)
    throw std::invalid_argument( "Value is less than 0");
  if(x > sofV)
    throw std::invalid_argument( "Value is greater than vector size");
  return sname[x];
}
string services::getfSM(){ return fSM ; }
string services::getSta() { return startservice; }
string services::getGS() { return GoodStart; }
string services::getCompleteLN(int x){ return CompleteLN[x]; }
string services::getStartLN(int x) { return StartLN[x]; }
string services::getElapsedT(int x) { return ElapsedT[x]; }
int services::sz() { return sofV; }
void services::setNegvalues(){
  for (int i = 0; i < sofV; i++){
    StartLN[i] = "-1";
    CompleteLN[i]= "-1";
    ElapsedT[i] = "-1";
  }
} 
void services::ServiceStart(string line, int linenum) { 
 int i;  std::ostringstream so;
 for (i = 0; i < sofV; i++) {
   regex e(getSta() + getsr(i) + ".*");
   if (regex_match(line,e)) {  //Start service found
     so.str("");
     so << linenum;
     StartLN[i] = so.str();
   }
 }
 //starting service found
}
void services::ServiceSuccess(string line, int linenum) {
  int i; smatch sm; std::ostringstream so;
  for(i = 0; i < sofV; i++) {
    regex e(getGS() + getsr(i) + ".*");
    if (regex_match(line,e)){  //Success service found
      regex dig(rs); 
      if(regex_search(line, sm, dig)){
	so.str("");
	so << linenum;
	ElapsedT[i] = boost::lexical_cast<string>(sm[1]);
	CompleteLN[i] = so.str();
      }
    }
  }
}
void services::findOV(string line) {
  smatch sm; std::ostringstream so; string ltp;
  regex e(".*intouch-application-base-.*");
  if (regex_match(line, e)) {//works
    //cout << line << endl;
    regex rge(".*: removing");
    if (regex_match(line, rge)) {
      regex dig("(?=-[0-9])(.*?)(?=\\.armv)");
      if(regex_search(line, sm, dig)){
	ltp = boost::lexical_cast<string>(sm[0]);
	cout << ltp.erase(0,1) << " helllooo" << endl;
	l2 = "Original version ==> " + ltp + "\n";
      }
    }
  }
}
void services::findNV(string line) {
  smatch sm; std::ostringstream so; string ltp;
  regex e(".*intouch-application-base-.*");
  if (regex_match(line, e)) {// works
    //cout << line << endl;
    regex rge(".*: Processing");
    if (regex_match(line, rge)) {
      regex dig("(?=-[0-9])(.*?)(?=\\.armv)");
      if(regex_search(line, sm, dig)){
	ltp = boost::lexical_cast<string>(sm[0]);
	cout << ltp.erase(0, 1) << endl;
	l3 = "New version ==> "+ltp +"\n";
      }
    }
  }
}

void services::SoftloadS(string line, int ln, string fn) {
  // if valid line drab date
  //cout << line << endl;
  smatch sm; std::ostringstream so; string ltp;
  regex e(startSoftload);
  if (regex_match(line, e)) {//this regex works
    cout << line << endl; 
    regex rge("(\\s*\\w{3}\\s*[0-9]{2})([0-9]{2}):([0-9]{2}):([0-9]{2})");
    if (regex_search(line, sm, rge)) { //dw
      cout << line << endl;
      so.str("");
      so << ln;
      ltp = so.str() + "(" + fn + ") : "
	+ boost::lexical_cast<string>(sm[0]);
      ltp += "Softload Start\n";
      start[0] = boost::lexical_cast<int>(sm[1]); 
      start[1] = boost::lexical_cast<int>(sm[2]);
      start[2] = boost::lexical_cast<int>(sm[3]);
      l1 = ltp;
    }
  }
}
void services::SoftloadEnd(string line, int ln, string fn) {
  // if valid line drab date
  smatch sm; std::ostringstream so; string ltp;
  regex e(EndSoftload);
  if (regex_match(line, e)) {//this regex works
    cout << line << endl;
    regex rge("(\\s*\\w{3}\\s*[0-9]{2})([0-9]{2}):([0-9]{2}):([0-9]{2})");
    if (regex_search(line, sm, rge)) {
      cout << line << endl;
      so.str("");
      so << ln;
      ltp = so.str() + "(" + fn + ") : " 
	+ boost::lexical_cast<string>(sm[0]);     
      ltp += "Softload Start\n";
      end[0] = boost::lexical_cast<int>(sm[1]); 
      end[1] = boost::lexical_cast<int>(sm[2]);
      end[2] = boost::lexical_cast<int>(sm[3]);
      l5 = ltp;
      cout << l5 << endl;
      GetEtime();
    }
  }
}
void services::GetEtime() {
  string temp;
  std::ostringstream so;
  boost::posix_time::time_duration st( start[0], start[1], start[2]);
  boost::posix_time::time_duration et( end[0], end[1], end[2]);
  et = et - st;
  so.str("");
  so << et.total_seconds();
  temp = "Elapsed Time (sec) ==> " + so.str() + "\n";
  l4 = temp;
}
#endif
