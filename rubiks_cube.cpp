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

#include "rubiks_cube.h"

/*==============================================================
| function: RubiksCube Constructor - faces indexing must
| agree with the defines in the .h file
==============================================================*/
cubing::rubiks_cube::rubiks_cube(int n, std::vector<cubing::cube_face> faces):
  _faces(faces),
  _n(n)
{

}

cubing::rubiks_cube::rubiks_cube(int n, cubing::cube_face front, cubing::cube_face bottom, \
  cubing::cube_face right, cubing::cube_face left, cubing::cube_face top, cubing::cube_face back):
  _faces({front, bottom, right, left, top, back}),
  _n(n)
{

}

/*==============================================================
| function: rotateFaceClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_face_clock_wise(int face, int squares)
{   
    switch(face)
    {
        case FRONT:
            rotate_front_clock_wise(squares);
            break;
        case BACK:
            rotate_back_clock_wise(squares);
            break;
        case TOP:
            rotate_top_clock_wise(squares);
            break;
        case BOTTOM:
            rotate_bottom_clock_wise(squares);
            break;
        case RIGHT:
            rotate_right_clock_wise(squares);
            break;
        case LEFT:
            rotate_left_clock_wise(squares);
            break;
    }
}

/*==============================================================
| function: rotateFaceCounterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_face_counter_clock_wise(int face, int squares)
{   
    switch(face)
    {
        case FRONT:
            rotate_front_counter_clock_wise(squares);
            break;
        case BACK:
            rotate_back_counter_clock_wise(squares);
            break;
        case TOP:
            rotate_top_counter_clock_wise(squares);
            break;
        case BOTTOM:
            rotate_bottom_counter_clock_wise(squares);
            break;
        case RIGHT:
            rotate_right_counter_clock_wise(squares);
            break;
        case LEFT:
            rotate_left_counter_clock_wise(squares);
            break;
    }
}

/*==============================================================
| function: getN
==============================================================*/
int cubing::rubiks_cube::N() const
{
    return _n;
}

/*==============================================================
| function: getFaces
==============================================================*/
std::vector<cubing::cube_face> cubing::rubiks_cube::faces() const
{
    return _faces;
}

/*==============================================================
| function: getFace - returns the face indexed by "face"
==============================================================*/
cubing::cube_face cubing::rubiks_cube::face(int face) const
{
    return _faces[face];
}

/*==============================================================
| function: getFaceDescription - just a written description of 
| each face
==============================================================*/
std::string cubing::rubiks_cube::face_description(int face) const
{   
    switch(face)
    {
        case FRONT:
            return "front";
        case BACK:
            return "back";
        case TOP:
            return "top";
        case BOTTOM:
            return "bottom";
        case RIGHT:
            return "right";
        case LEFT:
            return "left";
    }
}

/*==============================================================
| function: solved - all the faces have a unique color
==============================================================*/
bool cubing::rubiks_cube::solved()
{
    for(cubing::cube_face face : _faces)
        if(!face.all_same_color())
            return false;

    return true;
}

