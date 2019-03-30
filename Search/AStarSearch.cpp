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

#include "AStarSearch.h"

/*==============================================================
| function: execute
==============================================================*/
template<typename C>
vector<shared_ptr<Action<C>>> AStarSearch<C>::execute(Problem<C>* problem)
{
    shared_ptr<Node<C>> node = make_shared<Node<C>>(problem->getInitialState(), 
                                                    nullptr, nullptr, 0,
                                                    problem->heuristic(
                                                    problem->getInitialState()));
    priority_queue<shared_ptr<Node<C>>, 
                   vector<shared_ptr<Node<C>>>, 
                   std::greater<shared_ptr<Node<C>>>> frontier;
    set<C> explored;
    vector<shared_ptr<Action<C>>> actions;

    frontier.push(node);
    explored.insert(node->getState());
    int depth = 0;
    while(!frontier.empty())
    {
        node = frontier.top(); /*chooses the lowest-cost node in frontier*/
        frontier.pop();

        if( problem->goalTest(node->getState()) )  
            return solution(node); /*builds a vector with the actions*/
        
        explored.insert(node->getState());

        /*expansion*/
        for(shared_ptr<Action<C>> action : problem->actions(node->getState()))
        {
            shared_ptr<Node<C>> child = childNode(problem, action, node);

            if( explored.count(child->getState())==0 )
            {    
                frontier.push(child);
            }
        }
    } 
    //throw some exception indicating the problem has no solution        
}

/*==============================================================
| function: childNode
==============================================================*/
template<typename C>
shared_ptr<Node<C>> AStarSearch<C>::childNode(Problem<C>* problem, 
                                              shared_ptr<Action<C>> action, 
                                              shared_ptr<Node<C>> parent)
{
    C state = problem->result(parent->getState(), action);

    double path_cost = problem->pathCost(parent->getPathCost(),
                                         parent->getState(), 
                                         action, state);

    double heuristic = problem->heuristic(state);

    return make_shared<Node<C>>(state, parent, action, path_cost, heuristic);

}

/*==============================================================
| function: solution
==============================================================*/
template<typename C>
vector<shared_ptr<Action<C>>> AStarSearch<C>::solution(shared_ptr<Node<C>> node)
{
    stack<shared_ptr<Action<C>>>  sol_stack;
    vector<shared_ptr<Action<C>>> solution;
    shared_ptr<Node<C>> curr_node = node;

    /*the initial state node has a Null action*/
    while( curr_node->getAction() )
    {   
        sol_stack.push(curr_node->getAction());
        curr_node = curr_node->getParent();
    }

    while( !sol_stack.empty() )
    {
        solution.push_back(sol_stack.top());
        sol_stack.pop();
    }

    return solution;
}
