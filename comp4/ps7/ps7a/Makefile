all: ps7a

ps7a: main.o
	g++ main.cpp -o ps7a -lboost_unit_test_framework -lboost_regex -g

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lboost_regex -g

clean:
	rm *.o ps7a *~
