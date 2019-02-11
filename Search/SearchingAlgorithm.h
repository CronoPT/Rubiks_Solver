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
#include <stack>

using namespace std;

template <typename C>
class SearchingAlgorithm
{
    public:
        virtual vector<Action<C>*> execute(Problem<C>* problem) = 0;
};

#endif