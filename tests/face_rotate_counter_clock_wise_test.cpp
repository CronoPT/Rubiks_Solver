#include "../src/face.h"
#include <gtest/gtest.h>

class face_rotate_counter_clock_wise_test: public testing::Test
{   
    protected:
    std::vector<char> _aux;
    cube::face _face;
    cube::face _resulting_face;
};

TEST_F(face_rotate_counter_clock_wise_test, two_sided_uniform_face)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);
    _resulting_face = cube::face(2, _aux);

    _face.rotate_counter_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_counter_clock_wise_test, two_sided_random_face_1)
{
    _aux = {WHITE, RED, 
            BLUE , GREEN};
    _face = cube::face(2, _aux);
    _aux = {RED  , GREEN, 
            WHITE, BLUE};
    _resulting_face = cube::face(2, _aux);

    _face.rotate_counter_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_counter_clock_wise_test, two_sided_random_face_2)
{
    _aux = {YELLOW, RED, 
            GREEN , RED};
    _face = cube::face(2, _aux);
    _aux = {RED   , RED, 
            YELLOW, GREEN};
    _resulting_face = cube::face(2, _aux);

    _face.rotate_counter_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_counter_clock_wise_test, three_sided_uniform_face)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);
    _resulting_face = cube::face(3, _aux);

    _face.rotate_counter_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_counter_clock_wise_test, three_sided_random_face_1)
{
    _aux = {BLUE  , ORANGE, RED,
            ORANGE, RED   , WHITE,
            YELLOW, GREEN , BLUE};
    _face = cube::face(3, _aux);
    _aux = {RED   , WHITE , BLUE,
            ORANGE, RED   , GREEN,
            BLUE  , ORANGE, YELLOW};
    _resulting_face = cube::face(3, _aux);

    _face.rotate_counter_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}

TEST_F(face_rotate_counter_clock_wise_test, three_sided_random_face_2)
{
    _aux = {RED   , BLUE  , YELLOW,
            YELLOW, ORANGE, GREEN,
            ORANGE, RED   , WHITE};
    _face = cube::face(3, _aux);
    _aux = {YELLOW, GREEN , WHITE,
            BLUE  , ORANGE, RED,
            RED   , YELLOW, ORANGE};
    _resulting_face = cube::face(3, _aux);

    _face.rotate_counter_clock_wise();

    ASSERT_EQ(_resulting_face, _face);
}