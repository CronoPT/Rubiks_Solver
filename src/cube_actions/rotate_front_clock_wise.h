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

#ifndef __ROTATE_FRONT_CLOCK_WISE_H__
#define __ROTATE_FRONT_CLOCK_WISE_H__

#include "../search/action.h"
#include "../rubiks_cube.h"

/*==============================================================
| class: rotateFrontClockWise - squares is the number of squares
| to swap between the faces adjacent to the one you're 
| rotating, for examples, in the 3x3 cube, squares can't be
| diferent from 1, since it does not make sense to rotate
| beyond the middle
==============================================================*/
namespace cube
{

class rotate_front_clock_wise: public search::action<rubiks_cube>
{
    private:
        int _squares;

    public:
        rotate_front_clock_wise(int squares): search::action<rubiks_cube>()
        {   
            _squares = squares;
        }
        
        rubiks_cube execute(rubiks_cube cube) override
        {
            cube.rotate_face_clock_wise(FRONT, _squares);
            return cube;
        }

        void dump_to(std::ostream& os) const override
        {
            os << "Front Clock " << _squares;
        }

        friend std::ostream& operator<<(std::ostream& os, const rotate_front_clock_wise& r)
        {
            r.dump_to(os);
            return os;
        }
};

}// namespace cube

#endif
