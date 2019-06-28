/*====================================================================
|     ,.  ,.                                                         |
|     ||  ||                                                         |
|    .''--''.                                                        |
|   : (.)(.) :               CronoPT - Vasco Silva                   |
|  .'        '.                                                      |
|  :          :                                                      |
|  :          :                                                      |
|  :          :                                                      |
|   '-m----m-'                                                       |
====================================================================*/

#include "Cubing.h"

/*
    Including both the .cpp and .h files
because of the linking problem between 
those files, since they are relative
to a template class 
*/
#include "Search/AStarSearch.h"
#include "Search/AStarSearch.cpp"

using namespace std;

RubiksCube foo();
RubiksCube doneCube();

int main()
{   
       RubiksCube my_cube = foo();

       Cubing problem(my_cube);
       AStarSearch<RubiksCube> algorithm;
       vector<shared_ptr<Action<RubiksCube>>> solution = algorithm.execute(&problem);

       cout << "SOLUTION:" << endl;

       for(shared_ptr<Action<RubiksCube>> a : solution)
       {
              cout << *a << endl;
       }
    

    // RubiksCube my = doneCube();
    // my.rotateFaceClockWise(BOTTOM, 1);
    // cout << my << endl;

    // RubiksCube my_2 = doneCube();
    // my_2.rotateFaceCounterClockWise(BOTTOM, 1);
    // cout << my_2 << endl;
}

RubiksCube foo()
{
	// front | bottom | right | left | top | back

    vector<char> aux = {WHITE,  YELLOW,
                        YELLOW, WHITE };
    Face front_face(2, aux);
    
    aux = {ORANGE, BLUE, 
           RED,    RED };
    Face back_face(2, aux);

    aux = {RED,   GREEN, 
           GREEN, BLUE };
    Face right_face(2, aux);

    aux = {RED,   ORANGE, 
           GREEN, ORANGE };
    Face left_face(2, aux);

    aux = {YELLOW, YELLOW, 
           BLUE,   GREEN };
    Face top_face(2, aux);

    aux = {BLUE, ORANGE, 
           WHITE, WHITE};
    Face bottom_face(2, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(2, faces);
    
    return my_cube;
}

RubiksCube doneCube()
{
	// front | bottom | right | left | top | back

    vector<char> aux = {WHITE, WHITE, WHITE,
                        WHITE, WHITE, WHITE, 
                        WHITE, WHITE, WHITE};
    Face front_face(3, aux);
    
    aux = {YELLOW, YELLOW, YELLOW, 
           YELLOW, YELLOW, YELLOW, 
           YELLOW, YELLOW, YELLOW};
    Face back_face(3, aux);

    aux = {ORANGE, ORANGE, ORANGE, 
           ORANGE, ORANGE, ORANGE, 
           ORANGE, ORANGE, ORANGE};
    Face right_face(3, aux);

    aux = {RED, RED, RED, 
           RED, RED, RED, 
           RED, RED, RED};
    Face left_face(3, aux);

    aux = {GREEN, GREEN, GREEN, 
           GREEN, GREEN, GREEN,
           GREEN, GREEN, GREEN};
    Face top_face(3, aux);

    aux = {BLUE, BLUE, BLUE, 
           BLUE, BLUE, BLUE, 
           BLUE, BLUE, BLUE};
    Face bottom_face(3, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(3, faces);
    
    return my_cube;
}
