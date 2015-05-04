all: ps7b

ps7b: main.o Services.o
	g++ main.o Services.o -o ps7b -lboost_unit_test_framework -lboost_regex -g

ps7b.o: main.cpp Services.hpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lboost_regex -g

Services.o: Services.cpp Services.hpp
	g++ -c Services.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lboost_regex -g


clean:
	rm *.o ps7b *~ *.gch
