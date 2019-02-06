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

#include "Action.h"
#include <vector>
#include <stack>

template <typename C>
class SearchingAlgorithm
{
    public:
        vector<Action<C>> execute(Problem<C> problem);

        Node<C> childNode(Problem<C> problem, Action<C> action, Node<C>* node)
        {
            C state = problem.result(node->getState(), action);

            doubl path_cost = problem.pathCost(node->getPathCost(), \
              node->getState(), action, state);

            Node<C> child_node(state, node, action, path_cost);

            return child_node;
        }

        vector<Action<C>> solution(Node<C> node)
        {
            stack<Action<C>> sol_stack;
            Node<C>* curr_node = &node;

            while( curr_node->getParent()!=NULL )
            {
                sol_stack.push(curr_node->getAction());
                curr_node = curr_node->getParent();
            }

            while( !sol_stack.empty() )
            {
                solution.push_back(sol_stack.pop());
            }

            return solution;
        }
}
