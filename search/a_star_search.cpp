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

#include "a_star_search.h"

/*==============================================================
| function: execute
==============================================================*/
template<typename C>
std::vector<std::shared_ptr<search::action<C>>> search::a_star_search<C>::execute(problem<C>* problem)
{
    std::shared_ptr<search::node<C>> node = std::make_shared<search::node<C>>(problem->initial_state(), 
                                                              nullptr, nullptr, 0,
                                                              problem->heuristic(
                                                              problem->initial_state()));
    std::priority_queue<std::shared_ptr<search::node<C>>, 
                        std::vector<std::shared_ptr<search::node<C>>>, 
                        std::greater<std::shared_ptr<search::node<C>>>> frontier;
    std::set<C> explored;
    std::vector<std::shared_ptr<action<C>>> actions;

    frontier.push(node);
    explored.insert(node->state());
    int depth = 0;
    while(!frontier.empty())
    {
        node = frontier.top(); /*chooses the lowest-cost node in frontier*/
        frontier.pop();

        if( problem->goal_test(node->state()) )  
            return solution(node); /*builds a vector with the actions*/
        
        explored.insert(node->state());

        /*expansion*/
        for(std::shared_ptr<action<C>> action : problem->actions(node->state()))
        {
            std::shared_ptr<search::node<C>> child = child_node(problem, action, node);

            if( explored.count(child->state())==0 )
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
std::shared_ptr<search::node<C>> search::a_star_search<C>::child_node(problem<C>* problem, 
                                                                      std::shared_ptr<action<C>> action, 
                                                                      std::shared_ptr<node<C>> parent)
{
    C state = problem->result(parent->state(), action);

    double path_cost = problem->path_cost(parent->path_cost(),
                                          parent->state(), 
                                          action, state);

    double heuristic = problem->heuristic(state);

    return std::make_shared<node<C>>(state, parent, action, path_cost, heuristic);

}

/*==============================================================
| function: solution
==============================================================*/
template<typename C>
std::vector<std::shared_ptr<search::action<C>>> search::a_star_search<C>::solution(std::shared_ptr<node<C>> node)
{
    std::stack<std::shared_ptr<action<C>>>  sol_stack;
    std::vector<std::shared_ptr<action<C>>> solution;
    std::shared_ptr<search::node<C>> curr_node = node;

    /*the initial state node has a Null action*/
    while( curr_node->action_exec() )
    {   
        sol_stack.push(curr_node->action_exec());   
        curr_node = curr_node->parent();
    }

    while( !sol_stack.empty() )
    {
        solution.push_back(sol_stack.top());
        sol_stack.pop();
    }

    return solution;
}
