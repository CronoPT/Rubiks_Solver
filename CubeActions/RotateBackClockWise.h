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

#ifndef __ROTATEBACKCLOCKWISE_H__
#define __ROTATEBACKCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateBackClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does nvirtual ot make sense to rotate
| beyond the middle
==============================================================*/
class RotateBackClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateBackClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceClockWise(BACK, _squares);
            return cube;
        }

        void dumpTo(ostream& os) const override
        {
            os << "Back Clock " << _squares;
        }

        friend ostream& operator<<(ostream& os, const RotateBackClockWise& r)
        {
            r.dumpTo(os);
            return os;
        }
};

#endif