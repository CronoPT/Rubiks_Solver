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

using namespace std;

RubiksCube foo();

int main()
{   
    RubiksCube my_cube = foo();
    Cubing problem(my_cube);
    AStarSearch<RubiksCube> algorithm;
    vector<Action<RubiksCube>*> solution = algorithm.execute(&problem);

    cout << "SOLUTION:" << endl;

    for(Action<RubiksCube>* a : solution)
    {
        problem.printAction(a);
    }

}

RubiksCube foo()
{
    // front | bottom | right | left | top | back

    vector<char> aux = {GREEN, WHITE, RED, ORANGE, WHITE, GREEN, YELLOW, GREEN, ORANGE};
    Face front_face(3, aux);
    
    aux = {WHITE, BLUE, GREEN, BLUE, YELLOW, WHITE, YELLOW, RED, YELLOW};
    Face back_face(3, aux);

    aux = {BLUE, ORANGE, RED, WHITE, RED, WHITE, BLUE, GREEN, BLUE};
    Face right_face(3, aux);

    aux = {ORANGE, YELLOW, ORANGE, RED, ORANGE, YELLOW, BLUE, BLUE, RED};
    Face left_face(3, aux);

    aux = {YELLOW, ORANGE, GREEN, BLUE, BLUE, GREEN, WHITE, ORANGE, WHITE};
    Face top_face(3, aux);

    aux = {GREEN, RED, WHITE, RED, GREEN, YELLOW, ORANGE, YELLOW, RED};
    Face bottom_face(3, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(3, faces);
    
    return my_cube;
}