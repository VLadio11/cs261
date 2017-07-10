all: lab4

lab4: clist.o main.o supplied.o
			g++ -Wall -std=gnu++0x clist.o main.o supplied.o -o lab4

clist.o: clist.cpp
			g++ -Wall -std=gnu++0x -c clist.cpp

main.o: main.cpp
			g++ -Wall -std=gnu++0x -c main.cpp

clean:
			rm clist.o main.o lab4
