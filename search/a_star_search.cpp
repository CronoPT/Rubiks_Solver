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
vector<shared_ptr<action<C>>> a_star_search<C>::execute(problem<C>* problem)
{
    shared_ptr<node<C>> node = make_shared<::node<C>>(problem->get_initial_state(), 
                                                    nullptr, nullptr, 0,
                                                    problem->heuristic(
                                                    problem->get_initial_state()));
    priority_queue<shared_ptr<::node<C>>, 
                   vector<shared_ptr<::node<C>>>, 
                   std::greater<shared_ptr<::node<C>>>> frontier;
    set<C> explored;
    vector<shared_ptr<action<C>>> actions;

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
        for(shared_ptr<action<C>> action : problem->actions(node->get_state()))
        {
            shared_ptr<::node<C>> child = child_node(problem, action, node);

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
shared_ptr<node<C>> a_star_search<C>::child_node(problem<C>* problem, 
                                              shared_ptr<action<C>> action, 
                                              shared_ptr<node<C>> parent)
{
    C state = problem->result(parent->get_state(), action);

    double path_cost = problem->path_cost(parent->get_path_cost(),
                                         parent->get_state(), 
                                         action, state);

    double heuristic = problem->heuristic(state);

    return make_shared<node<C>>(state, parent, action, path_cost, heuristic);

}

/*==============================================================
| function: solution
==============================================================*/
template<typename C>
vector<shared_ptr<action<C>>> a_star_search<C>::solution(shared_ptr<node<C>> node)
{
    stack<shared_ptr<action<C>>>  sol_stack;
    vector<shared_ptr<action<C>>> solution;
    shared_ptr<::node<C>> curr_node = node;

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
