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

#include "Action.h"

#include <memory>
#include <iostream>

template <typename C>
class Node
{
    private:
        C          _state;
        shared_ptr<Node<C>>   _parent;
        shared_ptr<Action<C>> _action;
        double     _path_cost;
        double     _heuristic;

    public:
        Node(C state, shared_ptr<Node<C>> parent, 
          shared_ptr<Action<C>> action, double path_cost,
          double heuristic):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost), 
          _heuristic(heuristic){}

        Node(C state, shared_ptr<Node<C>> parent, 
          shared_ptr<Action<C>> action, double path_cost):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost), 
          _heuristic(0) {}

        C getState() const { return _state; }

        shared_ptr<Node<C>> getParent() const  { return _parent; }

        shared_ptr<Action<C>> getAction() const { return _action; }

        double getPathCost() const  { return _path_cost; }

        double getHeuristic() const { return _heuristic; }

        bool operator<(const Node<C>& other)
        {
            return getPathCost() + getHeuristic() < 
                   other.getPathCost() + other.getHeuristic();
        }

        bool operator>(const Node<C>& other)
        {
            return getPathCost() + getHeuristic() > 
                   other.getPathCost() + other.getHeuristic();
        }

        friend bool operator<(const shared_ptr<Node<C>>& node_1, const shared_ptr<Node<C>>& node_2)
        {
            return *node_1 < *node_2;
        }

        friend bool operator>(const shared_ptr<Node<C>>& node_1, const shared_ptr<Node<C>>& node_2)
        {
            return *node_1 > *node_2;
        }
};

#endif