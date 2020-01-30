#include "../src/face.h"
#include "../src/face.cpp"
#include <gtest/gtest.h>

class face_constructor_test: public testing::Test
{   
    protected:
    std::vector<char> _aux;
    cube::face _face; 
};

TEST_F(face_constructor_test, two_sided_test_same_color)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);

    ASSERT_EQ(2, _face.get_n());
    ASSERT_EQ((_aux = {RED, RED}), _face.get_column(0));
    ASSERT_EQ((_aux = {RED, RED}), _face.get_column(1));
    ASSERT_EQ((_aux = {RED, RED}), _face.get_line(0));
    ASSERT_EQ((_aux = {RED, RED}), _face.get_line(1));
    ASSERT_EQ(RED, _face.get_position_by_index(0));
    ASSERT_EQ(RED, _face.get_position_by_index(1));
    ASSERT_EQ(RED, _face.get_position_by_index(2));
    ASSERT_EQ(RED, _face.get_position_by_index(3));
    ASSERT_EQ(RED, _face.get_position(0, 0));
    ASSERT_EQ(RED, _face.get_position(0, 1));
    ASSERT_EQ(RED, _face.get_position(1, 0));
    ASSERT_EQ(RED, _face.get_position(1, 1));
}

TEST_F(face_constructor_test, three_sided_test_same_color)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);

    ASSERT_EQ(3, _face.get_n());
    ASSERT_EQ((_aux = {RED, RED, RED}), _face.get_column(0));
    ASSERT_EQ((_aux = {RED, RED, RED}), _face.get_column(1));
    ASSERT_EQ((_aux = {RED, RED, RED}), _face.get_column(2));
    ASSERT_EQ((_aux = {RED, RED, RED}), _face.get_line(0));
    ASSERT_EQ((_aux = {RED, RED, RED}), _face.get_line(1));
    ASSERT_EQ((_aux = {RED, RED, RED}), _face.get_line(2));
    ASSERT_EQ(RED, _face.get_position_by_index(0));
    ASSERT_EQ(RED, _face.get_position_by_index(1));
    ASSERT_EQ(RED, _face.get_position_by_index(2));
    ASSERT_EQ(RED, _face.get_position_by_index(3));
    ASSERT_EQ(RED, _face.get_position_by_index(4));
    ASSERT_EQ(RED, _face.get_position_by_index(5));
    ASSERT_EQ(RED, _face.get_position_by_index(6));
    ASSERT_EQ(RED, _face.get_position_by_index(7));
    ASSERT_EQ(RED, _face.get_position_by_index(8));
    ASSERT_EQ(RED, _face.get_position(0, 0));
    ASSERT_EQ(RED, _face.get_position(0, 1));
    ASSERT_EQ(RED, _face.get_position(0, 2));
    ASSERT_EQ(RED, _face.get_position(1, 0));
    ASSERT_EQ(RED, _face.get_position(1, 1));
    ASSERT_EQ(RED, _face.get_position(1, 2));
    ASSERT_EQ(RED, _face.get_position(2, 0));
    ASSERT_EQ(RED, _face.get_position(2, 1));
    ASSERT_EQ(RED, _face.get_position(2, 2));
}

TEST_F(face_constructor_test, two_sided_test_scrambled_color)
{
    _aux = {RED,   GREEN, 
            GREEN, BLUE };
    _face = cube::face(2, _aux);

    ASSERT_EQ(2, _face.get_n());
    ASSERT_EQ((_aux = {RED, GREEN}), _face.get_column(0));
    ASSERT_EQ((_aux = {GREEN, BLUE}), _face.get_column(1));
    ASSERT_EQ((_aux = {RED, GREEN}), _face.get_line(0));
    ASSERT_EQ((_aux = {GREEN, BLUE}), _face.get_line(1));
    ASSERT_EQ(RED  , _face.get_position_by_index(0));
    ASSERT_EQ(GREEN, _face.get_position_by_index(1));
    ASSERT_EQ(GREEN, _face.get_position_by_index(2));
    ASSERT_EQ(BLUE , _face.get_position_by_index(3));
    ASSERT_EQ(RED  , _face.get_position(0, 0));
    ASSERT_EQ(GREEN, _face.get_position(0, 1));
    ASSERT_EQ(GREEN, _face.get_position(1, 0));
    ASSERT_EQ(BLUE , _face.get_position(1, 1));
}

TEST_F(face_constructor_test, three_sided_test_scrambled_color)
{
    _aux = {YELLOW, GREEN , BLUE,
            ORANGE, RED   , GREEN,
            GREEN , YELLOW, ORANGE};
    _face = cube::face(3, _aux);

    ASSERT_EQ(3, _face.get_n());
    ASSERT_EQ((_aux = {YELLOW, ORANGE, GREEN}),  _face.get_column(0));
    ASSERT_EQ((_aux = {GREEN , RED   , YELLOW}), _face.get_column(1));
    ASSERT_EQ((_aux = {BLUE  , GREEN , ORANGE}), _face.get_column(2));
    ASSERT_EQ((_aux = {YELLOW, GREEN , BLUE}),   _face.get_line(0));
    ASSERT_EQ((_aux = {ORANGE, RED   , GREEN}),  _face.get_line(1));
    ASSERT_EQ((_aux = {GREEN , YELLOW, ORANGE}), _face.get_line(2));
    ASSERT_EQ(YELLOW, _face.get_position_by_index(0));
    ASSERT_EQ(GREEN , _face.get_position_by_index(1));
    ASSERT_EQ(BLUE  , _face.get_position_by_index(2));
    ASSERT_EQ(ORANGE, _face.get_position_by_index(3));
    ASSERT_EQ(RED   , _face.get_position_by_index(4));
    ASSERT_EQ(GREEN , _face.get_position_by_index(5));
    ASSERT_EQ(GREEN , _face.get_position_by_index(6));
    ASSERT_EQ(YELLOW, _face.get_position_by_index(7));
    ASSERT_EQ(ORANGE, _face.get_position_by_index(8));
    ASSERT_EQ(YELLOW, _face.get_position(0, 0));
    ASSERT_EQ(GREEN , _face.get_position(0, 1));
    ASSERT_EQ(BLUE  , _face.get_position(0, 2));
    ASSERT_EQ(ORANGE, _face.get_position(1, 0));
    ASSERT_EQ(RED   , _face.get_position(1, 1));
    ASSERT_EQ(GREEN , _face.get_position(1, 2));
    ASSERT_EQ(GREEN , _face.get_position(2, 0));
    ASSERT_EQ(YELLOW, _face.get_position(2, 1));
    ASSERT_EQ(ORANGE, _face.get_position(2, 2));
}