/*==============================================================
| function: "toString equivalent"
==============================================================*/
std::ostream& cubing::operator<<(std::ostream& os, const rubiks_cube& cube)
{
    for(int i=0; i<6; i++)
    {
        os << cube.face_description(i) << std::endl;
        os << cube.face(i) << std::endl;
    }
    return os;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool cubing::operator==(const rubiks_cube& cube_1, const rubiks_cube& cube_2)
{
    if(cube_1.N() != cube_2.N())
        return false;

    for(int i=0; i<6; i++)
        if(cube_1.face(i) != cube_2.face(i))
            return false;

    return true;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool cubing::operator!=(const rubiks_cube& cube_1, const rubiks_cube& cube_2)
{
    return !(cube_1 == cube_2);
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool cubing::operator<(const rubiks_cube& cube_1, const rubiks_cube& cube_2)
{
    return !(cube_1 == cube_2);
}   

/*==============================================================
| function: rotateFrontClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_front_clock_wise(int squares)
{
    _faces[FRONT].rotate_clock_wise();

    std::vector<char> turning_column;
    std::vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {   
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[RIGHT].column(start_limit);
        _faces[RIGHT].column(start_limit, _faces[TOP].line(end_limit));
        turning_column = _faces[BOTTOM].line(start_limit);
        _faces[BOTTOM].line_backwards(start_limit, turning_line);
        turning_line   = _faces[LEFT].column(end_limit);
        _faces[LEFT].column(end_limit, turning_column);
        _faces[TOP].line_backwards(end_limit, turning_line);
    }
}

/*==============================================================
| function: rotateBackClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_back_clock_wise(int squares)
{
    _faces[BACK].rotate_clock_wise();

    std::vector<char> turning_column;
    std::vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[LEFT].column(start_limit);
        _faces[LEFT].column_backwards(start_limit, _faces[TOP].line(start_limit));
        turning_column = _faces[BOTTOM].line(end_limit);
        _faces[BOTTOM].line(end_limit, turning_line);
        turning_line   = _faces[RIGHT].column(end_limit);
        _faces[RIGHT].column_backwards(end_limit, turning_column);
        _faces[TOP].line(start_limit, turning_line);
    }
}

/*==============================================================
| function: rotateTopClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_top_clock_wise(int squares)
{
    _faces[TOP].rotate_clock_wise();

    std::vector<char> turning_line_1;
    std::vector<char> turning_line_2;
    for(int i=0; i<squares; i++)
    {
        turning_line_1 = _faces[RIGHT].line(i);
        _faces[RIGHT].line(i, _faces[BACK].line(i));
        turning_line_2 = _faces[FRONT].line(i);
        _faces[FRONT].line(i, turning_line_1);
        turning_line_1 = _faces[LEFT].line(i);
        _faces[LEFT].line(i, turning_line_2);
        _faces[BACK].line(i, turning_line_1);
    }
}

/*==============================================================
| function: rotateBottomClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_bottom_clock_wise(int squares)
{
    _faces[BOTTOM].rotate_clock_wise();

    std::vector<char> turning_line_1;
    std::vector<char> turning_line_2;
    int end_limit;
    for(int i=0; i<squares; i++)
    {
        end_limit = _n-i-1;

        turning_line_1 = _faces[RIGHT].line(end_limit);
        _faces[RIGHT].line(end_limit, _faces[FRONT].line(end_limit));
        turning_line_2 = _faces[BACK].line(end_limit);
        _faces[BACK].line(end_limit, turning_line_1);
        turning_line_1 = _faces[LEFT].line(end_limit);
        _faces[LEFT].line(end_limit, turning_line_2);
        _faces[FRONT].line(end_limit, turning_line_1);
    }
}

/*==============================================================
| function: rotateRightClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_right_clock_wise(int squares)
{
    _faces[RIGHT].rotate_clock_wise();

    std::vector<char> turning_column_1;
    std::vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[BACK].column(start_limit);
        _faces[BACK].column_backwards(start_limit, _faces[TOP].column(end_limit));
        turning_column_2 = _faces[BOTTOM].column(end_limit);
        _faces[BOTTOM].column_backwards(end_limit, turning_column_1);
        turning_column_1 = _faces[FRONT].column(end_limit);
        _faces[FRONT].column(end_limit, turning_column_2);
        _faces[TOP].column(end_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateLeftClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_left_clock_wise(int squares)
{
    _faces[LEFT].rotate_clock_wise();

    std::vector<char> turning_column_1;
    std::vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[FRONT].column(start_limit);
        _faces[FRONT].column(start_limit, _faces[TOP].column(start_limit));
        turning_column_2 = _faces[BOTTOM].column(start_limit);
        _faces[BOTTOM].column(start_limit, turning_column_1);
        turning_column_1 = _faces[BACK].column(end_limit);
        _faces[BACK].column_backwards(end_limit, turning_column_2);
        _faces[TOP].column_backwards(start_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateFrontCounterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_front_counter_clock_wise(int squares)
{
    _faces[FRONT].rotate_counter_clock_wise();

    std::vector<char> turning_column;
    std::vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {   
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[LEFT].column(end_limit);
        _faces[LEFT].column_backwards(end_limit, _faces[TOP].line(end_limit));
        turning_column = _faces[BOTTOM].line(start_limit);
        _faces[BOTTOM].line(start_limit, turning_line);
        turning_line   = _faces[RIGHT].column(start_limit);
        _faces[RIGHT].column_backwards(start_limit, turning_column);
        _faces[TOP].line(end_limit, turning_line);
    }
}

/*==============================================================
| function: rotateBackCounterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_back_counter_clock_wise(int squares)
{
    _faces[BACK].rotate_counter_clock_wise();

    std::vector<char> turning_column;
    std::vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[RIGHT].column(end_limit);
        _faces[RIGHT].column(end_limit, _faces[TOP].line(start_limit));
        turning_column = _faces[BOTTOM].line(end_limit);
        _faces[BOTTOM].line_backwards(end_limit, turning_line);
        turning_line   = _faces[LEFT].column(start_limit);
        _faces[LEFT].column(start_limit, turning_column);
        _faces[TOP].line_backwards(start_limit, turning_line);
    }
}

/*==============================================================
| function: rotateTopCOunterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_top_counter_clock_wise(int squares)
{
    _faces[TOP].rotate_counter_clock_wise();

    std::vector<char> turning_line_1;
    std::vector<char> turning_line_2;
    for(int i=0; i<squares; i++)
    {
        turning_line_1 = _faces[LEFT].line(i);
        _faces[LEFT].line(i, _faces[BACK].line(i));
        turning_line_2 = _faces[FRONT].line(i);
        _faces[FRONT].line(i, turning_line_1);
        turning_line_1 = _faces[RIGHT].line(i);
        _faces[RIGHT].line(i, turning_line_2);
        _faces[BACK].line(i, turning_line_1);
    }
}

/*==============================================================
| function: rotateBottomCounterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_bottom_counter_clock_wise(int squares)
{
    _faces[BOTTOM].rotate_counter_clock_wise();

    std::vector<char> turning_line_1;
    std::vector<char> turning_line_2;
    int end_limit;
    for(int i=0; i<squares; i++)
    {
        end_limit = _n-i-1;

        turning_line_1 = _faces[LEFT].line(end_limit);
        _faces[LEFT].line(end_limit, _faces[FRONT].line(end_limit));
        turning_line_2 = _faces[BACK].line(end_limit);
        _faces[BACK].line(end_limit, turning_line_1);
        turning_line_1 = _faces[RIGHT].line(end_limit);
        _faces[RIGHT].line(end_limit, turning_line_2);
        _faces[FRONT].line(end_limit, turning_line_1);
    }
}

/*==============================================================
| function: rotateRightCounterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_right_counter_clock_wise(int squares)
{
    _faces[RIGHT].rotate_counter_clock_wise();

    std::vector<char> turning_column_1;
    std::vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[FRONT].column(end_limit);
        _faces[FRONT].column(end_limit, _faces[TOP].column(end_limit));
        turning_column_2 = _faces[BOTTOM].column(end_limit);
        _faces[BOTTOM].column(end_limit, turning_column_1);
        turning_column_1 = _faces[BACK].column(start_limit);
        _faces[BACK].column_backwards(start_limit, turning_column_2);
        _faces[TOP].column_backwards(end_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateLeftCounterClockWise
==============================================================*/
void cubing::rubiks_cube::rotate_left_counter_clock_wise(int squares)
{
    _faces[LEFT].rotate_counter_clock_wise();

    std::vector<char> turning_column_1;
    std::vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[BACK].column(end_limit);
        _faces[BACK].column_backwards(end_limit, _faces[TOP].column(start_limit));
        turning_column_2 = _faces[BOTTOM].column(start_limit);
        _faces[BOTTOM].column_backwards(start_limit, turning_column_1);
        turning_column_1 = _faces[FRONT].column(start_limit);
        _faces[FRONT].column(start_limit, turning_column_2);
        _faces[TOP].column(start_limit, turning_column_1);
    }
}

/*==============================================================
| function: getFaceToTop - if you turn the face "face" to you
| this function returns the face above it (index)
==============================================================*/
int cubing::rubiks_cube::face_to_top(int face) const
{
    switch(face)
    {
        case FRONT:
            return TOP;
        case BACK:
            return TOP;
        case TOP:
            return BACK;
        case BOTTOM:
            return FRONT;
        case RIGHT:
            return TOP;
        case LEFT:
            return TOP;
    }
}

/*==============================================================
| function: getFaceToBottom - if you turn the face "face" to you
| this function returns the face bellow it (index)
==============================================================*/
int cubing::rubiks_cube::face_to_bottom(int face) const
{
    switch(face)
    {
        case FRONT:
            return BOTTOM;
        case BACK:
            return BOTTOM;
        case TOP:
            return FRONT;
        case BOTTOM:
            return BACK;
        case RIGHT:
            return BOTTOM;
        case LEFT:
            return BOTTOM;
    }
}

/*==============================================================
| function: getFaceToRight - if you turn the face "face" to you
| this function returns the face to its right (index)
==============================================================*/
int cubing::rubiks_cube::face_to_right(int face) const
{
    switch(face)
    {
        case FRONT:
            return RIGHT;
        case BACK:
            return LEFT;
        case TOP:
            return RIGHT;
        case BOTTOM:
            return RIGHT;
        case RIGHT:
            return BACK;
        case LEFT:
            return FRONT;
    }
}

/*==============================================================
| function: getFaceToLeft - if you turn the face "face" to you
| this function returns the face to its left (index)
==============================================================*/
int cubing::rubiks_cube::face_to_left(int face) const
{
    switch(face)
    {
        case FRONT:
            return LEFT;
        case BACK:
            return RIGHT;
        case TOP:
            return LEFT;
        case BOTTOM:
            return LEFT;
        case RIGHT:
            return FRONT;
        case LEFT:
            return BACK;
    }
}
