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

#include "Face.h"
#include "RubiksCube.h"
#include "Cubing.h"
#include "Search/Action.h"

/*
    Including both the .cpp and .h files
because of the linking problem between 
those files, since they are relative
to a template class 
*/
#include "Search/AStarSearch.h"
#include "Search/AStarSearch.cpp"

#include "CubeActions/RotateBackClockWise.h"
#include "CubeActions/RotateBackCounterClockWise.h"
#include "CubeActions/RotateFrontClockWise.h"
#include "CubeActions/RotateFrontCounterClockWise.h"
#include "CubeActions/RotateTopClockWise.h"
#include "CubeActions/RotateTopCounterClockWise.h"
#include "CubeActions/RotateBottomClockWise.h"
#include "CubeActions/RotateBottomCounterClockWise.h"
#include "CubeActions/RotateRightClockWise.h"
#include "CubeActions/RotateRightCounterClockWise.h"
#include "CubeActions/RotateLeftClockWise.h"
#include "CubeActions/RotateLeftCounterClockWise.h"

#include <vector>
#include <memory>

using namespace std;

RubiksCube foo();
RubiksCube doneCube();

int main()
{   
       RubiksCube my_cube = foo();
       
       //my_cube.rotateFaceCounterClockWise(TOP, 1);
       Cubing problem(my_cube);
       AStarSearch<RubiksCube> algorithm;
       vector<shared_ptr<Action<RubiksCube>>> solution = algorithm.execute(&problem);

       cout << "SOLUTION:" << endl;

       for(shared_ptr<Action<RubiksCube>> a : solution)
       {
              problem.printAction(a);
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

    vector<char> aux = {GREEN, ORANGE, ORANGE,
                        GREEN, WHITE, BLUE, 
                        WHITE, WHITE, BLUE};
    Face front_face(3, aux);
    
    aux = {BLUE, BLUE, BLUE, 
           RED, YELLOW, YELLOW, 
           RED, GREEN, GREEN};
    Face back_face(3, aux);

    aux = {GREEN, YELLOW, YELLOW, 
           ORANGE, ORANGE, GREEN, 
           ORANGE, ORANGE, GREEN};
    Face right_face(3, aux);

    aux = {WHITE, RED, WHITE, 
           BLUE, RED, WHITE, 
           YELLOW, RED, BLUE};
    Face left_face(3, aux);

    aux = {RED, RED, RED, 
           YELLOW, GREEN, GREEN,
           RED, WHITE, WHITE};
    Face top_face(3, aux);

    aux = {ORANGE, BLUE, YELLOW, 
           WHITE, BLUE, YELLOW, 
           ORANGE, ORANGE, YELLOW};
    Face bottom_face(3, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(3, faces);
    
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