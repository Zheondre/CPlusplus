all: PhotoMagic 

PhotoMagic: PhotoMagic.o LFSR.o
	g++ PhotoMagic.o LFSR.o -o PhotoMagic -lsfml-graphics -lsfml-window -lsfml-system 

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp 
	g++ -c PhotoMagic.cpp 

LFSR.o: LFSR.cpp LFSR.hpp 
	g++ -c LFSR.cpp
clean: rm *.o PhotoMagic *~
