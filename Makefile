# makefile for Date Manager code
# File done by Alexander Blake and all parts involving dateManager done by Lucas Larocco.

all: dateCalc

test: date_test
	./date_test

dateManager.o: dateManager.h dateManager.cpp
	g++ -std=c++14 -Wall -c dateManager.cpp

date_test.o: dateManager.h date_test.cpp
	g++ -std=c++14 -Wall -c date_test.cpp

main.o: dateManager.h main.cpp
	g++ -std=c++14 -Wall -c main.cpp

dateCalc: dateManager.o main.o
	g++ -std=c++14 -Wall dateManager.o main.o -o dateCalc

date_test: dateManager.o date_test.o
	g++ -pthread -std=c++14 -Wall dateManager.o date_test.o -lgtest_main -lgtest -lpthread -o date_test

clean:
	rm -f *.o dateManager
