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
vector<shared_ptr<Action<C>>> search::a_star_search<C>::execute(Problem<C>* problem)
{
    shared_ptr<Node<C>> node = make_shared<Node<C>>(problem->initial_state(), 
                                                    nullptr, nullptr, 0,
                                                    problem->heuristic(
                                                    problem->initial_state()));
    priority_queue<shared_ptr<node<C>>, 
                   vector<shared_ptr<node<C>>>, 
                   std::greater<shared_ptr<node<C>>>> frontier;
    set<C> explored;
    vector<shared_ptr<action<C>>> actions;

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
        for(shared_ptr<action<C>> action : problem->actions(node->state()))
        {
            shared_ptr<node<C>> child = child_node(problem, action, node);

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
shared_ptr<Node<C>> search::a_star_search<C>::child_node(problem<C>* problem, 
                                                         shared_ptr<action<C>> action, 
                                                         shared_ptr<node<C>> parent)
{
    C state = problem->result(parent->state(), action);

    double path_cost = problem->path_cost(parent->path_xost(),
                                          parent->state(), 
                                          action, state);

    double heuristic = problem->heuristic(state);

    return make_shared<node<C>>(state, parent, action, path_cost, heuristic);

}

/*==============================================================
| function: solution
==============================================================*/
template<typename C>
vector<shared_ptr<Action<C>>> search::a_star_search<C>::solution(shared_ptr<Node<C>> node)
{
    stack<shared_ptr<action<C>>>  sol_stack;
    vector<shared_ptr<action<C>>> solution;
    shared_ptr<node<C>> curr_node = node;

    /*the initial state node has a Null action*/
    while( curr_node->action() )
    {   
        sol_stack.push(curr_node->action());
        curr_node = curr_node->parent();
    }

    while( !sol_stack.empty() )
    {
        solution.push_back(sol_stack.top());
        sol_stack.pop();
    }

    return solution;
}
