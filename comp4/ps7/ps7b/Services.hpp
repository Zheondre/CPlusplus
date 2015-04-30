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
  vector< string > sname;
  string startservice, GoodStart, allfs, rs;
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
    for( int i = 0; i < sofV; i++)
      allfs += sname[i]+", ";
    allfs += "\n";
    rs = "([0-9]{3})";
  //might have to hadd .* at the beginnning..
  }

  string getsr(int);
  string AFail();
  string getSta();
  string getGS();
  string getRS();
  int sz();
};
string services::getRS() { 
  return rs;
}
string services::AFail() {
  return allfs;
}
string services::getsr(int x) {
  if(x < 0)
    throw std::invalid_argument( "Value is less than 0");
  if(x > sofV)
    throw std::invalid_argument( "Value is greater than vector size");
  return sname[x];
}
string services::getSta() {
  return startservice;
}
string services::getGS() {
  return GoodStart;
}
int services::sz() {
  return sofV;
}
#endif
