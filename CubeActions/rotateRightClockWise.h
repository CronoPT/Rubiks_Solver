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

#ifndef __ROTATERIGHTCLOCKWISE_H__
#define __ROTATERIGHTCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"
#include <iostream>

/*==============================================================
| class: rotateRightClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class rotateRightClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        rotateRightClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube)
        {
            cube.rotateFaceClockWise(RIGHT, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const rotateRightClockWise& r)
        {
            os << "Right Clock " << r._squares;
            return os;
        }
};

#endif
