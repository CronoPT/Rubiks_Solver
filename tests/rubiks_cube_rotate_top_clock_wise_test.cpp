#include "../src/face.h"
#include "../src/rubiks_cube.h"
#include <gtest/gtest.h>

class rubiks_cube_rotate_top_clock_wise_test: public testing::Test
{   
    protected:
    std::vector<char> _aux;
    std::vector<cube::face> _faces;
    cube::face _front;
    cube::face _bottom;
    cube::face _right;
    cube::face _left;
    cube::face _top;
    cube::face _back;
    cube::rubiks_cube _cube;
    cube::rubiks_cube _resulting_cube;
};

TEST_F(rubiks_cube_rotate_top_clock_wise_test, two_sided)
{
    _aux = {WHITE, GREEN, 
            RED  , WHITE};
    _front = cube::face(2, _aux);

    _aux = {BLUE  , RED, 
            YELLOW, GREEN};
    _bottom = cube::face(2, _aux);

    _aux = {RED , YELLOW, 
            BLUE, ORANGE};
    _right = cube::face(2, _aux);

    _aux = {GREEN, ORANGE, 
            RED  , YELLOW};
    _left = cube::face(2, _aux);

    _aux = {ORANGE, BLUE, 
            BLUE  , WHITE};
    _top = cube::face(2, _aux);

    _aux = {ORANGE, YELLOW, 
            WHITE , GREEN};
    _back = cube::face(2, _aux);

    _faces = {_front, _bottom, _right, _left, _top, _back};
    _cube  = cube::rubiks_cube(2, _faces);

    //------------

    _aux = {RED, YELLOW, 
            RED, WHITE};
    _front = cube::face(2, _aux);

    _aux = {BLUE  , RED, 
            YELLOW, GREEN};
    _bottom = cube::face(2, _aux);

    _aux = {ORANGE, YELLOW, 
            BLUE  , ORANGE};
    _right = cube::face(2, _aux);

    _aux = {WHITE, GREEN, 
            RED  , YELLOW};
    _left = cube::face(2, _aux);

    _aux = {BLUE , ORANGE, 
            WHITE, BLUE};
    _top = cube::face(2, _aux);

    _aux = {GREEN, ORANGE, 
            WHITE, GREEN};
    _back = cube::face(2, _aux);

    _faces = {_front, _bottom, _right, _left, _top, _back};
    _resulting_cube = cube::rubiks_cube(2, _faces);

    _cube.rotate_face_clock_wise(TOP, 1);

    ASSERT_EQ(_resulting_cube, _cube);
}

TEST_F(rubiks_cube_rotate_top_clock_wise_test, three_sided)
{
    _aux = {WHITE , GREEN , WHITE,
            BLUE  , WHITE , BLUE,
            YELLOW, YELLOW, BLUE};
    _front = cube::face(3, _aux);

    _aux = {RED  , GREEN , YELLOW,
            BLUE , RED   , ORANGE,
            WHITE, ORANGE, RED};
    _bottom = cube::face(3, _aux);

    _aux = {BLUE  , WHITE, RED,
            YELLOW, BLUE , GREEN,
            ORANGE, GREEN, YELLOW};
    _right = cube::face(3, _aux);

    _aux = {GREEN , YELLOW, GREEN,
            ORANGE, GREEN , RED,
            RED   , WHITE , BLUE};
    _left = cube::face(3, _aux);

    _aux = {ORANGE, BLUE  , GREEN,
            RED   , ORANGE, RED,
            ORANGE, RED   , ORANGE};
    _top = cube::face(3, _aux);

    _aux = {WHITE, ORANGE, YELLOW,
            WHITE, YELLOW, YELLOW,
            GREEN, WHITE , BLUE};
    _back = cube::face(3, _aux);

    _faces = {_front, _bottom, _right, _left, _top, _back};
    _cube  = cube::rubiks_cube(3, _faces);

    //------------

    _aux = {BLUE  , WHITE , RED,
            BLUE  , WHITE , BLUE,
            YELLOW, YELLOW, BLUE};
    _front = cube::face(3, _aux);

    _aux = {RED  , GREEN , YELLOW,
            BLUE , RED   , ORANGE,
            WHITE, ORANGE, RED};
    _bottom = cube::face(3, _aux);

    _aux = {WHITE , ORANGE, YELLOW,
            YELLOW, BLUE  , GREEN,
            ORANGE, GREEN , YELLOW};
    _right = cube::face(3, _aux);

    _aux = {WHITE , GREEN, WHITE,
            ORANGE, GREEN, RED,
            RED   , WHITE, BLUE};
    _left = cube::face(3, _aux);

    _aux = {ORANGE, RED   , ORANGE,
            RED   , ORANGE, BLUE,
            ORANGE, RED   , GREEN};
    _top = cube::face(3, _aux);

    _aux = {GREEN, YELLOW, GREEN,
            WHITE, YELLOW, YELLOW,
            GREEN, WHITE , BLUE};
    _back = cube::face(3, _aux);

    _faces = {_front, _bottom, _right, _left, _top, _back};
    _resulting_cube  = cube::rubiks_cube(3, _faces);

    _cube.rotate_face_clock_wise(TOP, 1);

    ASSERT_EQ(_resulting_cube, _cube);
}
