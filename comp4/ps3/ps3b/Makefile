all: NBody 

NBody: main.o space.o mf.o
	g++ main.o space.o mf.o -o NBody -lsfml-graphics -lsfml-window -lsfml-system 

NBody.o: main.cpp space.hpp 
	g++ -c main.cpp -Wall -Werror -ansi -pedantic -g 

Space.o: space.cpp space.hpp 
	g++ -c space.cpp -Wall -Werror -ansi -pedantic -g 

mf.o: mf.cpp space.hpp 
	g++ -c mf.cpp -Wall -Werror -ansi -pedantic -g 

clean: 
	rm *.o NBody *~ *# *.gch
