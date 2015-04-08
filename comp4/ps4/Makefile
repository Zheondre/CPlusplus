all: ED 

ED: main.o a.o
	g++ main.o a.o -o ED -Wall -Werror -ansi -pedantic -lsfml-system -g

ED.o: main.cpp a.hpp 
	g++ -c main.cpp -g

a.o: a.cpp a.hpp 
	g++ -c a.cpp -g 

clean: rm *.o ED *~ 
