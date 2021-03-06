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

#ifndef __PROBLEM_H__
#define __PROBLEM_H__ 

#include "action.h"
#include "node.h"
#include <vector>

template<typename C> class searching_algorithm;

/*==============================================================
| class: problem - a template of things to implement for a
| given type of search problem, e.g a Rubik's Cube
==============================================================*/
namespace search
{

template<typename C>
class problem
{
    private:
        C _initial;

    protected:
        problem(C initial):
          _initial(initial){}

    public:
        C get_initial_state() const { return _initial; }

        virtual std::vector<std::shared_ptr<action<C>>> actions(C state) = 0; //virtual function

        virtual C result(C state, std::shared_ptr<action<C>> action)
        {
            return action->execute(state);
        }

        virtual bool goal_test(C state) = 0; //virtual function

        virtual double path_cost(double cost, C state_1, std::shared_ptr<action<C>> action, C state_2)
        {   
            //default: one more step
            return cost+1;
        }

        virtual double heuristic(C state) const { return 0; }

        std::vector<std::shared_ptr<action<C>>> solve(searching_algorithm<C>* algorithm) const
        {
            return algorithm->execute(this);
        }
};

}// namespace search

#endif