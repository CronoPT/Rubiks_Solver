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

#ifndef __ACTION_H__
#define __ACTION_H__ 

#include<iostream>

using namespace std;

/*==============================================================
| class: Problem - a template of things to implement for a
| given type of search problem, e.g a Rubik's Cube
==============================================================*/
template<typename C>
class Action
{
    public:
        virtual C execute(C state) = 0; //virtual function

        friend ostream& operator<<(ostream& os, const Action<C>& r) {}
};

#endif