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

#ifndef __ROTATETOPCOUNTERCLOCKWISE_H__
#define __ROTATETOPCOUNTERCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateTopCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateTopCounterClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateTopCounterClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }

        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceCounterClockWise(TOP, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const RotateTopCounterClockWise& r)
        {
            os << "Top Counter Clock " << r._squares;
            return os;
        }
};

#endif
