all: lab2

lab2: arr.o main.o
	g++ -Wall -std=gnu++0x arr.o main.o supplied.o -o lab2

arr.o: arr.cpp
	g++ -Wall -std=gnu++0x -c arr.cpp

main.o: main.cpp
	g++ -Wall -std=gnu++0x -c main.cpp

clean:
	rm arr.o main.o lab2