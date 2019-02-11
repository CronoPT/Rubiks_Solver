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
#include <vector>

using namespace std;

RubiksCube foo();

int main()
{   
    RubiksCube my_cube = foo();
    Cubing problem(my_cube);
    AStarSearch<RubiksCube> algorithm;
    vector<Action<RubiksCube>*> solution = algorithm.execute(&problem);

    for(Action<RubiksCube>* a : solution)
        cout << a << endl;

    cout << my_cube << endl;
}

RubiksCube foo()
{
    // front | bottom | right | left | top | back

    vector<char> aux = {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
    Face front_face(3, aux);
    
    aux = {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW};
    Face back_face(3, aux);

    aux = {GREEN, GREEN, ORANGE, GREEN, GREEN, ORANGE, GREEN, GREEN, ORANGE};
    Face right_face(3, aux);

    aux = {RED, BLUE, BLUE, RED, BLUE, BLUE, RED, BLUE, BLUE};
    Face left_face(3, aux);

    aux = {GREEN, GREEN, GREEN, RED, RED, RED, RED, RED, RED};
    Face top_face(3, aux);

    aux = {ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, BLUE, BLUE, BLUE};
    Face bottom_face(3, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(3, faces);
    
    return my_cube;
}