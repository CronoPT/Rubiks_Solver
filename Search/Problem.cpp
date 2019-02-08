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

#include "Problem.h"

/*==============================================================
| function: rotateFaceClockWise
==============================================================*/
Problem::Problem(C initial, C goal)
{
    _initial = initial;
    _goal    = goal;
}

/*==============================================================
| function: rotateFaceClockWise
==============================================================*/
Problem::Problem(C initial)
{
    _intial = initial;
}

/*==============================================================
| function: result - just execute the action
==============================================================*/
C Problem::result(C state, Action<C> action)
{
    return action.execute(state);
}

/*==============================================================
| function: pathCost - default assumes the steps are uninatary
==============================================================*/
int Problem::pathCost(int cost, C state_1, Action<C> action, C state_2)
{
    return c+1;
}
