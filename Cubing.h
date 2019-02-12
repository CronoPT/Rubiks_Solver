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

#ifndef __CUBING_H__
#define __CUBING_H__

#include "Search/Problem.h"
#include "Search/Action.h"
#include "RubiksCube.h"

#include "CubeActions/rotateBackClockWise.h"
#include "CubeActions/rotateBackCounterClockWise.h"
#include "CubeActions/rotateFrontClockWise.h"
#include "CubeActions/rotateFrontCounterClockWise.h"
#include "CubeActions/rotateTopClockWise.h"
#include "CubeActions/rotateTopCounterClockWise.h"
#include "CubeActions/rotateBottomClockWise.h"
#include "CubeActions/rotateBottomCounterClockWise.h"
#include "CubeActions/rotateRightClockWise.h"
#include "CubeActions/rotateRightCounterClockWise.h"
#include "CubeActions/rotateLeftClockWise.h"
#include "CubeActions/rotateLeftCounterClockWise.h"

class Cubing: public Problem<RubiksCube>
{
    public:
        Cubing(RubiksCube cube): Problem<RubiksCube>(cube) {}

        vector<Action<RubiksCube>*> actions(RubiksCube cube)
        {   
            vector<Action<RubiksCube>*> res;
            for(int i=1; i<=(int)cube.getN()/2; i++)
            {
                res.push_back(new rotateBackClockWise(i));
                res.push_back(new rotateBackCounterClockWise(i));
                res.push_back(new rotateFrontClockWise(i));
                res.push_back(new rotateFrontCounterClockWise(i));
                res.push_back(new rotateTopClockWise(i));
                res.push_back(new rotateTopCounterClockWise(i));
                res.push_back(new rotateBottomClockWise(i));
                res.push_back(new rotateBottomCounterClockWise(i));
                res.push_back(new rotateRightClockWise(i));
                res.push_back(new rotateRightCounterClockWise(i));
                res.push_back(new rotateLeftClockWise(i));
                res.push_back(new rotateLeftCounterClockWise(i));
            }
        
            for(Action<RubiksCube>* a : res)
                cout << *a << endl;

            return res;
        }

        bool goalTest(RubiksCube cube)
        {
            return cube.solved();
        }

        double pathCost(double cost, RubiksCube state_1, Action<RubiksCube>* action, RubiksCube state_2)
        {
            return cost + 1 - heuristic(state_1) + heuristic(state_2);
        }

        double heuristic(RubiksCube cube)
        {
            int to_subtract = 0;
            int n = cube.getN();
            for(Face face : cube.getFaces())
                for(int l=0; l<n; l++)
                    for(int c=0; c<n; c++)
                    {
                        if(c > 1)
                            if(face.getPosition(l, c) == face.getPosition(l, c-1))
                                to_subtract++;
                        if(c < n-1)
                            if(face.getPosition(l, c) == face.getPosition(l, c+1))
                                to_subtract++;
                        if(l > 1)
                            if(face.getPosition(l, c) == face.getPosition(l-1, c))
                                to_subtract++;
                        if(l < n-1)
                            if(face.getPosition(l, c) == face.getPosition(l+1, c))
                                to_subtract++;
                    }
            return n*n*6*4 - to_subtract;
        }
};

#endif