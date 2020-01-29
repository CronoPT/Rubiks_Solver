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

vector<shared_ptr<action<rubiks_cube>>> cubing::actions(rubiks_cube cube)
{
    vector<shared_ptr<action<rubiks_cube>>> res;
    for(int i=1; i<=(int)cube.get_n()/2; i++)
    {
        res.push_back(make_shared<rotate_back_clock_wise>(rotate_back_clock_wise(i)));
        res.push_back(make_shared<rotate_back_counter_clock_wise>(rotate_back_counter_clock_wise(i)));
        res.push_back(make_shared<rotate_front_clock_wise>(rotate_front_clock_wise(i)));
        res.push_back(make_shared<rotate_front_counter_clock_wise>(rotate_front_counter_clock_wise(i)));
        res.push_back(make_shared<rotate_top_clock_wise>(rotate_top_clock_wise(i)));
        res.push_back(make_shared<rotate_top_counter_clock_wise>(rotate_top_counter_clock_wise(i)));
        res.push_back(make_shared<rotate_bottom_clock_wise>(rotate_bottom_clock_wise(i)));
        res.push_back(make_shared<rotate_bottom_counter_clock_wise>(rotate_bottom_counter_clock_wise(i)));
        res.push_back(make_shared<rotate_right_clock_wise>(rotate_right_clock_wise(i)));
        res.push_back(make_shared<rotate_right_counter_clock_wise>(rotate_right_counter_clock_wise(i)));
        res.push_back(make_shared<rotate_left_clock_wise>(rotate_left_clock_wise(i)));
        res.push_back(make_shared<rotate_left_counter_clock_wise>(rotate_left_counter_clock_wise(i))); 
    }

    return res;
}

bool cubing::goal_test(rubiks_cube cube)
{
    return cube.solved();
}

double cubing::heuristic(rubiks_cube cube) const
{
    return 0;
    if(cube.solved())
        return 0;

    int to_subtract = 0;
    int n = cube.get_n();
    for(face face : cube.get_faces())
        for(int l=0; l<n; l++)
            for(int c=0; c<n; c++)
            {
                if(c > 1)
                    if(face.get_position(l, c) == face.get_position(l, c-1))
                        to_subtract++;
                if(c < n-1)
                    if(face.get_position(l, c) == face.get_position(l, c+1))
                        to_subtract++;
                if(l > 1)
                    if(face.get_position(l, c) == face.get_position(l-1, c))
                        to_subtract++;
                if(l < n-1)
                    if(face.get_position(l, c) == face.get_position(l+1, c))
                        to_subtract++;
            }
    return n*n*6*4 - to_subtract;
}