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
            Node<C> node(problem->getInitialState(), nullptr, nullptr, 0);
            priority_queue<Node<C>, vector<Node<C>>, std::greater<Node<C>>> frontier;
            set<C> explored;
            vector<Action<C>*> actions;

            frontier.push(node);

            while(!frontier.empty())
            {
                node = frontier.top(); /*chooses the lowest-cost node in frontier*/
                frontier.pop();

                if( problem->goalTest(node.getState()) )
                    return solution(node); /*builds a vector with the actions*/

                explored.insert(node.getState());
            
                /*expansion*/
                for(Action<C>* action : problem->actions(node.getState()))
                {
                    Node<C> child = childNode(problem, action, &node);
                    cout << *action << endl;
                    if( explored.count(child.getState())==0 )
                        frontier.push(child);
                }
            } 

            //throw some exception indicating the problem has no solution        
        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        Node<C> childNode(Problem<C>* problem, Action<C>* action, Node<C>* parent)
        {
            C state = problem->result(parent->getState(), action);

            double path_cost = problem->pathCost(parent->getPathCost(), \
              parent->getState(), action, state);

            Node<C> child_node(state, parent, action, path_cost);

            return child_node;
        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        vector<Action<C>*> solution(Node<C> node)
        {
            stack<Action<C>*>  sol_stack;
            vector<Action<C>*> solution;
            Node<C>* curr_node = &node;

            cout << "Solution - inicio" << endl;

            /*the initial state node has a Null action*/
            while( curr_node->getAction()!=nullptr )
            {   
                sol_stack.push(curr_node->getAction());
                curr_node = curr_node->getParent();
            }

            cout << "Solution - checkpoint" << endl; 

            while( !sol_stack.empty() )
            {
                solution.push_back(sol_stack.top());
                sol_stack.pop();
            }

            cout << "Solution - ending" << endl;

            return solution;
        }
};

#endif