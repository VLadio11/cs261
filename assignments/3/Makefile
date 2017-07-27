all: project3

project3: user.o message.o facebookmessage.o inbox.o main.o
	g++ -g -Wall -std=gnu++0x User.o Message.o FacebookMessage.o Inbox.o main.o -o project3

user.o: User.cpp
	g++ -g -Wall -std=gnu++0x -c User.cpp

message.o: Message.cpp
	g++ -g -Wall -std=gnu++0x -c Message.cpp

facebookmessage.o: FacebookMessage.cpp
	g++ -g -Wall -std=gnu++0x -c FacebookMessage.cpp

inbox.o: Inbox.cpp
	g++ -g -Wall -std=gnu++0x -c Inbox.cpp

main.o: main.cpp
	g++ -g -Wall -std=gnu++0x -c main.cpp

clean:
	rm *.o project3