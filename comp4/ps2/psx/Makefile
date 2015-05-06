all: ps2a

ps2a: test.o LFSR.o
	g++ test.o LFSR.o -o ps2a -lboost_unit_test_framework

ps2a.o: test.cpp LFSR.hpp
	g++ -c test.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -g

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -g

clean: rm *.o ps2a *~
