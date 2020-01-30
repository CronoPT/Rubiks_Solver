#include "../src/face.h"
#include <gtest/gtest.h>

class face_setters_test: public testing::Test
{   
    protected:
    std::vector<char> _aux;
    cube::face _face;
};

TEST_F(face_setters_test, two_sided_straight_line_setter)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);

    _face.set_line(0, (_aux={BLUE, GREEN}));

    ASSERT_EQ((_aux = {BLUE, GREEN}), _face.get_line(0));
    ASSERT_EQ((_aux = {RED , RED})  , _face.get_line(1));
    ASSERT_EQ(BLUE , _face.get_position(0, 0));
    ASSERT_EQ(GREEN, _face.get_position(0, 1));
    ASSERT_EQ(RED  , _face.get_position(1, 0));
    ASSERT_EQ(RED  , _face.get_position(1, 1));
}

TEST_F(face_setters_test, three_sided_straight_line_setter)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);

    _face.set_line(0, (_aux={BLUE, GREEN, ORANGE}));

    ASSERT_EQ((_aux = {BLUE, GREEN, ORANGE}), _face.get_line(0));
    ASSERT_EQ((_aux = {RED , RED  , RED})   , _face.get_line(1));
    ASSERT_EQ((_aux = {RED , RED  , RED})   , _face.get_line(2));
    ASSERT_EQ(BLUE  , _face.get_position(0, 0));
    ASSERT_EQ(GREEN , _face.get_position(0, 1));
    ASSERT_EQ(ORANGE, _face.get_position(0, 2));
    ASSERT_EQ(RED   , _face.get_position(1, 0));
    ASSERT_EQ(RED   , _face.get_position(1, 1));
    ASSERT_EQ(RED   , _face.get_position(1, 2));
    ASSERT_EQ(RED   , _face.get_position(2, 0));
    ASSERT_EQ(RED   , _face.get_position(2, 1));
    ASSERT_EQ(RED   , _face.get_position(2, 2));
}

TEST_F(face_setters_test, two_sided_straight_column_setter)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);

    _face.set_column(0, (_aux={BLUE, GREEN}));

    ASSERT_EQ((_aux = {BLUE, GREEN}), _face.get_column(0));
    ASSERT_EQ((_aux = {RED , RED})  , _face.get_column(1));
    ASSERT_EQ(BLUE , _face.get_position(0, 0));
    ASSERT_EQ(RED  , _face.get_position(0, 1));
    ASSERT_EQ(GREEN, _face.get_position(1, 0));
    ASSERT_EQ(RED  , _face.get_position(1, 1));
}

TEST_F(face_setters_test, three_sided_straight_column_setter)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);

    _face.set_column(0, (_aux={BLUE, GREEN, ORANGE}));

    ASSERT_EQ((_aux = {BLUE, GREEN, ORANGE}), _face.get_column(0));
    ASSERT_EQ((_aux = {RED , RED  , RED})   , _face.get_column(1));
    ASSERT_EQ((_aux = {RED , RED  , RED})   , _face.get_column(2));
    ASSERT_EQ(BLUE  , _face.get_position(0, 0));
    ASSERT_EQ(RED   , _face.get_position(0, 1));
    ASSERT_EQ(RED   , _face.get_position(0, 2));
    ASSERT_EQ(GREEN , _face.get_position(1, 0));
    ASSERT_EQ(RED   , _face.get_position(1, 1));
    ASSERT_EQ(RED   , _face.get_position(1, 2));
    ASSERT_EQ(ORANGE, _face.get_position(2, 0));
    ASSERT_EQ(RED   , _face.get_position(2, 1));
    ASSERT_EQ(RED   , _face.get_position(2, 2));
}

TEST_F(face_setters_test, two_sided_backwards_line_setter)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);

    _face.set_line_backwards(0, (_aux={BLUE, GREEN}));

    ASSERT_EQ((_aux = {GREEN, BLUE}), _face.get_line(0));
    ASSERT_EQ((_aux = {RED , RED})  , _face.get_line(1));
    ASSERT_EQ(GREEN, _face.get_position(0, 0));
    ASSERT_EQ(BLUE , _face.get_position(0, 1));
    ASSERT_EQ(RED  , _face.get_position(1, 0));
    ASSERT_EQ(RED  , _face.get_position(1, 1));
}

TEST_F(face_setters_test, three_sided_backwards_line_setter)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);

    _face.set_line_backwards(0, (_aux={BLUE, GREEN, ORANGE}));

    ASSERT_EQ((_aux = {ORANGE, GREEN, BLUE}), _face.get_line(0));
    ASSERT_EQ((_aux = {RED   , RED  , RED}) , _face.get_line(1));
    ASSERT_EQ((_aux = {RED   , RED  , RED}) , _face.get_line(2));
    ASSERT_EQ(ORANGE, _face.get_position(0, 0));
    ASSERT_EQ(GREEN , _face.get_position(0, 1));
    ASSERT_EQ(BLUE  , _face.get_position(0, 2));
    ASSERT_EQ(RED   , _face.get_position(1, 0));
    ASSERT_EQ(RED   , _face.get_position(1, 1));
    ASSERT_EQ(RED   , _face.get_position(1, 2));
    ASSERT_EQ(RED   , _face.get_position(2, 0));
    ASSERT_EQ(RED   , _face.get_position(2, 1));
    ASSERT_EQ(RED   , _face.get_position(2, 2));
}

TEST_F(face_setters_test, two_sided_backwards_column_setter)
{
    _aux = {RED, RED, 
            RED, RED};
    _face = cube::face(2, _aux);

    _face.set_column_backwards(0, (_aux={BLUE, GREEN}));

    ASSERT_EQ((_aux = {GREEN, BLUE}), _face.get_column(0));
    ASSERT_EQ((_aux = {RED , RED})  , _face.get_column(1));
    ASSERT_EQ(GREEN, _face.get_position(0, 0));
    ASSERT_EQ(RED  , _face.get_position(0, 1));
    ASSERT_EQ(BLUE , _face.get_position(1, 0));
    ASSERT_EQ(RED  , _face.get_position(1, 1));
}

TEST_F(face_setters_test, three_sided_backwards_column_setter)
{
    _aux = {RED, RED, RED,
            RED, RED, RED,
            RED, RED, RED};
    _face = cube::face(3, _aux);

    _face.set_column_backwards(0, (_aux={BLUE, GREEN, ORANGE}));

    ASSERT_EQ((_aux = {ORANGE, GREEN, BLUE}), _face.get_column(0));
    ASSERT_EQ((_aux = {RED   , RED  , RED}) , _face.get_column(1));
    ASSERT_EQ((_aux = {RED   , RED  , RED}) , _face.get_column(2));
    ASSERT_EQ(ORANGE, _face.get_position(0, 0));
    ASSERT_EQ(RED   , _face.get_position(0, 1));
    ASSERT_EQ(RED   , _face.get_position(0, 2));
    ASSERT_EQ(GREEN , _face.get_position(1, 0));
    ASSERT_EQ(RED   , _face.get_position(1, 1));
    ASSERT_EQ(RED   , _face.get_position(1, 2));
    ASSERT_EQ(BLUE  , _face.get_position(2, 0));
    ASSERT_EQ(RED   , _face.get_position(2, 1));
    ASSERT_EQ(RED   , _face.get_position(2, 2));
}