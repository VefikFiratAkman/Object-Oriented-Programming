all: prog

prog: main.o ConnectFour.o
	g++  ConnectFour.o main.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ConnectFour.o: ConnectFour.cpp
	g++ -std=c++11 -c ConnectFour.cpp

clean:
	rm *.o exe
