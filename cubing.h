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

#include "CubeActions/RotateBackClockWise.h"
#include "CubeActions/RotateBackCounterClockWise.h"
#include "CubeActions/RotateFrontClockWise.h"
#include "CubeActions/RotateFrontCounterClockWise.h"
#include "CubeActions/RotateTopClockWise.h"
#include "CubeActions/RotateTopCounterClockWise.h"
#include "CubeActions/RotateBottomClockWise.h"
#include "CubeActions/RotateBottomCounterClockWise.h"
#include "CubeActions/RotateRightClockWise.h"
#include "CubeActions/RotateRightCounterClockWise.h"
#include "CubeActions/RotateLeftClockWise.h"
#include "CubeActions/RotateLeftCounterClockWise.h"

#include <memory>

class Cubing: public Problem<RubiksCube>
{
    public:
        Cubing(RubiksCube cube): Problem<RubiksCube>(cube) {}

        vector<shared_ptr<Action<RubiksCube>>> actions(RubiksCube cube) override
        {   
            vector<shared_ptr<Action<RubiksCube>>> res;
            for(int i=1; i<=(int)cube.getN()/2; i++)
            {
                res.push_back(make_shared<RotateBackClockWise>(RotateBackClockWise(i)));
                res.push_back(make_shared<RotateBackCounterClockWise>(RotateBackCounterClockWise(i)));
                res.push_back(make_shared<RotateFrontClockWise>(RotateFrontClockWise(i)));
                res.push_back(make_shared<RotateFrontCounterClockWise>(RotateFrontCounterClockWise(i)));
                res.push_back(make_shared<RotateTopClockWise>(RotateTopClockWise(i)));
                res.push_back(make_shared<RotateTopCounterClockWise>(RotateTopCounterClockWise(i)));
                res.push_back(make_shared<RotateBottomClockWise>(RotateBottomClockWise(i)));
                res.push_back(make_shared<RotateBottomCounterClockWise>(RotateBottomCounterClockWise(i)));
                res.push_back(make_shared<RotateRightClockWise>(RotateRightClockWise(i)));
                res.push_back(make_shared<RotateRightCounterClockWise>(RotateRightCounterClockWise(i)));
                res.push_back(make_shared<RotateLeftClockWise>(RotateLeftClockWise(i)));
                res.push_back(make_shared<RotateLeftCounterClockWise>(RotateLeftCounterClockWise(i))); 
            }

            return res;
        }

        bool goalTest(RubiksCube cube) override
        {
            return cube.solved();
        }

        double heuristic(RubiksCube cube) const override
        {
            return 0;
            if(cube.solved())
                return 0;

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