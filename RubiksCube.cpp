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

RubiksCube::RubiksCube(int n, vector<Face> faces)
{
    _faces = faces;
    _n = n;
}

void RubiksCube::rotateFaceClockWise(int face, int squares)
{   
    switch(face)
    {
        case FRONT:
            rotateFrontClockWise(squares);
        case BACK:
            rotateBackClockWise(squares);
        case TOP:
            rotateTopClockWise(squares);
        case BOTTOM:
            rotateBottomClockWise(squares);
        case RIGHT:
            rotateRightClockWise(squares);
        case LEFT:
            rotateLeftClockWise(squares);
    }
}

void RubiksCube::rotateFaceCounterClockWise(int face, int squares)
{
    _faces[face].rotateCounterClockWise();
}

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

int RubiksCube::getFaceToTop(int face)
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

int RubiksCube::getFaceToBottom(int face)
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

int RubiksCube::getFaceToRight(int face)
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

int RubiksCube::getFaceToLeft(int face)
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