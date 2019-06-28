CFLAGS = -O -g
CC = g++

rubiksSolver: main.o face.o rubiks_cube.o a_star_search.o
	$(CC) $(CFLAGS) -o rubiksSolver main.o face.o rubiks_cube.o a_star_search.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

face.o: face.h face.cpp
	$(CC) $(CFLAGS) -c face.cpp

rubiks_cube.o: rubiks_cube.h rubiks_cube.cpp
	$(CC) $(CFLAGS) -c rubiks_cube.cpp

a_star_search.o: search/a_star_search.h search/a_star_search.cpp search/node.h search/action.h search/problem.h
	$(CC) $(CFLAGS) -c search/a_star_search.cpp

clean:
	rm *.o

