#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
*/
void efname( string &name ) { name += ".out";}
void wtof( string name, string info){ 
  std::ofstream outfile;
  outfile.open(name, std::ios_base::app);
  outfile << info;
}
void parse(string fn ){ 
  int linenum, completeboot, he, hf, hg;; 
  int vector<int> holdval;
  holdval.push_back(0);
  holdval.push_back(0);
  holdval.push_back(0);  
  string ufn, filename, lif, rs, rsa, temp;
  ufn = fn;
  efname(fn);
 
  rs = ".*log.c.166.*"
  rsa = ".*oejs.AbstractConnector:Started SelectChannelConnector.*";
  string t = "(\\d{2}):(\\d{2}):(\\d{2})";
  //(\d{2}):(\d{2}):(\d{2})
  string tmm= "(\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3})";
  //(\d{2}):(\d{2}):(\d{2})\.(\d{3})
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";
  
  boottime= "Boot Time: ";
  wtof(fn,"Device Boot Repot \n " + uf + "\n"); 
  std::ifstream infile(fn.c_str());
  smatch sm, sn, so,sp;
  regex e = regex(rs);
  regex ea = regex(rsa); 
  regex etime(t);
  regex f(tmm);
  regex getdate(gd);
  regex getdatea(gd);
  
  linenum = completeboot = 0; 

 while(getline(infile, lif)){
	linenum++;
    if(regex_match(lif,e)){
		if( completeboot == 1){ //badboot
			wtof(fn, "**** Incomplete boot ****\n")
			completeboot = 0;
		} else{ // startboot
			wtof(fn, "=== Device boot ===\n");
			regex_search(lif, sm, etime);
			regex_search(lif, so, getdate);
			holdval[0] = boost::lexical_cast<int>(sm[1]);
			holdval[1] = boost::lexical_cast<int>(sm[2]);
			holdval[2] = boost::lexical_cast<int>(sm[3]);	
			temp = std::to_string(linenum); // linenum
			temp += "(" + ufn + "):";
			temp += so[0] + " " + sm[0] + " Boot Start \n";
			wtof(fn,temp);
			completeboot = 1;
			temp = "";
		}
    }
	if(regex_match(lif,e)){ //good boot
		temp = std::to_string(linenum); // linenum
		temp += "(" + ufn + "):";
		regex_search(lif, sn, f);
		regex_search(lif, sp, getdatea);
		//I should put a case to check to see if the vector values are 
		//equvalent to 0 but I ran out of time.
		boost::posix_time::time_duration ta(holdval[0],holdval[1],holdval[2])
		boost::posix_time::time_duration tb(boost::lexical_cast<int>(sn[1]),
											boost::lexical_cast<int>(sn[2]),
											boost::lexical_cast<int>(sn[3]));
		tb += boost::posix_time::millisec(boost::lexical_cast<int>(sn[4]));
		tb = tb - ta;
											
		temp += sp[0] + " " + sn[0] + " " + "Boot Completed";
		wtof(fn,temp);
		tb.total_milliseconds()
		wtof(fn, boottime + std::to_string(tb.total_milliseconds()));
		completeboot = 0;
		temp = ""
	}
    cout<< "No match on current line."<<endl;
  }  
}