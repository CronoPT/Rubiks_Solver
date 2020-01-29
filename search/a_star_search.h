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
        std::vector<std::shared_ptr<action<C>>> execute(problem<C>* problem) override;

        std::shared_ptr<node<C>> child_node(problem<C>* problem,
                                            std::shared_ptr<action<C>> action, 
                                            std::shared_ptr<node<C>> parent);

        std::vector<std::shared_ptr<action<C>>> solution(std::shared_ptr<node<C>> node);
};

}// namespace search

#endif