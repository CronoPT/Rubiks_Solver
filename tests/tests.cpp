#include <gtest/gtest.h>

#include "face_constructor_test.cpp"
#include "face_setters_test.cpp"
#include "face_rotate_clock_wise_test.cpp"
#include "face_rotate_counter_clock_wise_test.cpp"

#include "../src/face.cpp"

int main(int argc, char** argv)
{   
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}