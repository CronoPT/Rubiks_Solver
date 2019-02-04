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

#ifndef __RUBIKSCUBE_H__
#define __RUBIKSCUBE_H__ 

#include <vector>
#include <iostream>
#include "Face.h"

using namespace std;

/*==============================================================
| Just following the layout of a regular d6 die. Every oposing
| face sums 5 (7 in a regular die).
==============================================================*/
#define FRONT  0
#define BACK   5
#define TOP    4
#define BOTTOM 1 
#define RIGHT  2
#define LEFT   3

/*==============================================================
| class: Rubik's Cube
==============================================================*/
class RubiksCube
{
    private:
        vector<Face> _faces;
        int _n;

    public:
        RubiksCube(int n, vector<Face> faces);
        void rotateFaceClockWise(int face, int squares);
        void rotateFaceCounterClockWise(int face, int squares);
};

#endif