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

#include "Action.h"
#include "Node.h"
#include <vector>

using namespace std;

template<typename C> class SearchingAlgorithm;

/*==============================================================
| class: Problem - a template of things to implement for a
| given type of search problem, e.g a Rubik's Cube
==============================================================*/
template<typename C>
class Problem
{
    private:
        C _initial;

    public:
        Problem(C initial):
          _initial(initial)
        {

        }

        C getInitialState() const { return _initial; }

        virtual vector<shared_ptr<Action<C>>> actions(C state) = 0; //virtual function

        C result(C state, shared_ptr<Action<C>> action)
        {
            return action->execute(state);
        }

        virtual bool goalTest(C state) = 0; //virtual function

        double pathCost(double cost, C state_1, shared_ptr<Action<C>> action, C state_2)
        {
            return cost+1;
        }

        virtual double heuristic(C state) = 0;

        vector<shared_ptr<Action<C>>> solve(SearchingAlgorithm<C>* algorithm)
        {
            return algorithm->execute(&this);
        }

        virtual void printAction(shared_ptr<Action<C>> a) = 0;
};

#endif