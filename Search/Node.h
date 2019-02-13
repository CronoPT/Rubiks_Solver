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

template <typename C>
class Node
{
    private:
        C          _state;
        Node<C>*   _parent;
        Action<C>* _action;
        double     _path_cost;

    public:
        Node(C state, Node<C>* parent, 
          Action<C>* action, double path_cost):
          _state(state),
          _parent(parent),
          _action(action),
          _path_cost(path_cost)
        {
            // _state     = state;
            // _parent    = parent;
            // _action    = action;
            // _path_cost = path_cost;
        }

        C getState() const { return _state; }

        Node<C>* getParent() const  { return _parent; }

        Action<C>* getAction() const { return _action; }

        double getPathCost() const  { return _path_cost; }

        friend bool operator<(const Node<C>& node_1, const Node<C>& node_2)
        {
            return node_1.getPathCost() < node_2.getPathCost();
        }

        friend bool operator>(const Node<C>& node_1, const Node<C>& node_2)
        {
            return node_1.getPathCost() > node_2.getPathCost();
        }

        friend bool operator<(const Node<C>& node_1, const Node<C>*& node_2)
        {
            return node_1->getPathCost() < node_2->getPathCost();
        }

        friend bool operator>(const Node<C>& node_1, const Node<C>*& node_2)
        {
            return node_1->getPathCost() > node_2->getPathCost();
        }
};

#endif