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
#include "face.h"

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

namespace cubing
{

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
class rubiks_cube
{
    private:
        std::vector<face> _faces;
        int _n;

        void rotate_front_clock_wise(int squares);
        void rotate_back_clock_wise(int squares);
        void rotate_top_clock_wise(int squares);
        void rotate_bottom_clock_wise(int squares);
        void rotate_right_clock_wise(int squares);
        void rotate_left_clock_wise(int squares);

        void rotate_front_counter_clock_wise(int squares);
        void rotate_back_counter_clock_wise(int squares);
        void rotate_top_counter_clock_wise(int squares);
        void rotate_bottom_counter_clock_wise(int squares);
        void rotate_right_counter_clock_wise(int squares);
        void rotate_left_counter_clock_wise(int squares);

        int face_to_top(int face)    const;
        int face_to_bottom(int face) const;
        int face_to_right(int face)  const;
        int face_to_left(int faces)  const;

    public:
        rubiks_cube(int n, std::vector<face> faces);
        rubiks_cube(int n, face front, face bottom, face right, \
          face left, face top, face back);
        void rotate_face_clock_wise(int face, int squares);
        void rotate_face_counter_clock_wise(int face, int squares);
        int  N() const;
        std::vector<face> faces() const;
        face face(int face) const;
        std::string face_description(int face) const;
        bool solved();
        friend std::ostream& operator<<(std::ostream& os, const rubiks_cube& cube);
        friend bool operator==(const rubiks_cube& cube_1, const rubiks_cube& cube_2);
        friend bool operator!=(const rubiks_cube& cube_1, const rubiks_cube& cube_2);
        friend bool operator<(const rubiks_cube& cube_1, const rubiks_cube& cube_2);
};

} //cubing

#endif