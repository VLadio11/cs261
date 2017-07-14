all: chickenfoot

chickenfoot: bone.o boneyard.o player.o field.o game.o chickenfoot.o
	g++ -g -Wall -std=gnu++0x Bone.o Boneyard.o Player.o Field.o Game.o ChickenFoot.o -o chickenfoot

bone.o: Bone.cpp
	g++ -g -Wall -std=gnu++0x -c Bone.cpp

boneyard.o: Boneyard.cpp
	g++ -g -Wall -std=gnu++0x -c Boneyard.cpp

player.o: Player.cpp
	g++ -g -Wall -std=gnu++0x -c Player.cpp

field.o: Field.cpp
	g++ -g -Wall -std=gnu++0x -c Field.cpp

game.o: Game.cpp
	g++ -g -Wall -std=gnu++0x -c Game.cpp

chickenfoot.o: ChickenFoot.cpp
	g++ -g -Wall -std=gnu++0x -c ChickenFoot.cpp

clean:
	rm *.o chickenfoot