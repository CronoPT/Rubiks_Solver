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

#include "../Action.h"
#include "../RubiksCube.h"
#include <iostream>

/*==============================================================
| class: rotateRightCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class rotateRightCounterClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        rotateRightCounterClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }

        RubiksCube execute(RubiksCube cube)
        {
            cube.rotateFaceCounterClockWise(RIGHT, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const rotateRightCounterClockWise& r)
        {
            os << "Right Counter Clock " << r._squares;
            return os;
        }
};