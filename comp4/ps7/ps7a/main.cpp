#include <fstream>
#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

string tme(string& linefromfile){
  //get time and date from current file
  
  string tandmm = "([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])(?:\\.([0-9]{1,4}))?";
  string t = "^(?:(?:([01]?\\d|2[0-3]):)?([0-5]?\\d):)?([0-5]?\\d)$";
  
  //std::regex e ("(sub)(.*)"); example
  
  regex e(Da);
  smatch sm;    // same as std::match_results<string::const_iterator> sm;
  regex_match (linefromfile,sm,e);
  string temp = sm[0] ;
  cout << temp << endl;
}

void parse(string &fn, vector< string > &names ){ 
  int linenum; 
  regex e;
  string filename, lif, rs, temp;
  string t = ("([0-9]+)-([0-9]+)-([0- 9]+)""([0-9]+):([0-9]+):([0-9]+)"".*AbstractConnector:Started SelectChannelConnector.*")
  // works "([0-9]+)-([0-9]+)-([0-9]+).*"
  
  //rs = "( )";
  //temp = "(bob)(.*)"; <- works
  std::ifstream infile(fn.c_str());
  e = regex("(\\W|^)(log)(\\W|$)");
 
  linenum = 0; 

  while(getline(infile, lif)){
   
    if(regex_match(lif,e)){
      cout << linenum << " "<< lif << endl;//works
      tme(lif);  
    }    
    linenum++;
    cout<< "No match on current line."<<endl;
  } 
}

//int totaltime(){ 
//}

int main (int argc, char *argv[]) {
  string filename;
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

  filename = argv[1];  
  parse(filename, names);
  return 0;
  //ofstream resultsfile;
  //myfile.open(filename) creatingfile for log but needs some work
}
