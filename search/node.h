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
        shared_ptr<node<C>>   _parent;
        shared_ptr<action<C>> _action;
        double _path_cost;
        double _heuristic;

    public:
        node(C state, shared_ptr<Node<C>> parent, 
          shared_ptr<Action<C>> action, double path_cost,
          double heuristic):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost), 
          _heuristic(heuristic){}

        node(C state, shared_ptr<Node<C>> parent, 
          shared_ptr<Action<C>> action, double path_cost):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost), 
          _heuristic(0) {}

        C state() const { return _state; }

        shared_ptr<Node<C>> parent() const  { return _parent; }

        shared_ptr<Action<C>> action() const { return _action; }

        double path_cost() const  { return _path_cost; }

        double heuristic() const { return _heuristic; }

        bool operator<(const Node<C>& other)
        {
            return path_cost() + heuristic() < 
                   other.path_cost() + other.heuristic();
        }

        bool operator>(const Node<C>& other)
        {
            return path_cost() + heuristic() > 
                   other.path_cost() + other.heuristic();
        }

        friend bool operator<(const shared_ptr<node<C>>& node_1, const shared_ptr<node<C>>& node_2)
        {
            return *node_1 < *node_2;
        }

        friend bool operator>(const shared_ptr<node<C>>& node_1, const shared_ptr<node<C>>& node_2)
        {
            return *node_1 > *node_2;
        }
};

} //search

#endif