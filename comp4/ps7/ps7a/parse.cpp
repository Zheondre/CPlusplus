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
void efname( string &name ) { name += name + ".out";}
void wtof( string name, string info){ 
  std::ofstream outfile;
  outfile.open(name, std::ios_base::app);
  outfile << info;
}
void parse(string fn, vector< string > &names ){ 
  int linenum, completeboot; 
  string ufn, filename, lif, rs,rsa, temp;
  ufn = fn;
  efname(fn);
 
  rs = ".*log.c.166.*"
  rsa = ".*oejs.AbstractConnector:Started SelectChannelConnector.*";
  //t = ("([0-9]+)-([0-9]+)-([0- 9]+)""([0-9]+):([0-9]+):([0-9]+)"".*AbstractConnector:Started SelectChannelConnector.*")
  
  boottime= "Boot Time: ";
  wtof(fn,"Device Boot Repot \n " + uf + "\n"); 
  
  std::ifstream infile(fn.c_str());
  regex e, ea;
  e = regex(rs);
  ea = regex(rsa)
  linenum = completeboot = 0; 

  while(getline(infile, lif)){
	linenum++;
    if(regex_match(lif,e)){
		if( completeboot == 1){ //badboot
			wtof(fn, "**** Incomplete boot ****\n") // ==device boot ==
			completeboot = 0;
		} else{ // startboot
			wtof(fn, "=== Device boot ===\n");
			//use regex_search
			temp = std::to_string(linenum); // linenum
			temp += "(" + ufn + "):";
			
			wtof(fn,temp);
			completeboot = 1;
			temp = "";
		}
    }
	if( regex_match(rsa,e)){ //good boot
		temp = std::to_string(linenum); // linenum
		temp += "(" + ufn + "):";
		
		
		
		wtof(fn,temp);
		completeboot = 0;
		temp = ""
	}
    cout<< "No match on current line."<<endl;
  }  
}