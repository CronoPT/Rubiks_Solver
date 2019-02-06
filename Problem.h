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

#include "Action.h"
#include "Node.h"
#include <vector>

/*==============================================================
| class: Problem - a template of things to implement for a
| given type of search problem, e.g a Rubik's Cube
==============================================================*/
template<typename C>
class Problem
{
    private:
        C _initial;
        C _goal;

    public:
        Problem(C initial, C goal);
        Problem(C initial);
        C getInitialState() const { return _initial; }
        C getGoalState()    const { return _goal;    }
        
        virtual vector<Action<C>> actions(C state) = 0; //virtual function
        C   result(C state, Action<C> action);
        virtual bool goalTest(C state) = 0; //virtual function
        int pathCost(int cost, C state_1, Action<C> action, C state_2);
        vector<Action<C>> solve(SearchingAlgorithm algorithm)
        {
            return algorithm.execute(this);
        }

};