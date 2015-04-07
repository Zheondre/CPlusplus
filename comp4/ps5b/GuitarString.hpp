#ifndef _GuitarString_
#define _GuitarString_ 

#include <iostream> 
#include <string>
#include <cstdlib>

class GS{
  RingBuffer *_j; int _size, _ticCount;
  
  public:
 
  explicit GS(int freq): {
    //use resize ?
    _size = ceiling((44100/freq)); 
    _j = new RingBuffer(_size);  
    _ticCount = 0;
     for ( int i = 0 ; i < _size; i++) 
       _j->enqueue(0) ; 
  }
  explicit GS( vector< Int16 > j ):{ 
    _size= j.size();
    _j = new RingBUffer(_size);
    _ticCount = 0;
    for ( int i = 0 ; i < _size; i++)
      _j->enqueue(j[i]);
  }
  ~GS(): {
    //make sure to free bytes for the pointer. 
    delete[] j;
  }
  void Pluck();
  int Time();
  void Tic();
  Int16 Sample();  
};
#endif
