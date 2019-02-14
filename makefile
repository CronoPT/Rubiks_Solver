CFLAGS = -O -g
CC = g++

rubiksSolver: main.o Face.o RubiksCube.o AStarSearch.o
	$(CC) $(CFLAGS) -o rubiksSolver main.o Face.o RubiksCube.o AStarSearch.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Face.o: Face.h Face.cpp
	$(CC) $(CFLAGS) -c Face.cpp

RubiksCube.o: RubiksCube.h RubiksCube.cpp
	$(CC) $(CFLAGS) -c RubiksCube.cpp

AStarSearch.o: Search/AStarSearch.h Search/AStarSearch.cpp
	$(CC) $(CFLAGS) -c Search/AStarSearch.cpp

clean:
	rm *.o

