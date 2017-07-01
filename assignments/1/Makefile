all: chickenfoot

chickenfoot: bone.o boneyard.o player.o field.o chickenfoot.o
	g++ -Wall -std=gnu++0x Bone.o Boneyard.o Player.o Field.o ChickenFoot.o -o chickenfoot

bone.o: Bone.cpp
	g++ -Wall -std=gnu++0x -c Bone.cpp

boneyard.o: Boneyard.cpp
	g++ -Wall -std=gnu++0x -c Boneyard.cpp

player.o: Player.cpp
	g++ -Wall -std=gnu++0x -c Player.cpp

field.o: Field.cpp
	g++ -Wall -std=gnu++0x -c Field.cpp

chickenfoot.o: ChickenFoot.cpp
	g++ -Wall -std=gnu++0x -c ChickenFoot.cpp

clean:
	rm *.o chickenfoot