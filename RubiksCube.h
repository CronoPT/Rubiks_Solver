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
#include <string>
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
| 
| Rotating:
|     * back: as if you turned the back face to you, leaving
|     the top face faced up
|     * top: as if you turned the top face to you, leaving 
|     the back face faced up
|     * right: as if you turner the right face to you, leaving
|     the top face faced up
|     * left: as if you turner the left face to you, leaving
|     the top face faced up
|     * bottom: as if you turned the bottom face to you, leaving 
|     the front face faced up
==============================================================*/
class RubiksCube
{
    private:
        vector<Face> _faces;
        int _n;

        void rotateFrontClockWise(int squares);
        void rotateBackClockWise(int squares);
        void rotateTopClockWise(int squares);
        void rotateBottomClockWise(int squares);
        void rotateRightClockWise(int squares);
        void rotateLeftClockWise(int squares);

        void rotateFrontCounterClockWise(int squares);
        void rotateBackCounterClockWise(int squares);
        void rotateTopCounterClockWise(int squares);
        void rotateBottomCounterClockWise(int squares);
        void rotateRightCounterClockWise(int squares);
        void rotateLeftCounterClockWise(int squares);

        int getFaceToTop(int face) const;
        int getFaceToBottom(int face) const;
        int getFaceToRight(int face) const;
        int getFaceToLeft(int faces) const;

    public:
        RubiksCube(int n, vector<Face> faces);
        RubiksCube(int n, Face front, Face bottom, Face right, \
          Face left, Face top, Face back);
        void   rotateFaceClockWise(int face, int squares);
        void   rotateFaceCounterClockWise(int face, int squares);
        Face   getFace(int face) const;
        string getFaceDescription(int face) const;
        bool   solved();
        friend ostream &operator<<(ostream &os, const RubiksCube &cube);
};

#endif