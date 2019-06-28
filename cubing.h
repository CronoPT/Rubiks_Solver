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

#ifndef __CUBING_H__
#define __CUBING_H__

#include "search/problem.h"
#include "search/section.h"
#include "rubiks_cube.h"

#include "cube_actions/RotateBackClockWise.h"
#include "cube_actions/RotateBackCounterClockWise.h"
#include "cube_actions/RotateFrontClockWise.h"
#include "cube_actions/RotateFrontCounterClockWise.h"
#include "cube_actions/RotateTopClockWise.h"
#include "cube_actions/RotateTopCounterClockWise.h"
#include "cube_actions/RotateBottomClockWise.h"
#include "cube_actions/RotateBottomCounterClockWise.h"
#include "cube_actions/RotateRightClockWise.h"
#include "cube_actions/RotateRightCounterClockWise.h"
#include "cube_actions/RotateLeftClockWise.h"
#include "cube_actions/RotateLeftCounterClockWise.h"

#include <memory>

namespace cubing 
{

class cubing: public problem<rubiks_cube>
{
    public:
        cubing(rubiks_cube cube): problem<rubiks_cube>(cube) {}

        vector<shared_ptr<action<rubiks_cube>>> actions(rubiks_cube cube) override
        {   
            vector<shared_ptr<action<rubiks_cube>>> res;
            for(int i=1; i<=(int)cube.N()/2; i++)
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

        bool goal_test(rubiks_cube cube) override
        {
            return cube.solved();
        }

        double heuristic(rubiks_cube cube) const override
        {
            return 0;
            if(cube.solved())
                return 0;

            int to_subtract = 0;
            int n = cube.N();
            for(face face : cube.faces())
                for(int l=0; l<n; l++)
                    for(int c=0; c<n; c++)
                    {
                        if(c > 1)
                            if(face.position(l, c) == face.position(l, c-1))
                                to_subtract++;
                        if(c < n-1)
                            if(face.position(l, c) == face.position(l, c+1))
                                to_subtract++;
                        if(l > 1)
                            if(face.position(l, c) == face.position(l-1, c))
                                to_subtract++;
                        if(l < n-1)
                            if(face.position(l, c) == face.position(l+1, c))
                                to_subtract++;
                    }
            return n*n*6*4 - to_subtract;
        }
};

} //cubing

#endif