all: lab3

lab3: list.o main.o supplied.o
		g++ -Wall -std=gnu++0x list.o main.o supplied.o -o lab3

list.o: list.cpp
		g++ -Wall -std=gnu++0x -c list.cpp

main.o: main.cpp
		g++ -Wall -std=gnu++0x -c main.cpp

clean:
		rm list.o main.o lab3
