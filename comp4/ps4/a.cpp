
#include <string> 
#include <iostream> 
#include "a.hpp" 
using namespace std; 

int Edist::penalty( char temp, char tb ){

  if( temp == tb && temp == '-' ) return 0 ; 
  if( temp == tb ) return 0 ; 
  if( temp != tb && ((temp == '-') || (tb == '-'))) return 2 ; 
  return 1 ; 
} 

int Edist::min( int a, int b, int c ) { 

  int low ; 

  low = a ; 
  if( low < b && low < c  ) return low ; 

  low = b ;  
  if( low  < a && low < b ) return low ; 

  low = c ; 
  if( low < b && low < a ) return low ; 
} 

int Edist::OptDistance(){ 

  int i, j ; 

  for( i = maxCL ; i > -1 ; i--){ 
    if( i == maxCL ) cost = penalty( '-','-') ; 
    else  cost =  cost + penalty( '-', b[i] ) ; 
    opt[maxRL][i] = cost ;
  }
  
  for( i = maxRL ; i > -1 ; i--){
    if( i == maxRL ) cost = penalty( '-','-') ;
    else  cost =  cost + penalty( '-', b[i] ) ;
    opt[i][maxCL] = cost ;
  }
  
  for(i = maxCL - 1 ; i > -1 ; i--)
    for( j = maxRL - 1 ; i > -1 ; i-- ) 
      opt[i][j] = min { opt[i+1][j+1] + 0/1, opt[i+1][j] + 2, opt[i][j+1] + 2 } ; 

  return opt[0][0] ; 
} 

int Edist::Alignment(int i, int j ){ 
  // might do this iteratively  
  // need to edit code this implementation is incorrect. 

  if( i => maxCL || j => maxRL ) return 0 ;  
  if( opt[i][j] == opt[i+1][j+1] && x[i] == y[j] ){ 
    
    cout << x[i] << y[i]<< 0  ; 
    i++; j++ ; 
    return Alignment( i , j ) ; 
  }  
  if( opt[i][j] == opt[i+1][j+1] + 1 && x[i] != y[j] ){
    cout << x[i] <<  y[j] << 1 << endl ;
    i++ ; j++ ;
    return Alignment( i , j ) ; 
  } ;  
  if( opt[i][j] == opt[i+1][j] + 2 && x[i] != y[j] ){
    cout << x[i] << '-' << 2 << endl ;
    i++ ; 
    return Alignment( i , j ) ; 
  } ;
  if( opt[i][j] == opt[i][j+1] + 2 &&x[i] != y[j] ){
    cout << '-' << y[j] << 2 << endl ;
    j++ ; 
    return  Alignment( i , j ) ; 
  } ;  

} 
