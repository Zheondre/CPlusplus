#include <string.h>
#include <iostream>
#include <map>
#include <utility>



MM{ 
  string _Kgram; string cycle; char cyclea; 
  map< string, map< string, int > > _FreqOfChar;
  map< string, map< string, double > > _PbOfChar;
 public:

  MM();

} 

int MM::MM(){ 
  //if the string is empty throw an exception




} 

void func( string a, int k ){ 




} 
/*

create a map of a map for the freq of the next char

aa --->(aa 2), (a 1), (c 0), (g 1)  
ag --->(ag 5), (a 3), (c 0), (g 2) 
ga --->(ag 5), (a 1), (c 0), (g 4)
gc --->(ag 1), (a 0), (c 0), (g 1) 

then create a map for the 

mm[aa][aa]= 2
mm[aa][a] = 1




 */
