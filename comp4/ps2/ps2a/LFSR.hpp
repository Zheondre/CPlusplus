#ifndef _LFSR
#define _LFSR

#include <iostream> 
#include <string> 

using namespace std ; 

class LFSR{ 
protected: 
  string unit ; int t, bit ; 

public : 

  LFSR( string seed, int tap ) : unit(seed), t(tap) {} ; 
  int step() ; 
  int generate( int k ) ; 
  int stTodig( string &a ) ; 


  friend std::ostream& operator<<( std::ostream &out , const LFSR& rhs) {

    out << rhs.unit ;
    return out ;
  };

  string prtln( const LFSR &t, int b ) ;
  
} ; 

#endif 
