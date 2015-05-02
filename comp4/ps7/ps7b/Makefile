all: ps7b

ps7b: main.o
	g++ main.o -o ps7b -lboost_unit_test_framework -lboost_regex -g

main.o: main.cpp Services.hpp
	g++ -c main.cpp Services.hpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lboost_regex -g

clean:
	rm *.o ps7b *~ *.gch
