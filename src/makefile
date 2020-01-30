CFLAGS = -O -g -std=c++17
CC = g++

rubiks_solver: main.o face.o rubiks_cube.o a_star_search.o cubing.o
	$(CC) $(CFLAGS) -o rubiks_solver main.o face.o rubiks_cube.o a_star_search.o cubing.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

face.o: face.h face.cpp
	$(CC) $(CFLAGS) -c face.cpp

rubiks_cube.o: rubiks_cube.h rubiks_cube.cpp
	$(CC) $(CFLAGS) -c rubiks_cube.cpp

cubing.o: cubing.h cubing.cpp
	$(CC) $(CFLAGS) -c cubing.cpp

a_star_search.o: search/a_star_search.h search/a_star_search.cpp search/node.h search/action.h search/problem.h
	$(CC) $(CFLAGS) -c search/a_star_search.cpp

clean:
	rm *.o rubiks_solver

