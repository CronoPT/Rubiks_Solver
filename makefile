CFLAGS = -O -g
CC = g++

rubiksSolver: main.o Face.o RubiksCube.o
	$(CC) $(CFLAGS) -o rubiksSolver main.o Face.o RubiksCube.o

main.o: main.cpp Search/AStarSearch.h
	$(CC) $(CFLAGS) -c main.cpp

Face.o: Face.h Face.cpp
	$(CC) $(CFLAGS) -c Face.cpp

RubiksCube.o: RubiksCube.h RubiksCube.cpp
	$(CC) $(CFLAGS) -c RubiksCube.cpp

clean:
	rm *.o

