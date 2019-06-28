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

#ifndef __ROTATE_BOTTOM_COUNTER_CLOCK_WISE_H__
#define __ROTATE_BOTTOM_COUNTER_CLOCK_WISE_H__

#include "../search/action.h"
#include "../rubiks_cube.h"

namespace cubing
{

/*==============================================================
| class: rotateBottomCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class rotate_bottom_counter_clock_wise: public action<rubiks_cube>
{
    private:
        int _squares;

    public:
        rotate_bottom_counter_clock_wise(int squares): action<rubiks_cube>()
        {   
            _squares = squares;
        }

        rubiks_cube execute(rubiks_cube cube) override
        {
            cube.rotate_face_counter_clock_wise(BOTTOM, _squares);
            return cube;
        }

        void dump_to(ostream& os) const override
        {
            os << "Bottom Counter " << _squares;
        }

        friend ostream& operator<<(ostream& os, const rotate_bottom_counter_clock_wise& r)
        {
            r.dump_to(os);
            return os;
        }
};

} //cubing

#endif
