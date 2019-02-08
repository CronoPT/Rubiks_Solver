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

#ifndef __ROTATEBACKCOUNTERCLOCKWISE_H__
#define __ROTATEBACKCOUNTERCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"
#include <iostream>

/*==============================================================
| class: rotateBackCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class rotateBackCounterClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        rotateBackCounterClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }

        RubiksCube execute(RubiksCube cube)
        {
            cube.rotateFaceCounterClockWise(BACK, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const rotateBackCounterClockWise& r)
        {
            os << "Back Counter Clock " << r._squares;
            return os;
        }
};

#endif