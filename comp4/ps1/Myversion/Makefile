all: original sierpinski

original: main.o func.o
	g++ main.o func.o -o original -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

func.o: func.cpp
	g++ -c func.cpp -Wall -Werror -ansi -pedantic

sierpinski: smain.o sierpinski.o
	g++ smain.o sierpinski.o -o sierpinski -lsfml-graphics -lsfml-window -lsfml-system

smain.o: smain.cpp
	g++ -c smain.cpp -Wall -Werror -ansi -pedantic

sierpinski.o:
	g++ -c sierpinski.cpp -Wall -Werror -ansi -pedantic

clean:
	rm *.o original sierpinski *~