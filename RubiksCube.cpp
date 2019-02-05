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

#include "RubiksCube.h"

/*==============================================================
| function: RubiksCube Constructor - faces indexing must
| agree with the defines in the .h file
==============================================================*/
RubiksCube::RubiksCube(int n, vector<Face> faces)
{
    _faces = faces;
    _n = n;
}

RubiksCube::RubiksCube(int n, Face front, Face bottom, \
  Face right, Face left, Face top, Face back)
{
    _faces = {front, bottom, right, left, top, back};
    _n = n;
}

/*==============================================================
| function: rotateFaceClockWise
==============================================================*/
void RubiksCube::rotateFaceClockWise(int face, int squares)
{   
    switch(face)
    {
        case FRONT:
            rotateFrontClockWise(squares);
            break;
        case BACK:
            rotateBackClockWise(squares);
            break;
        case TOP:
            rotateTopClockWise(squares);
            break;
        case BOTTOM:
            rotateBottomClockWise(squares);
            break;
        case RIGHT:
            rotateRightClockWise(squares);
            break;
        case LEFT:
            rotateLeftClockWise(squares);
            break;
    }
}

/*==============================================================
| function: rotateFaceCounterClockWise
==============================================================*/
void RubiksCube::rotateFaceCounterClockWise(int face, int squares)
{   
    switch(face)
    {
        case FRONT:
            rotateFrontCounterClockWise(squares);
            break;
        case BACK:
            rotateBackCounterClockWise(squares);
            break;
        case TOP:
            rotateTopCounterClockWise(squares);
            break;
        case BOTTOM:
            rotateBottomCounterClockWise(squares);
            break;
        case RIGHT:
            rotateRightCounterClockWise(squares);
            break;
        case LEFT:
            rotateLeftCounterClockWise(squares);
            break;
    }
}

/*==============================================================
| function: getN
==============================================================*/
int RubiksCube::getN() const{
    return _n;
}

/*==============================================================
| function: getFace - returns the face indexed by "face"
==============================================================*/
Face RubiksCube::getFace(int face) const
{
    return _faces[face];
}

/*==============================================================
| function: getFaceDescription - just a written description of 
| each face
==============================================================*/
string RubiksCube::getFaceDescription(int face) const
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
bool RubiksCube::solved()
{
    for(Face face : _faces)
        if(!face.allSameColor())
            return false;

    return true;
}

