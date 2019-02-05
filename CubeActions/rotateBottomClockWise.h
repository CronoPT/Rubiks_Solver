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
| class: rotateBottomClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class rotateBottomClockWise: public Action<RubiksCube>
{
    private:
        int _squares;

    public:
        rotateBottomClockWise(int squares): Action<RubiksCube>()
        {   
            _squares = squares;
        }
        
        RubiksCube execute(RubiksCube cube)
        {
            cube.rotateFaceClockWise(BOTTOM, _squares);
            return cube;
        }

        friend ostream& operator<<(ostream& os, const rotateBottomClockWise& r)
        {
            os << "Bottom Clock " << r._squares;
            return os;
        }
};