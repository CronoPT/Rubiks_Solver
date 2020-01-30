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

/*==============================================================
| class: Problem - a template of things to implement for a
| given type of search problem, e.g a Rubik's Cube
==============================================================*/
namespace search
{

template<typename C>
class action
{
    public:
        virtual C execute(C state) = 0; //virtual function

        virtual void dump_to(std::ostream& os) const = 0;

        friend std::ostream& operator<<(std::ostream& os, const action<C>& a) 
        {
            a.dump_to(os);
            return os;
        }
};

}// namespace search

#endif