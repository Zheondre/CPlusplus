all: GuitarHero

GuitarHero: GuitarHero.o GuitarString.o RingBuffer.o
	g++ GuitarHero.o RingBuffer.o GuitarString.o -o GuitarHero -lboost_unit_test_framework -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window -g

GuitarHero.o: GuitarHero.cpp GuitarString.hpp RingBuffer.hpp
	g++ -c GuitarHero.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window -g

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	g++ -c RingBuffer.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window -g

GuitarString.o: GuitarString.cpp GuitarString.hpp
	g++ -c GuitarString.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window -g

clean:	
	 rm *.o GuitarHero *~ a.out
