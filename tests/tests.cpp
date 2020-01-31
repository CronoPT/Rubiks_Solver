#include <gtest/gtest.h>

#include "face_constructor_test.cpp"
#include "face_setters_test.cpp"
#include "face_rotate_clock_wise_test.cpp"
#include "face_rotate_counter_clock_wise_test.cpp"
#include "rubiks_cube_rotate_front_clock_wise_test.cpp"
#include "rubiks_cube_rotate_front_counter_clock_wise_test.cpp"
#include "rubiks_cube_rotate_bottom_clock_wise.cpp"
#include "rubiks_cube_rotate_bottom_counter_clock_wise.cpp"
#include "rubiks_cube_rotate_right_clock_wise.cpp"
#include "rubiks_cube_rotate_right_counter_clock_wise.cpp"
#include "rubiks_cube_rotate_left_clock_wise.cpp"
#include "rubiks_cube_rotate_left_counter_clock_wise.cpp"
#include "rubiks_cube_rotate_top_clock_wise.cpp"
#include "rubiks_cube_rotate_top_counter_clock_wise.cpp"
#include "rubiks_cube_rotate_back_clock_wise.cpp"
#include "rubiks_cube_rotate_back_counter_clock_wise.cpp"


#include "../src/face.cpp"
#include "../src/rubiks_cube.cpp"

int main(int argc, char** argv)
{   
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}