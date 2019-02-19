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

using namespace std;

/*==============================================================
| class: rotateRightClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateRightClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateRightClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceClockWise(RIGHT, _squares);
            return cube;
        }

        void dumpTo(ostream& os) const override
        {
            os << "Right Clock " << _squares;
        }

        friend ostream& operator<<(ostream& os, const RotateRightClockWise& r)
        {
            r.dumpTo(os);
            return os;
        }
};

#endif
