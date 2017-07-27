all: project3

project3: user.o message.o facebookmessage.o emailmessage.o textmessage.o inbox.o main.o
	g++ -g -Wall -std=gnu++0x User.o Message.o FacebookMessage.o EmailMessage.o TextMessage.o Inbox.o main.o -o project3

user.o: User.cpp
	g++ -g -Wall -std=gnu++0x -c User.cpp

message.o: Message.cpp
	g++ -g -Wall -std=gnu++0x -c Message.cpp

facebookmessage.o: FacebookMessage.cpp
	g++ -g -Wall -std=gnu++0x -c FacebookMessage.cpp

emailmessage.o: EmailMessage.cpp
	g++ -g -Wall -std=gnu++0x -c EmailMessage.cpp

textmessage.o: TextMessage.cpp
	g++ -g -Wall -std=gnu++0x -c TextMessage.cpp

inbox.o: Inbox.cpp
	g++ -g -Wall -std=gnu++0x -c Inbox.cpp

main.o: main.cpp
	g++ -g -Wall -std=gnu++0x -c main.cpp

clean:
	rm *.o project3