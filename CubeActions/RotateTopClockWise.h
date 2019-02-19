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

#ifndef __ROTATETOPCLOCKWISE_H__
#define __ROTATETOPCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateTopClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateTopClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateTopClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceClockWise(TOP, _squares);
            return cube;
        }

        void dumpTo(ostream& os) const override
        {
            os << "Top Clock " << _squares;
        }

        friend ostream& operator<<(ostream& os, const RotateTopClockWise& r)
        {
            r.dumpTo(os);
            return os;
        }
};

#endif
