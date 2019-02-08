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

#include "Search/Problem.h"
#include "RubiksCube.h"

class Cubing: public Problem<RubiksCube>
{
    public:
        Cubing(RubiksCube cube): Problem<RubiksCube>(cube){}

        vector<Action<RubiksCube>> actions(){
            return {rotateBackClockWise(),
                    rotateBackCounterClockWise(),
                    rotateFrontClockWIse(),
                    rotateFrontCounterClockWise(),
                    rotateTopClockWise(),
                    rotateTopCounterClockWIse(),
                    rotateBottomClockWise(),
                    rotateBottomCounterClockWise(),
                    rotateRightClockWise(),
                    rotateRightCounterClockWise(),
                    rotateLeftClockWise(),
                    rotateLeftCounterClockWise()}
        }

        bool goalTest(RubiksCube cube)
        {
            return cube.solved();
        }

};

#endif