
#include "Face.h"
#include "RubiksCube.h"
#include "CubeActions/rotateBackClockWise.h"
#include <vector>

using namespace std;

RubiksCube foo();

int main()
{   
    RubiksCube my_cube = foo();

    rotateBackClockWise action(1);

    RubiksCube other_cube = action.execute(my_cube);

    cout << my_cube << endl;
    cout << other_cube << endl;
    cout << action << endl;

}

RubiksCube foo(){
    // front | bottom | right | left | top | back

    vector<char> aux = {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
    Face front_face(3, aux);
    
    aux = {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW};
    Face back_face(3, aux);

    aux = {ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE};
    Face right_face(3, aux);

    aux = {RED, RED, RED, RED, RED, RED, RED, RED, RED};
    Face left_face(3, aux);

    aux = {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN};
    Face top_face(3, aux);

    aux = {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE};
    Face bottom_face(3, aux);

    vector<Face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    RubiksCube my_cube(3, faces);
    
    return my_cube;
}