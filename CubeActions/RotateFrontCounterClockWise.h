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

#ifndef __ROTATEFRONTCOUNTERCLOCKWISE_H__
#define __ROTATEFRONTCOUNTERCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateFrontCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateFrontCounterClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateFrontCounterClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }

        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceCounterClockWise(FRONT, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const RotateFrontCounterClockWise& r)
        {
            os << "Front Counter Clock " << r._squares;
            return os;
        }
};

#endif
