# makefile for triangle code
# Alexander Blake

all: dateCalc

#test: triangle_test
#	./triangle_test

dateManager.o: dateManager.h dateManager.cpp
	g++ -std=c++14 -Wall -c dateManager.cpp

futureDate.o: futureDate.h futureDate.cpp
	g++ -std=c++14 -Wall -c futureDate.cpp

#triangle_test.o: triangle.h triangle_test.cpp
#	g++ -std=c++14 -Wall -c triangle_test.cpp

main.o: dateManager.h futureDate.h main.cpp
	g++ -std=c++14 -Wall -c main.cpp

dateCalc: dateManager.o futureDate.o main.o
	g++ -std=c++14 -Wall dateManager.o futureDate.o main.o -o dateCalc

#triangle_test: triangle.o triangle_test.o
#	g++ -pthread -std=c++14 -Wall triangle.o triangle_test.o -lgtest_main -lgtest -lpthread -o triangle_test

clean:
	rm -f *.o dateCalc
