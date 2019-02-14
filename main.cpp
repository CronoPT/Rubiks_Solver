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
#include "Search/AStarSearch.h"

#include "CubeActions/rotateBackClockWise.h"
#include "CubeActions/rotateBackCounterClockWise.h"
#include "CubeActions/rotateFrontClockWise.h"
#include "CubeActions/rotateFrontCounterClockWise.h"
#include "CubeActions/rotateTopClockWise.h"
#include "CubeActions/rotateTopCounterClockWise.h"
#include "CubeActions/rotateBottomClockWise.h"
#include "CubeActions/rotateBottomCounterClockWise.h"
#include "CubeActions/rotateRightClockWise.h"
#include "CubeActions/rotateRightCounterClockWise.h"
#include "CubeActions/rotateLeftClockWise.h"
#include "CubeActions/rotateLeftCounterClockWise.h"

#include <vector>
#include <memory>

using namespace std;

RubiksCube foo();

int main()
{   
    RubiksCube my_cube = foo();
    Cubing problem(my_cube);
    AStarSearch<RubiksCube> algorithm;
    vector<shared_ptr<Action<RubiksCube>>> solution = algorithm.execute(&problem);

    cout << "SOLUTION:" << endl;

    for(shared_ptr<Action<RubiksCube>> a : solution)
    {
        problem.printAction(a);
    }
}

RubiksCube foo()
{
    // front | bottom | right | left | top | back

    vector<char> aux = {BLUE, WHITE, BLUE, WHITE, WHITE, GREEN, GREEN, GREEN, ORANGE};
    Face front_face(3, aux);
    
    aux = {RED, YELLOW, RED, YELLOW, YELLOW, BLUE, ORANGE, BLUE, GREEN};
    Face back_face(3, aux);

    aux = {YELLOW, ORANGE, WHITE, ORANGE, RED, BLUE, BLUE, GREEN, GREEN};
    Face right_face(3, aux);

    aux = {WHITE, BLUE, YELLOW, ORANGE, ORANGE, RED, RED, RED, ORANGE};
    Face left_face(3, aux);

    aux = {GREEN, GREEN, BLUE, WHITE, BLUE, YELLOW, RED, ORANGE, ORANGE};
    Face top_face(3, aux);

    aux = {YELLOW, RED, WHITE, YELLOW, GREEN, WHITE, YELLOW, RED, WHITE};
    Face bottom_face(3, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(3, faces);
    
    return my_cube;
}