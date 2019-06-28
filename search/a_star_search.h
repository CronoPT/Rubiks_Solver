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

#ifndef __A_STAR_SEARCH_H__
#define __A_STAR_SEARCH_H__ 

#include "searching_algorithm.h"
#include "node.h"
#include <vector>
#include <queue>
#include <stack>
#include <set>

namespace search
{

template <typename C>
class a_star_search: public searching_algorithm<C>
{
    public:
        vector<shared_ptr<action<C>>> execute(problem<C>* problem) override;

        shared_ptr<node<C>> child_node(problem<C>* problem,
                                      shared_ptr<action<C>> action, 
                                      shared_ptr<node<C>> parent);

        vector<shared_ptr<action<C>>> solution(shared_ptr<Node<C>> node);
};

} //search

#endif