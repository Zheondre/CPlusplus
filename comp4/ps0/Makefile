all: ps0

ps0: main.o 
	g++ main.o -o ps0 -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic

clean:
	rm *.o ps0 *~ *# 
