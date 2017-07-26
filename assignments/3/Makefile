all: project3

project3: user.o message.o main.o
	g++ -g -Wall -std=gnu++0x User.o Message.o main.o -o project3

user.o: User.cpp
	g++ -g -Wall -std=gnu++0x -c User.cpp

message.o: Message.cpp
	g++ -g -Wall -std=gnu++0x -c Message.cpp

main.o: main.cpp
	g++ -g -Wall -std=gnu++0x -c main.cpp

clean:
	rm *.o project3