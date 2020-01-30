#include "../src/face.h"
#include <gtest/gtest.h>

class face_rotate_clock_wise_test: public testing::Test
{   
    protected:
    std::vector<char> _aux;
    cube::face _face;
    cube::face _resulting_face;
};

TEST_F(face_rotate_clock_wise_test, two_sided_uniform_face)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);
    _resulting_face = cube::face(2, _aux);

    _face.rotate_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_clock_wise_test, two_sided_random_face_1)
{
    _aux = {WHITE, RED, 
            BLUE , GREEN};
    _face = cube::face(2, _aux);
    _aux = {BLUE , WHITE, 
            GREEN, RED};
    _resulting_face = cube::face(2, _aux);

    _face.rotate_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_clock_wise_test, two_sided_random_face_2)
{
    _aux = {YELLOW, RED, 
            GREEN , RED};
    _face = cube::face(2, _aux);
    _aux = {GREEN, YELLOW, 
            RED  , RED};
    _resulting_face = cube::face(2, _aux);

    _face.rotate_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_clock_wise_test, three_sided_uniform_face)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);
    _resulting_face = cube::face(3, _aux);

    _face.rotate_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_clock_wise_test, three_sided_random_face_1)
{
    _aux = {BLUE  , ORANGE, RED,
            ORANGE, RED   , WHITE,
            YELLOW, GREEN , BLUE};
    _face = cube::face(3, _aux);
    _aux = {YELLOW, ORANGE, BLUE,
            GREEN , RED   , ORANGE,
            BLUE  , WHITE , RED};
    _resulting_face = cube::face(3, _aux);

    _face.rotate_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_clock_wise_test, three_sided_random_face_2)
{
    _aux = {RED   , BLUE  , YELLOW,
            YELLOW, ORANGE, GREEN,
            ORANGE, RED   , WHITE};
    _face = cube::face(3, _aux);
    _aux = {ORANGE, YELLOW, RED,
            RED   , ORANGE, BLUE,
            WHITE , GREEN , YELLOW};
    _resulting_face = cube::face(3, _aux);

    _face.rotate_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}
