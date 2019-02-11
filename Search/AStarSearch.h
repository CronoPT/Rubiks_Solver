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
#include <set>
#include <algorithm>

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
            Node<C> node(problem->getInitialState(), NULL, NULL, 0);
            priority_queue<Node<C>, vector<Node<C>>, std::greater<Node<C>>> frontier;
            set<C> explored;
            vector<Action<C>*> actions;
            int path_cost_frontier;

            frontier.push(node);

            cout << "Searching" << endl;
            while(!frontier.empty())
            {
                node = frontier.top(); /*chooses the lowest-cost node in frontier*/
                frontier.pop();
                if( problem->goalTest(node.getState()) )
                    return solution(node);
                explored.insert(node.getState());

                actions = problem->actions(node.getState());
                for(Action<C>* action : actions)
                {
                    Node<C> child = childNode(problem, action, &node);

                    if( explored.count(child.getState())==0 )
                        frontier.push(child);
                }
            } 
            //throw some exception indicating the problemhas no solution        
        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        Node<C> childNode(Problem<C>* problem, Action<C>* action, Node<C>* node)
        {
            C state = problem->result(node->getState(), action);

            double path_cost = problem->pathCost(node->getPathCost(), \
              node->getState(), action, state);

            Node<C> child_node(state, node, action, path_cost);

            return child_node;
        }

        /*==============================================================
        | function: rotateFaceClockWise
        ==============================================================*/
        vector<Action<C>*> solution(Node<C> node)
        {
            stack<Action<C>*> sol_stack;
            vector<Action<C>*> solution;
            Node<C>* curr_node = &node;

            while( curr_node->getParent()!=NULL )
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