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

#ifndef __SEARCHINGALGORITHM_H__
#define __SEARCHINGALGORITHM_H__ 

#include "Action.h"
#include "Problem.h"
#include <vector>

namespace search
{

template <typename C>
class searching_algorithm
{
    public:
        virtual vector<shared_ptr<action<C>>> execute(problem<C>* problem) = 0;
};

} //search

#endif