#include <iostream> 
#include <string>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <vector>

void GS::Pluck() {
  if(j->isEmpty())
    throw
      std::runtime_error("Can't pluck, empty buffer.");
  
  int i, sc; Int16 ran;
  sc = _capacity; 
  for ( i = 0 ; i < sc; i++)
    _j->dequeue();
  for ( i = 0 ; i < sc; i++ ) {
    ran = (Int16)((rand() % .10) - .5);
    _j->enqueue(ran);
  }
}

void GS::Tic() {
  if(_j->isEmpty())
    throw
      std::runtime_error("Can't tic, empty buffer."); 
  double num1, num2, result;
  num1 = _j->dequeue();
  num2 = _j->peek();
  result = .996*.5*(num1 + num2);
  for( i = 0 ; i < _size - 1; i++)
    _j->enqueue(_j->dequeue());
  _j->enqueue(result);
  _ticCount++;
}

Int16 GS::Sample() {
  return _j->peek();
}

int GS::Time() {
  return _ticCount;
}
