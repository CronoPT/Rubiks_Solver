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

#include "Face.h"

/*==============================================================
| function: Face Constructor
==============================================================*/
Face::Face(int n, vector<char> squares)
{
    _squares = squares;
    _n = n;
}

/*==============================================================
| function: getN
==============================================================*/
int Face::getN() const
{
    return _n;
}

/*==============================================================
| function: getPositionByIndex
==============================================================*/
char Face::getPositionByIndex(int index) const
{
    return _squares[index];
}

/*==============================================================
| function: getPosition - get the contents, i.e color, of
| a given position
==============================================================*/
char Face::getPosition(int l, int c) const
{
    return _squares[l*_n + c];
}

/*==============================================================
| function: setPosition - set the contents, i.e color, of
| a given position
==============================================================*/
void Face::setPosition(int l, int c, char new_square)
{
    _squares[l*_n + c] = new_square;
}

/*==============================================================
| function: getColumn
==============================================================*/
vector<char> Face::getColumn(int c) const
{
    vector<char> column(_n, 0);

    for(int i=0; i<_n; i++)
        column[i] = getPosition(i, c);

    return column;
}

/*==============================================================
| function: setColumn
==============================================================*/
void Face::setColumn(int c, vector<char> new_column)
{
    for(int i=0; i<_n; i++)
        setPosition(i, c, new_column[i]);
}

/*==============================================================
| function: getLine
==============================================================*/
vector<char> Face::getLine(int l) const
{
    vector<char> line(_n, 0);

    for(int i=0; i<_n; i++)
        line[i] = getPosition(l, i);

    return line;
}

/*==============================================================
| function: setLine
==============================================================*/
void Face::setLine(int l, vector<char> new_line)
{
    for(int i=0; i<_n; i++)
        setPosition(l, i, new_line[i]);
}

/*==============================================================
| function: rotateClockWise
==============================================================*/
void Face::rotateClockWise()
{
    int size = _n*_n;
    vector<char> old_face(size, 0);

    for(int i=0; i<size; i++)
        old_face[i] = _squares[i];

    int new_l, new_c;
    for(int l=0; l<_n; l++)
        for(int c=0; c<_n; c++)
        {
            new_l = c;
            new_c = _n-l-1;
            setPosition(new_l, new_c, old_face[l*_n + c]);
        }
}

/*==============================================================
| function: rotateCounterClockWise
==============================================================*/
void Face::rotateCounterClockWise()
{
    int size = _n*_n;
    vector<char> old_face(size, 0);

    for(int i=0; i<size; i++)
        old_face[i] = _squares[i];

    int new_l, new_c;
    for(int l=0; l<_n; l++)
        for(int c=0; c<_n; c++)
        {
            new_l = _n-c-1;
            new_c = l;
            setPosition(new_l, new_c, old_face[l*_n + c]);
        }
}

/*==============================================================
| function: allSameColor
==============================================================*/
bool Face::allSameColor()
{
    int first_color = _squares[0];

    for(int i=1; i<_n; i++)
        if(_squares[i] != first_color)
            return false;

    return true;
}

/*==============================================================
| function: "toString equivalent"
==============================================================*/
ostream& operator<<(ostream& os, const Face& face)
{   
    int n = face.getN();
    for(int l=0; l<n; l++)
    {
        for(int c=0; c<n; c++)
        {   
            os << face.getPosition(l, c) << ' ';
        }
        os << endl; 
    }
    return os;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator==(const Face& face_1, const Face& face_2)
{
    if(face_1.getN() != face_2.getN())
        return false;

    int n = face_1.getN();

    for(int i=0; i<n; i++)
        if(face_1.getPositionByIndex(i) != face_2.getPositionByIndex(i))
            return false;

    return true;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator!=(const Face& face_1, const Face& face_2)
{
    return !(face_1 == face_2);
}