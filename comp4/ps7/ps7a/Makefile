all: TextGenerator

TextGenerator: TextGenerator.o MarkovModel.o
	g++ TextGenerator.o MarkovModel.o -o TextGenerator -lboost_unit_test_framework -g

TextGenerator.o: TextGenerator.cpp MarkovModel.hpp
	g++ -c TextGenerator.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -g

MarkovModel.o: MarkovModel.cpp MarkovModel.hpp
	g++ -c MarkovModel.cpp -Wall -Werror -ansi -pedantic -lboost_unit_test_framework -g

clean:
	rm *.o TextGenerator *~
