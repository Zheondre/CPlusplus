all: ps5a

ps5a: test.o RingBuffer.o
	g++ test.o RingBuffer.o -o ps5a -lboost_unit_test_framework

ps5a.o: test.cpp RingBuffer.hpp
	g++ -c test.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -g

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	g++ -c RingBuffer.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -g

clean:
	 rm *.o ps5a *~
