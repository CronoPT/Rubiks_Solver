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
| function: rubiks_cube Constructor - faces indexing must
| agree with the defines in the .h file
==============================================================*/
rubiks_cube::rubiks_cube(int n, vector<face> faces):
  _faces(faces),
  _n(n)
{

}

rubiks_cube::rubiks_cube(int n, face front, face bottom, \
  face right, face left, face top, face back):
  _faces({front, bottom, right, left, top, back}),
  _n(n)
{

}

/*==============================================================
| function: rotatefaceClockWise
==============================================================*/
void rubiks_cube::rotate_face_clock_wise(int face, int squares)
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
| function: rotatefaceCounterClockWise
==============================================================*/
void rubiks_cube::rotate_face_counter_clock_wise(int face, int squares)
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
int rubiks_cube::get_n() const
{
    return _n;
}

/*==============================================================
| function: getfaces
==============================================================*/
vector<face> rubiks_cube::get_faces() const
{
    return _faces;
}

/*==============================================================
| function: getface - returns the face indexed by "face"
==============================================================*/
face rubiks_cube::get_face(int face) const
{
    return _faces[face];
}

/*==============================================================
| function: getfaceDescription - just a written description of 
| each face
==============================================================*/
string rubiks_cube::get_face_description(int face) const
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
bool rubiks_cube::solved()
{
    for(face face : _faces)
        if(!face.all_same_color())
            return false;

    return true;
}

