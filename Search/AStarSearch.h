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
#include "Action.h"
#include "Problem.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template <typename C>
class AStarSearch: public SearchingAlgorithm<C>
{    
    public:
        vector<Action<C>> execute(Problem<C> problem)
        {
            Node<C> node(problem.getInitialState(), NULL, 0);
            priority_queue<Node<C>, vector<Node<C>>, std::greater<Node<C>>> frontier;
            set<C> explored;
            Node<C> child;

            frontier.push(node);

            while(!frontier.empty())
            {
                node = frontier.pop(); /*chooses the lowest-cost node in frontier*/
                if( problem.goalTest(node.getState()) )
                    return solution(node);
                explored.insert(node.getState());

                for(Action<C> action : problem.actions(node.getState()))
                {
                    child = childNode(problem, action, &node);
                    if(explored.count(child.getState)==0)
                        frontier.push(child);
                }
            }   

            //throw some exception indicating the problemhas no solution        
        }
};

#endif