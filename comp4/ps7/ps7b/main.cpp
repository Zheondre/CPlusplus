//  Copyright 2015 Zheondre Calcano
#include <boost/regex.hpp>
#include <boost/date_time.hpp>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Services.hpp"

using namespace std; //NOLINT
using namespace boost; //NOLINT

void efname(string &name) { name += ".rpt";}
void parse(string fn) {
  int linenum, completeboot, startS;
  vector< int > holdval;
  services s;
  holdval.push_back(0);
  holdval.push_back(0);
  holdval.push_back(0);
  string ufn, filename, lif, rs, rsa, temp, boottime;
  ufn = fn;
  efname(fn);
  std::fstream outfile;
  cout << fn << endl;
  outfile.open(fn.c_str(), fstream::out);
  rs = ".*log.c.166.*";
  rsa = ".*oejs.AbstractConnector:Started SelectChannelConnector.*";
  string t = "(\\d{2}):(\\d{2}):(\\d{2})";
  string tmm = "(\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3})";
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";
  boottime = "Boot Time: ";
  outfile << "Device Boot Repot \n" + ufn + "\n\n";
  std::ifstream infile(ufn.c_str());
  smatch sm, sn, so, sp;
  regex e = regex(rs);
  regex ea = regex(rsa);
  regex etime(t);
  regex f(tmm);
  regex getdate(gd);
  regex getdatea(gd);
  std::ostringstream ss;
  linenum = completeboot = startS = 0;
  while (getline(infile, lif)) {
    linenum++;
    if (regex_match(lif, e)) {
      if (completeboot == 1) {
        outfile << "**** Incomplete boot ****\n\n";
        completeboot = 0;
	for (i = 0 ; i < sname.size(); i++) { 
	  outfile << "Servces \n\t" +s.getsr(i)+"\n";
	  outfile << "\t\t Start: Not started("+ ufn +")\n";
	  outfile << "\t\t Completed: Not Completed(" + ufn + ")\n";
	  outfile << "\t\t Elaplsed Time:\n"; 
	}
	//all failed services 
	outfile << s.AFail();
      }
      outfile << "=== Device boot ===\n";
      regex_search(lif, sm, etime);
      regex_search(lif, so, getdate);
      holdval[0] = boost::lexical_cast<int>(sm[1]);
      holdval[1] = boost::lexical_cast<int>(sm[2]);
      holdval[2] = boost::lexical_cast<int>(sm[3]);
      ss.str("");
      ss << linenum;
      temp = ss.str();
      temp += "(" + ufn + "):";
      temp += so[0] + " " + sm[0] + " Boot Start \n";
      outfile << temp;
      completeboot = 1;
      startS = 1;
      temp.clear();
    }
    if(startS == 1) {
      s.ServiceStart(lif, linenum);
      s.ServiceSuccess(lif, linenum);
      startS = 0;
    }
    if (regex_match(lif, ea)) {
      for (i = 0; i < s.getsz() ; i++ ) {
	if( s.getCompleteLN(i) != "-1" ) {
	  outfile << "Services\n"
	  outfile << "\t" + s.sr(i) + "\n\t\tStart: " + s.getStartLN(i) + "(" + ufn + ")\n";
	  outfile << "\t\tCompleted: " + s.getCompleteLN(i) + "(" + ufn + ")\n";
	  outfile << "\t\tElapsed Time: " + s.getElapsedT(i);
	}
	else{ 
	  outfile << "\t" + s.sr(i) + "\n\t\tStart: " + s.getStartLN(i) + "(" + ufn + ")\n";
	  outfile << "\t\tCompleted: Not completed(" + ufn +")\n\t\tElapsed Time:\n"  ;
	}
      } 
      //print line saying which services didnt start up
     
      // check complete T
      //after set all values tp -1

      ss.str("");
      ss << linenum;
      temp = ss.str();
      temp += "(" + ufn + "):";
      regex_search(lif, sn, f);
      regex_search(lif, sp, getdatea);
      boost::posix_time::time_duration ta(holdval[0], holdval[1], holdval[2]);
      boost::posix_time::time_duration tb(boost::lexical_cast<int>(sn[1]),
                                          boost::lexical_cast<int>(sn[2]),
                                          boost::lexical_cast<int>(sn[3]));
      //  tb += boost::posix_time::millisec(boost::lexical_cast<int>(sn[4]));
      tb = tb - ta;
      temp += sp[0] + " " + sn[0] + " " + "Boot Completed \n";
      outfile << temp;
      ss.str("");
      ss << tb.total_milliseconds();
      outfile <<"\t"+ boottime + ss.str() + " ms\n\n";
      completeboot = 0;
      temp.clear();
    }
  }
  outfile.close();
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
