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

using namespace std;

template <typename C>
class AStarSearch: public SearchingAlgorithm<C>
{    
    public:
        /*==============================================================
        | function: execute
        ==============================================================*/
        vector<Action<C>*> execute(Problem<C>* problem)
        {
            Node<C>* node = new Node<C>(problem->getInitialState(), nullptr, nullptr, \
              problem->heuristic(problem->getInitialState()));
            priority_queue<Node<C>*, vector<Node<C>*>, std::greater<Node<C>*>> frontier;
            set<C> explored;
            vector<Action<C>*> actions;

            frontier.push(node);

            while(!frontier.empty())
            {
                node = frontier.top(); /*chooses the lowest-cost node in frontier*/
                frontier.pop();

                if( problem->goalTest(node->getState()) )  
                    return solution(node, problem); /*builds a vector with the actions*/
                
                explored.insert(node->getState());

                /*expansion*/
                for(Action<C>* action : problem->actions(node->getState()))
                {
                    Node<C>* child = childNode(problem, action, node);

                    if( explored.count(child->getState())==0 )
                        frontier.push(child);
                }
                delete node;
            } 
            //throw some exception indicating the problem has no solution        
        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        Node<C>* childNode(Problem<C>* problem, Action<C>* action, Node<C>* parent)
        {
            C state = problem->result(parent->getState(), action);

            double path_cost = problem->pathCost(parent->getPathCost(), \
              parent->getState(), action, state);

            return new Node<C>(state, parent, action, path_cost);

        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        vector<Action<C>*> solution(Node<C>* node, Problem<C>* p)
        {
            stack<Action<C>*>  sol_stack;
            vector<Action<C>*> solution;
            Node<C>* curr_node = node;

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