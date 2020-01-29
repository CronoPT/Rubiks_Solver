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
#include "search/action.h"
#include "rubiks_cube.h"

#include "cube_actions/rotate_back_clock_wise.h"
#include "cube_actions/rotate_back_counter_clock_wise.h"
#include "cube_actions/rotate_front_clock_wise.h"
#include "cube_actions/rotate_front_counter_clock_wise.h"
#include "cube_actions/rotate_top_clock_wise.h"
#include "cube_actions/rotate_top_counter_clock_wise.h"
#include "cube_actions/rotate_bottom_clock_wise.h"
#include "cube_actions/rotate_bottom_counter_clock_wise.h"
#include "cube_actions/rotate_right_clock_wise.h"
#include "cube_actions/rotate_right_counter_clock_wise.h"
#include "cube_actions/rotate_left_clock_wise.h"
#include "cube_actions/rotate_left_counter_clock_wise.h"

#include <memory>

namespace cube 
{

class cubing: public search::problem<rubiks_cube>
{
    public:
        cubing(rubiks_cube cube): problem<rubiks_cube>(cube) {}
        std::vector<std::shared_ptr<search::action<rubiks_cube>>> actions(rubiks_cube cube) override;
        bool   goal_test(rubiks_cube cube) override;
        double heuristic(rubiks_cube cube) const override;
};

}// namespace cube

#endif