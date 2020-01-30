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

#ifndef __SEARCHING_ALGORITHM_H__
#define __SEARCHING_ALGORITHM_H__ 

#include "action.h"
#include "problem.h"
#include <vector>

namespace search
{

template <typename C>
class searching_algorithm
{
    public:
        virtual std::vector<std::shared_ptr<action<C>>> execute(problem<C>* problem) = 0;
};

}// namespace search

#endif