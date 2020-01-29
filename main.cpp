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

#include "cubing.h"

/*
    Including both the .cpp and .h files
because of the linking problem between 
those files, since they are relative
to a template class 
*/
#include "search/a_star_search.h"
#include "search/a_star_search.cpp"

using namespace std;
using namespace search;
using namespace cube;

rubiks_cube foo();
rubiks_cube doneCube();

int main()
{   
       rubiks_cube my_cube = foo();

       cubing problem(my_cube);
       a_star_search<rubiks_cube> algorithm;
       vector<shared_ptr<action<rubiks_cube>>> solution = algorithm.execute(&problem);

       cout << "SOLUTION:" << endl;

       for(shared_ptr<action<rubiks_cube>> a : solution)
       {
              cout << *a << endl;
       }
    

    // rubiks_cube my = doneCube();
    // my.rotatefaceClockWise(BOTTOM, 1);
    // cout << my << endl;

    // rubiks_cube my_2 = doneCube();
    // my_2.rotatefaceCounterClockWise(BOTTOM, 1);
    // cout << my_2 << endl;
}

rubiks_cube foo()
{
	// front | bottom | right | left | top | back

    vector<char> aux = {WHITE,  YELLOW,
                        YELLOW, WHITE };
    face front_face(2, aux);
    
    aux = {ORANGE, BLUE, 
           RED,    RED };
    face back_face(2, aux);

    aux = {RED,   GREEN, 
           GREEN, BLUE };
    face right_face(2, aux);

    aux = {RED,   ORANGE, 
           GREEN, ORANGE };
    face left_face(2, aux);

    aux = {YELLOW, YELLOW, 
           BLUE,   GREEN };
    face top_face(2, aux);

    aux = {BLUE, ORANGE, 
           WHITE, WHITE};
    face bottom_face(2, aux);

    vector<face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    rubiks_cube my_cube(2, faces);
    
    return my_cube;
}

rubiks_cube doneCube()
{
	// front | bottom | right | left | top | back

    vector<char> aux = {WHITE, WHITE, WHITE,
                        WHITE, WHITE, WHITE, 
                        WHITE, WHITE, WHITE};
    face front_face(3, aux);
    
    aux = {YELLOW, YELLOW, YELLOW, 
           YELLOW, YELLOW, YELLOW, 
           YELLOW, YELLOW, YELLOW};
    face back_face(3, aux);

    aux = {ORANGE, ORANGE, ORANGE, 
           ORANGE, ORANGE, ORANGE, 
           ORANGE, ORANGE, ORANGE};
    face right_face(3, aux);

    aux = {RED, RED, RED, 
           RED, RED, RED, 
           RED, RED, RED};
    face left_face(3, aux);

    aux = {GREEN, GREEN, GREEN, 
           GREEN, GREEN, GREEN,
           GREEN, GREEN, GREEN};
    face top_face(3, aux);

    aux = {BLUE, BLUE, BLUE, 
           BLUE, BLUE, BLUE, 
           BLUE, BLUE, BLUE};
    face bottom_face(3, aux);

    vector<face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    rubiks_cube my_cube(3, faces);
    
    return my_cube;
}
