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

#ifndef __ROTATE_FRONT_COUNTER_CLOCK_WISE_H__
#define __ROTATE_FRONT_COUNTER_CLOCK_WISE_H__

#include "../search/action.h"
#include "../rubiks_cube.h"

using namespace std;

/*==============================================================
| class: rotateFrontCounterClockWise - squares is the number of 
| squares to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
class rotate_front_counter_clock_wise: public action<rubiks_cube>
{
    private:
        int _squares;

    public:
        rotate_front_counter_clock_wise(int squares): action<rubiks_cube>()
        {   
            _squares = squares;
        }

        rubiks_cube execute(rubiks_cube cube) override
        {
            cube.rotate_face_counter_clock_wise(FRONT, _squares);
            return cube;
        }

        void dump_to(ostream& os) const override
        {
            os << "Front Counter " << _squares;
        }

        friend ostream& operator<<(ostream& os, const rotate_front_counter_clock_wise& r)
        {
            r.dump_to(os);
            return os;
        }
};

#endif