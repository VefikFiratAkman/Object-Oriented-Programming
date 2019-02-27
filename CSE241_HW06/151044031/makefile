all: hello

hello: main.o GTUSet.o  GTUMap.o  
	g++ GTUSet.o GTUMap.o main.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

GTUSet.o: GTUSet.cpp 
	g++ -std=c++11 -c GTUSet.cpp

GTUMap.o: GTUMap.cpp 
	g++ -std=c++11 -c GTUMap.cpp

clean:
	rm *.o exe
