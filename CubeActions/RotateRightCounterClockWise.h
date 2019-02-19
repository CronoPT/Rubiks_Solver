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

#ifndef __ROTATERIGHTCOUNTERCLOCKWISE_H__
#define __ROTATERIGHTCOUNTERCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateRightCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateRightCounterClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateRightCounterClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }

        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceCounterClockWise(RIGHT, _squares);
            return cube;
        }

        void dumpTo(ostream& os) const override
        {
            os << "Right Counter " << _squares;
        }

        friend ostream& operator<<(ostream& os, const RotateRightCounterClockWise& r)
        {
            r.dumpTo(os);
            return os;
        }
};

#endif
