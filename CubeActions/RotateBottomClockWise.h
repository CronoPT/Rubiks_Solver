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

#ifndef __ROTATEBOTTOMCLOCKWISE_H__
#define __ROTATEBOTTOMCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateBottomClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateBottomClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateBottomClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceClockWise(BOTTOM, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const RotateBottomClockWise& r)
        {
            os << "Bottom Clock " << r._squares;
            return os;
        }
};

#endif
