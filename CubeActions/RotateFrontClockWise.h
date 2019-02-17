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

#ifndef __ROTATEFRONTCLOCKWISE_H__
#define __ROTATEFRONTCLOCKWISE_H__

#include "../Search/Action.h"
#include "../RubiksCube.h"

using namespace std;

/*==============================================================
| class: rotateFrontClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class RotateFrontClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        RotateFrontClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube) override
        {
            cube.rotateFaceClockWise(FRONT, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const RotateFrontClockWise& r)
        {
            os << "Front Clock " << r._squares;
            return os;
        }
};

#endif
