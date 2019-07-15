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

cubing::rubiks_cube foo();
cubing::rubiks_cube done_cube();

int main()
{   
       cubing::rubiks_cube my_cube = foo();

       cubing::cubing problem(my_cube);
       search::a_star_search<cubing::rubiks_cube> algorithm;
       std::vector<std::shared_ptr<search::action<cubing::rubiks_cube>>> solution = algorithm.execute(&problem);

       std::cout << "SOLUTION:" << std::endl;

       for(std::shared_ptr<search::action<cubing::rubiks_cube>> a : solution)
       {
              std::cout << *a << std::endl;
       }
    

    // RubiksCube my = doneCube();
    // my.rotateFaceClockWise(BOTTOM, 1);
    // cout << my << endl;

    // RubiksCube my_2 = doneCube();
    // my_2.rotateFaceCounterClockWise(BOTTOM, 1);
    // cout << my_2 << endl;
}

cubing::rubiks_cube foo()
{
	// front | bottom | right | left | top | back

    std::vector<char> aux = {WHITE,  YELLOW,
                        YELLOW, WHITE };
    cubing::cube_face front_face(2, aux);
    
    aux = {ORANGE, BLUE, 
           RED,    RED };
    cubing::cube_face back_face(2, aux);

    aux = {RED,   GREEN, 
           GREEN, BLUE };
    cubing::cube_face right_face(2, aux);

    aux = {RED,   ORANGE, 
           GREEN, ORANGE };
    cubing::cube_face left_face(2, aux);

    aux = {YELLOW, YELLOW, 
           BLUE,   GREEN };
    cubing::cube_face top_face(2, aux);

    aux = {BLUE, ORANGE, 
           WHITE, WHITE};
    cubing::cube_face bottom_face(2, aux);

    std::vector<cubing::cube_face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    cubing::rubiks_cube my_cube(2, faces);
    
    return my_cube;
}

cubing::rubiks_cube done_cube()
{
	// front | bottom | right | left | top | back

    std::vector<char> aux = {WHITE, WHITE, WHITE,
                        WHITE, WHITE, WHITE, 
                        WHITE, WHITE, WHITE};
    cubing::cube_face front_face(3, aux);
    
    aux = {YELLOW, YELLOW, YELLOW, 
           YELLOW, YELLOW, YELLOW, 
           YELLOW, YELLOW, YELLOW};
    cubing::cube_face back_face(3, aux);

    aux = {ORANGE, ORANGE, ORANGE, 
           ORANGE, ORANGE, ORANGE, 
           ORANGE, ORANGE, ORANGE};
    cubing::cube_face right_face(3, aux);

    aux = {RED, RED, RED, 
           RED, RED, RED, 
           RED, RED, RED};
    cubing::cube_face left_face(3, aux);

    aux = {GREEN, GREEN, GREEN, 
           GREEN, GREEN, GREEN,
           GREEN, GREEN, GREEN};
    cubing::cube_face top_face(3, aux);

    aux = {BLUE, BLUE, BLUE, 
           BLUE, BLUE, BLUE, 
           BLUE, BLUE, BLUE};
    cubing::cube_face bottom_face(3, aux);

    std::vector<cubing::cube_face> faces = {front_face, bottom_face, right_face, left_face, top_face, back_face};
    cubing::rubiks_cube my_cube(3, faces);
    
    return my_cube;
}
