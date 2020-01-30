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
std::vector<std::shared_ptr<search::action<C>>> search::a_star_search<C>::execute(search::problem<C>* problem)
{
    std::shared_ptr<node<C>> node = std::make_shared<search::node<C>>(problem->get_initial_state(), 
                                                                 nullptr, nullptr, 0,
                                                                 problem->heuristic(
                                                                 problem->get_initial_state()));
    std::priority_queue<std::shared_ptr<search::node<C>>, 
                        std::vector<std::shared_ptr<search::node<C>>>, 
                        std::greater<std::shared_ptr<search::node<C>>>> frontier;
    std::set<C> explored;
    std::vector<std::shared_ptr<action<C>>> actions;

    frontier.push(node);
    explored.insert(node->get_state());
    int depth = 0;
    while(!frontier.empty())
    {
        node = frontier.top(); /*chooses the lowest-cost node in frontier*/
        frontier.pop();

        if( problem->goal_test(node->get_state()) )  
            return solution(node); /*builds a vector with the actions*/
        
        explored.insert(node->get_state());

        /*expansion*/
        for(std::shared_ptr<action<C>> action : problem->actions(node->get_state()))
        {
            std::shared_ptr<search::node<C>> child = child_node(problem, action, node);

            if( explored.count(child->get_state())==0 )
            {    
                frontier.push(child);
            }
        }
    } 
    //throw some exception indicating the problem has no solution        
}

/*==============================================================
| function: childnode
==============================================================*/
template<typename C>
std::shared_ptr<search::node<C>> search::a_star_search<C>::child_node(search::problem<C>* problem, 
                                                                      std::shared_ptr<action<C>> action, 
                                                                      std::shared_ptr<node<C>> parent)
{
    C state = problem->result(parent->get_state(), action);

    double path_cost = problem->path_cost(parent->get_path_cost(),
                                         parent->get_state(), 
                                         action, state);

    double heuristic = problem->heuristic(state);

    return std::make_shared<node<C>>(state, parent, action, path_cost, heuristic);

}

/*==============================================================
| function: solution
==============================================================*/
template<typename C>
std::vector<std::shared_ptr<search::action<C>>> search::a_star_search<C>::solution(std::shared_ptr<search::node<C>> node)
{
    std::stack<std::shared_ptr<action<C>>>  sol_stack;
    std::vector<std::shared_ptr<action<C>>> solution;
    std::shared_ptr<search::node<C>> curr_node = node;

    /*the initial state node has a Null action*/
    while( curr_node->get_action() )
    {   
        sol_stack.push(curr_node->get_action());
        curr_node = curr_node->get_parent();
    }

    while( !sol_stack.empty() )
    {
        solution.push_back(sol_stack.top());
        sol_stack.pop();
    }

    return solution;
}