/*==============================================================
| function: "toString equivalent"
==============================================================*/
ostream& operator<<(ostream& os, const rubiks_cube& cube)
{
    for(int i=0; i<6; i++)
    {
        os << cube.get_face_description(i) << endl;
        os << cube.get_face(i) << endl;
    }
    return os;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator==(const rubiks_cube& cube_1, const rubiks_cube& cube_2)
{
    if(cube_1.get_n() != cube_2.get_n())
        return false;

    for(int i=0; i<6; i++)
        if(cube_1.get_face(i) != cube_2.get_face(i))
            return false;

    return true;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator!=(const rubiks_cube& cube_1, const rubiks_cube& cube_2)
{
    return !(cube_1 == cube_2);
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator<(const rubiks_cube& cube_1, const rubiks_cube& cube_2)
{
    return !(cube_1 == cube_2);
}

/*==============================================================
| function: rotateFrontClockWise
==============================================================*/
void rubiks_cube::rotate_front_clock_wise(int squares)
{
    _faces[FRONT].rotate_clock_wise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {   
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[RIGHT].get_column(start_limit);
        _faces[RIGHT].set_column(start_limit, _faces[TOP].get_line(end_limit));
        turning_column = _faces[BOTTOM].get_line(start_limit);
        _faces[BOTTOM].set_line_backwards(start_limit, turning_line);
        turning_line   = _faces[LEFT].get_column(end_limit);
        _faces[LEFT].set_column(end_limit, turning_column);
        _faces[TOP].set_line_backwards(end_limit, turning_line);
    }
}

/*==============================================================
| function: rotateBackClockWise
==============================================================*/
void rubiks_cube::rotate_back_clock_wise(int squares)
{
    _faces[BACK].rotate_clock_wise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[LEFT].get_column(start_limit);
        _faces[LEFT].set_column_backwards(start_limit, _faces[TOP].get_line(start_limit));
        turning_column = _faces[BOTTOM].get_line(end_limit);
        _faces[BOTTOM].set_line(end_limit, turning_line);
        turning_line   = _faces[RIGHT].get_column(end_limit);
        _faces[RIGHT].set_column_backwards(end_limit, turning_column);
        _faces[TOP].set_line(start_limit, turning_line);
    }
}

/*==============================================================
| function: rotateTopClockWise
==============================================================*/
void rubiks_cube::rotate_top_clock_wise(int squares)
{
    _faces[TOP].rotate_clock_wise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    for(int i=0; i<squares; i++)
    {
        turning_line_1 = _faces[RIGHT].get_line(i);
        _faces[RIGHT].set_line(i, _faces[BACK].get_line(i));
        turning_line_2 = _faces[FRONT].get_line(i);
        _faces[FRONT].set_line(i, turning_line_1);
        turning_line_1 = _faces[LEFT].get_line(i);
        _faces[LEFT].set_line(i, turning_line_2);
        _faces[BACK].set_line(i, turning_line_1);
    }
}

/*==============================================================
| function: rotateBottomClockWise
==============================================================*/
void rubiks_cube::rotate_bottom_clock_wise(int squares)
{
    _faces[BOTTOM].rotate_clock_wise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    int end_limit;
    for(int i=0; i<squares; i++)
    {
        end_limit = _n-i-1;

        turning_line_1 = _faces[RIGHT].get_line(end_limit);
        _faces[RIGHT].set_line(end_limit, _faces[FRONT].get_line(end_limit));
        turning_line_2 = _faces[BACK].get_line(end_limit);
        _faces[BACK].set_line(end_limit, turning_line_1);
        turning_line_1 = _faces[LEFT].get_line(end_limit);
        _faces[LEFT].set_line(end_limit, turning_line_2);
        _faces[FRONT].set_line(end_limit, turning_line_1);
    }
}

/*==============================================================
| function: rotateRightClockWise
==============================================================*/
void rubiks_cube::rotate_right_clock_wise(int squares)
{
    _faces[RIGHT].rotate_clock_wise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[BACK].get_column(start_limit);
        _faces[BACK].set_column_backwards(start_limit, _faces[TOP].get_column(end_limit));
        turning_column_2 = _faces[BOTTOM].get_column(end_limit);
        _faces[BOTTOM].set_column_backwards(end_limit, turning_column_1);
        turning_column_1 = _faces[FRONT].get_column(end_limit);
        _faces[FRONT].set_column(end_limit, turning_column_2);
        _faces[TOP].set_column(end_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateLeftClockWise
==============================================================*/
void rubiks_cube::rotate_left_clock_wise(int squares)
{
    _faces[LEFT].rotate_clock_wise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[FRONT].get_column(start_limit);
        _faces[FRONT].set_column(start_limit, _faces[TOP].get_column(start_limit));
        turning_column_2 = _faces[BOTTOM].get_column(start_limit);
        _faces[BOTTOM].set_column(start_limit, turning_column_1);
        turning_column_1 = _faces[BACK].get_column(end_limit);
        _faces[BACK].set_column_backwards(end_limit, turning_column_2);
        _faces[TOP].set_column_backwards(start_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateFrontCounterClockWise
==============================================================*/
void rubiks_cube::rotate_front_counter_clock_wise(int squares)
{
    _faces[FRONT].rotate_counter_clock_wise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {   
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[LEFT].get_column(end_limit);
        _faces[LEFT].set_column_backwards(end_limit, _faces[TOP].get_line(end_limit));
        turning_column = _faces[BOTTOM].get_line(start_limit);
        _faces[BOTTOM].set_line(start_limit, turning_line);
        turning_line   = _faces[RIGHT].get_column(start_limit);
        _faces[RIGHT].set_column_backwards(start_limit, turning_column);
        _faces[TOP].set_line(end_limit, turning_line);
    }
}

/*==============================================================
| function: rotateBackCounterClockWise
==============================================================*/
void rubiks_cube::rotate_back_counter_clock_wise(int squares)
{
    _faces[BACK].rotate_counter_clock_wise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[RIGHT].get_column(end_limit);
        _faces[RIGHT].set_column(end_limit, _faces[TOP].get_line(start_limit));
        turning_column = _faces[BOTTOM].get_line(end_limit);
        _faces[BOTTOM].set_line_backwards(end_limit, turning_line);
        turning_line   = _faces[LEFT].get_column(start_limit);
        _faces[LEFT].set_column(start_limit, turning_column);
        _faces[TOP].set_line_backwards(start_limit, turning_line);
    }
}

/*==============================================================
| function: rotateTopCOunterClockWise
==============================================================*/
void rubiks_cube::rotate_top_counter_clock_wise(int squares)
{
    _faces[TOP].rotate_counter_clock_wise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    for(int i=0; i<squares; i++)
    {
        turning_line_1 = _faces[LEFT].get_line(i);
        _faces[LEFT].set_line(i, _faces[BACK].get_line(i));
        turning_line_2 = _faces[FRONT].get_line(i);
        _faces[FRONT].set_line(i, turning_line_1);
        turning_line_1 = _faces[RIGHT].get_line(i);
        _faces[RIGHT].set_line(i, turning_line_2);
        _faces[BACK].set_line(i, turning_line_1);
    }
}

/*==============================================================
| function: rotateBottomCounterClockWise
==============================================================*/
void rubiks_cube::rotate_bottom_counter_clock_wise(int squares)
{
    _faces[BOTTOM].rotate_counter_clock_wise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    int end_limit;
    for(int i=0; i<squares; i++)
    {
        end_limit = _n-i-1;

        turning_line_1 = _faces[LEFT].get_line(end_limit);
        _faces[LEFT].set_line(end_limit, _faces[FRONT].get_line(end_limit));
        turning_line_2 = _faces[BACK].get_line(end_limit);
        _faces[BACK].set_line(end_limit, turning_line_1);
        turning_line_1 = _faces[RIGHT].get_line(end_limit);
        _faces[RIGHT].set_line(end_limit, turning_line_2);
        _faces[FRONT].set_line(end_limit, turning_line_1);
    }
}

/*==============================================================
| function: rotateRightCounterClockWise
==============================================================*/
void rubiks_cube::rotate_right_counter_clock_wise(int squares)
{
    _faces[RIGHT].rotate_counter_clock_wise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[FRONT].get_column(end_limit);
        _faces[FRONT].set_column(end_limit, _faces[TOP].get_column(end_limit));
        turning_column_2 = _faces[BOTTOM].get_column(end_limit);
        _faces[BOTTOM].set_column(end_limit, turning_column_1);
        turning_column_1 = _faces[BACK].get_column(start_limit);
        _faces[BACK].set_column_backwards(start_limit, turning_column_2);
        _faces[TOP].set_column_backwards(end_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateLeftCounterClockWise
==============================================================*/
void rubiks_cube::rotate_left_counter_clock_wise(int squares)
{
    _faces[LEFT].rotate_counter_clock_wise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[BACK].get_column(end_limit);
        _faces[BACK].set_column_backwards(end_limit, _faces[TOP].get_column(start_limit));
        turning_column_2 = _faces[BOTTOM].get_column(start_limit);
        _faces[BOTTOM].set_column_backwards(start_limit, turning_column_1);
        turning_column_1 = _faces[FRONT].get_column(start_limit);
        _faces[FRONT].set_column(start_limit, turning_column_2);
        _faces[TOP].set_column(start_limit, turning_column_1);
    }
}

/*==============================================================
| function: getfaceToTop - if you turn the face "face" to you
| this function returns the face above it (index)
==============================================================*/
int rubiks_cube::get_face_to_top(int face) const
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
| function: getfaceToBottom - if you turn the face "face" to you
| this function returns the face bellow it (index)
==============================================================*/
int rubiks_cube::get_face_to_bottom(int face) const
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
| function: getfaceToRight - if you turn the face "face" to you
| this function returns the face to its right (index)
==============================================================*/
int rubiks_cube::get_face_to_right(int face) const
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
| function: getfaceToLeft - if you turn the face "face" to you
| this function returns the face to its left (index)
==============================================================*/
int rubiks_cube::get_face_to_left(int face) const
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
