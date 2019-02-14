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

#ifndef __ROTATEBOTTOMCOUNTERCLOCKWISE_H__
#define __ROTATEBOTTOMCOUNTERCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"
#include <iostream>

using namespace std;

/*==============================================================
| class: rotateBottomCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateBottomCounterClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateBottomCounterClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }

        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceCounterClockWise(BOTTOM, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const RotateBottomCounterClockWise& r)
        {
            os << "Bottom Counter Clock " << r._squares;
            return os;
        }
};

#endif