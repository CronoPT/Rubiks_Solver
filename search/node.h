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

#ifndef __NODE_H__
#define __NODE_H__ 

#include "action.h"

#include <memory>
#include <iostream>

namespace search
{

template <typename C>
class node
{
    private:
        C      _state;
        std::shared_ptr<node<C>>   _parent;
        std::shared_ptr<action<C>> _action_exec;
        double _path_cost;
        double _heuristic;

    public:
        node(C state, std::shared_ptr<node<C>> parent, 
          std::shared_ptr<action<C>> action, double path_cost,
          double heuristic):
          _state(state),
          _parent(parent),
          _action_exec(action),
          _path_cost(path_cost), 
          _heuristic(heuristic){}

        node(C state, std::shared_ptr<node<C>> parent, 
          std::shared_ptr<action<C>> action, double path_cost):
          _state(state),
          _parent(parent),
          _action_exec(action),
          _path_cost(path_cost), 
          _heuristic(0) {}

        C state() const { return _state; }

        std::shared_ptr<node<C>> parent() const   { return _parent; }

        std::shared_ptr<action<C>> action_exec() const { return _action_exec; }

        double path_cost() const  { return _path_cost; }

        double heuristic() const { return _heuristic; }

        bool operator<(const node<C>& other)
        {
            return path_cost() + heuristic() < 
                   other.path_cost() + other.heuristic();
        }

        bool operator>(const node<C>& other)
        {
            return path_cost() + heuristic() > 
                   other.path_cost() + other.heuristic();
        }

        friend bool operator<(const std::shared_ptr<node<C>>& node_1, const std::shared_ptr<node<C>>& node_2)
        {
            return *node_1 < *node_2;
        }

        friend bool operator>(const std::shared_ptr<node<C>>& node_1, const std::shared_ptr<node<C>>& node_2)
        {
            return *node_1 > *node_2;
        }
};

} //search

#endif