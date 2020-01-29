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
        C _state;
        std::shared_ptr<node<C>>   _parent;
        std::shared_ptr<action<C>> _action;
        double _path_cost;
        double _heuristic;

    public:
        node(C state, std::shared_ptr<node<C>> parent, 
          std::shared_ptr<action<C>> action, double path_cost,
          double heuristic):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost), 
          _heuristic(heuristic){}

        node(C state, std::shared_ptr<node<C>> parent, 
          std::shared_ptr<action<C>> action, double path_cost):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost), 
          _heuristic(0) {}

        C get_state() const { return _state; }

        std::shared_ptr<node<C>> get_parent() const  { return _parent; }

        std::shared_ptr<action<C>> get_action() const { return _action; }

        double get_path_cost() const  { return _path_cost; }

        double get_heuristic() const { return _heuristic; }

        bool operator<(const node<C>& other)
        {
            return get_path_cost() + get_heuristic() < 
                   other.get_path_cost() + other.get_heuristic();
        }

        bool operator>(const node<C>& other)
        {
            return get_path_cost() + get_heuristic() > 
                   other.get_path_cost() + other.get_heuristic();
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

}// namespace search

#endif