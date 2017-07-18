all: lab5

lab5: dlist.o main.o supplied.o
			g++ -Wall -std=gnu++0x dlist.o main.o supplied.o -o lab5

dlist.o: dlist.cpp
			g++ -Wall -std=gnu++0x -c dlist.cpp

main.o: main.cpp
			g++ -Wall -std=gnu++0x -c main.cpp

clean:
			rm dlist.o main.o lab5