/*==============================================================
| function: "toString equivalent"
==============================================================*/
ostream& operator<<(ostream& os, const RubiksCube& cube)
{
    for(int i=0; i<6; i++)
    {
        os << cube.getFaceDescription(i) << endl;
        os << cube.getFace(i) << endl;
    }
    return os;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator==(const RubiksCube& cube_1, const RubiksCube& cube_2)
{
    if(cube_1.getN() != cube_2.getN())
        return false;

    for(int i=0; i<6; i++)
        if(cube_1.getFace(i) != cube_2.getFace(i))
            return false;

    return true;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator!=(const RubiksCube& cube_1, const RubiksCube& cube_2)
{
    return !(cube_1 == cube_2);
}

/*==============================================================
| function: rotateFrontClockWise
==============================================================*/
void RubiksCube::rotateFrontClockWise(int squares)
{
    _faces[FRONT].rotateClockWise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {   
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[RIGHT].getColumn(start_limit);
        _faces[RIGHT].setColumn(start_limit, _faces[TOP].getLine(end_limit));
        turning_column = _faces[BOTTOM].getLine(start_limit);
        _faces[BOTTOM].setLine(start_limit, turning_line);
        turning_line   = _faces[LEFT].getColumn(end_limit);
        _faces[LEFT].setColumn(end_limit, turning_column);
        _faces[TOP].setLine(end_limit, turning_line);
    }
}

/*==============================================================
| function: rotateBackClockWise
==============================================================*/
void RubiksCube::rotateBackClockWise(int squares)
{
    _faces[BACK].rotateClockWise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[LEFT].getColumn(start_limit);
        _faces[LEFT].setColumn(start_limit, _faces[TOP].getLine(start_limit));
        turning_column = _faces[BOTTOM].getLine(end_limit);
        _faces[BOTTOM].setLine(end_limit, turning_line);
        turning_line   = _faces[RIGHT].getColumn(end_limit);
        _faces[RIGHT].setColumn(end_limit, turning_column);
        _faces[TOP].setLine(start_limit, turning_line);
    }
}

/*==============================================================
| function: rotateTopClockWise
==============================================================*/
void RubiksCube::rotateTopClockWise(int squares)
{
    _faces[TOP].rotateClockWise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    for(int i=0; i<squares; i++)
    {
        turning_line_1 = _faces[RIGHT].getLine(i);
        _faces[RIGHT].setLine(i, _faces[BACK].getLine(i));
        turning_line_2 = _faces[FRONT].getLine(i);
        _faces[FRONT].setLine(i, turning_line_1);
        turning_line_1 = _faces[LEFT].getLine(i);
        _faces[LEFT].setLine(i, turning_line_2);
        _faces[BACK].setLine(i, turning_line_1);
    }
}

/*==============================================================
| function: rotateBottomClockWise
==============================================================*/
void RubiksCube::rotateBottomClockWise(int squares)
{
    _faces[BOTTOM].rotateClockWise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    int end_limit;
    for(int i=0; i<squares; i++)
    {
        end_limit = _n-i-1;

        turning_line_1 = _faces[RIGHT].getLine(end_limit);
        _faces[RIGHT].setLine(end_limit, _faces[FRONT].getLine(end_limit));
        turning_line_2 = _faces[BACK].getLine(end_limit);
        _faces[BACK].setLine(end_limit, turning_line_1);
        turning_line_1 = _faces[LEFT].getLine(end_limit);
        _faces[LEFT].setLine(end_limit, turning_line_2);
        _faces[FRONT].setLine(end_limit, turning_line_1);
    }
}

/*==============================================================
| function: rotateRightClockWise
==============================================================*/
void RubiksCube::rotateRightClockWise(int squares)
{
    _faces[RIGHT].rotateClockWise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[BACK].getColumn(start_limit);
        _faces[BACK].setColumn(start_limit, _faces[TOP].getColumn(end_limit));
        turning_column_2 = _faces[BOTTOM].getColumn(end_limit);
        _faces[BOTTOM].setColumn(end_limit, turning_column_1);
        turning_column_1 = _faces[FRONT].getColumn(end_limit);
        _faces[FRONT].setColumn(end_limit, turning_column_2);
        _faces[TOP].setColumn(end_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateLeftClockWise
==============================================================*/
void RubiksCube::rotateLeftClockWise(int squares)
{
    _faces[LEFT].rotateClockWise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[FRONT].getColumn(start_limit);
        _faces[FRONT].setColumn(start_limit, _faces[TOP].getColumn(start_limit));
        turning_column_2 = _faces[BOTTOM].getColumn(start_limit);
        _faces[BOTTOM].setColumn(start_limit, turning_column_1);
        turning_column_1 = _faces[BACK].getColumn(end_limit);
        _faces[BACK].setColumn(end_limit, turning_column_2);
        _faces[TOP].setColumn(start_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateFrontCounterClockWise
==============================================================*/
void RubiksCube::rotateFrontCounterClockWise(int squares)
{
    _faces[FRONT].rotateCounterClockWise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {   
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[LEFT].getColumn(end_limit);
        _faces[LEFT].setColumn(end_limit, _faces[TOP].getLine(end_limit));
        turning_column = _faces[BOTTOM].getLine(start_limit);
        _faces[BOTTOM].setLine(start_limit, turning_line);
        turning_line   = _faces[RIGHT].getColumn(start_limit);
        _faces[RIGHT].setColumn(start_limit, turning_column);
        _faces[TOP].setLine(end_limit, turning_line);
    }
}

/*==============================================================
| function: rotateBackCounterClockWise
==============================================================*/
void RubiksCube::rotateBackCounterClockWise(int squares)
{
    _faces[BACK].rotateClockWise();

    vector<char> turning_column;
    vector<char> turning_line;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_line   = _faces[RIGHT].getColumn(end_limit);
        _faces[RIGHT].setColumn(end_limit, _faces[TOP].getLine(start_limit));
        turning_column = _faces[BOTTOM].getLine(end_limit);
        _faces[BOTTOM].setLine(end_limit, turning_line);
        turning_line   = _faces[LEFT].getColumn(start_limit);
        _faces[LEFT].setColumn(start_limit, turning_column);
        _faces[TOP].setLine(start_limit, turning_line);
    }
}

/*==============================================================
| function: rotateTopCOunterClockWise
==============================================================*/
void RubiksCube::rotateTopCounterClockWise(int squares)
{
    _faces[TOP].rotateClockWise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    for(int i=0; i<squares; i++)
    {
        turning_line_1 = _faces[LEFT].getLine(i);
        _faces[LEFT].setLine(i, _faces[BACK].getLine(i));
        turning_line_2 = _faces[FRONT].getLine(i);
        _faces[FRONT].setLine(i, turning_line_1);
        turning_line_1 = _faces[RIGHT].getLine(i);
        _faces[RIGHT].setLine(i, turning_line_2);
        _faces[BACK].setLine(i, turning_line_1);
    }
}

/*==============================================================
| function: rotateBottomCounterClockWise
==============================================================*/
void RubiksCube::rotateBottomCounterClockWise(int squares)
{
    _faces[BOTTOM].rotateClockWise();

    vector<char> turning_line_1;
    vector<char> turning_line_2;
    int end_limit;
    for(int i=0; i<squares; i++)
    {
        end_limit = _n-i-1;

        turning_line_1 = _faces[LEFT].getLine(end_limit);
        _faces[LEFT].setLine(end_limit, _faces[FRONT].getLine(end_limit));
        turning_line_2 = _faces[BACK].getLine(end_limit);
        _faces[BACK].setLine(end_limit, turning_line_1);
        turning_line_1 = _faces[RIGHT].getLine(end_limit);
        _faces[RIGHT].setLine(end_limit, turning_line_2);
        _faces[FRONT].setLine(end_limit, turning_line_1);
    }
}

/*==============================================================
| function: rotateRightCounterClockWise
==============================================================*/
void RubiksCube::rotateRightCounterClockWise(int squares)
{
    _faces[RIGHT].rotateClockWise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[FRONT].getColumn(end_limit);
        _faces[FRONT].setColumn(end_limit, _faces[TOP].getColumn(end_limit));
        turning_column_2 = _faces[BOTTOM].getColumn(end_limit);
        _faces[BOTTOM].setColumn(end_limit, turning_column_1);
        turning_column_1 = _faces[BACK].getColumn(start_limit);
        _faces[BACK].setColumn(start_limit, turning_column_2);
        _faces[TOP].setColumn(end_limit, turning_column_1);
    }
}

/*==============================================================
| function: rotateLeftCounterClockWise
==============================================================*/
void RubiksCube::rotateLeftCounterClockWise(int squares)
{
    _faces[LEFT].rotateClockWise();

    vector<char> turning_column_1;
    vector<char> turning_column_2;
    int start_limit, end_limit;
    for(int i=0; i<squares; i++)
    {
        start_limit = i;
        end_limit   = _n-i-1;

        turning_column_1 = _faces[BACK].getColumn(end_limit);
        _faces[BACK].setColumn(end_limit, _faces[TOP].getColumn(start_limit));
        turning_column_2 = _faces[BOTTOM].getColumn(start_limit);
        _faces[BOTTOM].setColumn(start_limit, turning_column_1);
        turning_column_1 = _faces[FRONT].getColumn(start_limit);
        _faces[FRONT].setColumn(start_limit, turning_column_2);
        _faces[TOP].setColumn(start_limit, turning_column_1);
    }
}

/*==============================================================
| function: getFaceToTop - if you turn the face "face" to you
| this function returns the face above it (index)
==============================================================*/
int RubiksCube::getFaceToTop(int face) const
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
int RubiksCube::getFaceToBottom(int face) const
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
int RubiksCube::getFaceToRight(int face) const
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
int RubiksCube::getFaceToLeft(int face) const
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
