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

#ifndef __ASTARSEARCH_H__
#define __ASTARSEARCH_H__ 

#include "SearchingAlgorithm.h"
#include "Node.h"
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <memory>

using namespace std;

template <typename C>
class AStarSearch: public SearchingAlgorithm<C>
{    
    public:
        /*==============================================================
        | function: execute
        ==============================================================*/
        vector<shared_ptr<Action<C>>> execute(Problem<C>* problem)
        {
            shared_ptr<Node<C>> node = make_shared<Node<C>>(problem->getInitialState(), nullptr, nullptr, 0);
            priority_queue<shared_ptr<Node<C>>, vector<shared_ptr<Node<C>>>, std::greater<shared_ptr<Node<C>>>> frontier;
            set<C> explored;
            vector<shared_ptr<Action<C>>> actions;

            frontier.push(node);

            while(!frontier.empty())
            {
                node = frontier.top(); /*chooses the lowest-cost node in frontier*/
                frontier.pop();

                if( problem->goalTest(node->getState()) )  
                    return solution(node); /*builds a vector with the actions*/
                
                explored.insert(node->getState());

                /*expansion*/
                for(shared_ptr<Action<C>> action : problem->actions(node->getState()))
                {
                    shared_ptr<Node<C>> child = childNode(problem, action, node);
                    if( explored.count(child->getState())==0 )
                        frontier.push(child);
                }
            } 
            //throw some exception indicating the problem has no solution        
        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        shared_ptr<Node<C>> childNode(Problem<C>* problem, shared_ptr<Action<C>> action, shared_ptr<Node<C>> parent)
        {
            C state = problem->result(parent->getState(), action);

            double path_cost = problem->pathCost(parent->getPathCost(), \
              parent->getState(), action, state);

            return make_shared<Node<C>>(state, parent, action, path_cost);

        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        vector<shared_ptr<Action<C>>> solution(shared_ptr<Node<C>> node)
        {
            stack<shared_ptr<Action<C>>>  sol_stack;
            vector<shared_ptr<Action<C>>> solution;
            shared_ptr<Node<C>> curr_node = node;

            /*the initial state node has a Null action*/
            while( curr_node->getAction() )
            {   
                sol_stack.push(curr_node->getAction());
                curr_node = curr_node->getParent();
            }

            while( !sol_stack.empty() )
            {
                solution.push_back(sol_stack.top());
                sol_stack.pop();
            }

            return solution;
        }
};

#endif