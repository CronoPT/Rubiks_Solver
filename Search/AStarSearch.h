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

using namespace std;

template <typename C>
class AStarSearch: public SearchingAlgorithm<C>
{
    public:
        vector<shared_ptr<Action<C>>> execute(Problem<C>* problem) override;

        shared_ptr<Node<C>> childNode(Problem<C>* problem,
                                      shared_ptr<Action<C>> action, 
                                      shared_ptr<Node<C>> parent);

        vector<shared_ptr<Action<C>>> solution(shared_ptr<Node<C>> node);
};

#endif