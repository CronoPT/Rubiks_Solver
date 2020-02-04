#include "../src/face.h"
#include "../src/rubiks_cube.h"
#include <gtest/gtest.h>

class rubiks_cube_solved_test: public testing::Test
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
};

TEST_F(rubiks_cube_solved_test, two_sided_not_solved)
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

    ASSERT_FALSE(_cube.solved());
}

TEST_F(rubiks_cube_solved_test, two_sided_solved)
{
    _aux = {WHITE, WHITE, 
            WHITE, WHITE};
    _front = cube::face(2, _aux);

    _aux = {GREEN, GREEN, 
            GREEN, GREEN};
    _bottom = cube::face(2, _aux);

    _aux = {RED, RED, 
            RED, RED};
    _right = cube::face(2, _aux);

    _aux = {ORANGE, ORANGE, 
            ORANGE, ORANGE};
    _left = cube::face(2, _aux);

    _aux = {BLUE, BLUE, 
            BLUE, BLUE};
    _top = cube::face(2, _aux);

    _aux = {YELLOW, YELLOW, 
            YELLOW, YELLOW};
    _back = cube::face(2, _aux);

    _faces = {_front, _bottom, _right, _left, _top, _back};
    _cube  = cube::rubiks_cube(2, _faces);

    ASSERT_TRUE(_cube.solved());
}

TEST_F(rubiks_cube_solved_test, three_sided_not_solved)
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

    ASSERT_FALSE(_cube.solved());
}

TEST_F(rubiks_cube_solved_test, three_sided_solved)
{
    _aux = {WHITE, WHITE, WHITE,
            WHITE, WHITE, WHITE,
            WHITE, WHITE, WHITE};
    _front = cube::face(3, _aux);

    _aux = {ORANGE, ORANGE, ORANGE,
            ORANGE, ORANGE, ORANGE,
            ORANGE, ORANGE, ORANGE};
    _bottom = cube::face(3, _aux);

    _aux = {GREEN, GREEN, GREEN,
            GREEN, GREEN, GREEN,
            GREEN, GREEN, GREEN};
    _right = cube::face(3, _aux);

    _aux = {BLUE, BLUE, BLUE,
            BLUE, BLUE, BLUE,
            BLUE, BLUE, BLUE};
    _left = cube::face(3, _aux);

    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _top = cube::face(3, _aux);

    _aux = {YELLOW, YELLOW, YELLOW,
            YELLOW, YELLOW, YELLOW,
            YELLOW, YELLOW, YELLOW};
    _back = cube::face(3, _aux);

    _faces = {_front, _bottom, _right, _left, _top, _back};
    _cube  = cube::rubiks_cube(3, _faces);

    ASSERT_TRUE(_cube.solved());
}