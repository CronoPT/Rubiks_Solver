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

#include "face.h"

/*==============================================================
| function: Face Constructor
==============================================================*/
cubing::face::face(int n, std::vector<char> squares):
  _squares(squares),
  _n(n)
{

}

/*==============================================================
| function: getN
==============================================================*/
int cubing::face::N() const
{
    return _n;
}

/*==============================================================
| function: getPositionByIndex
==============================================================*/
char cubing::face::position_by_index(int index) const
{
    return _squares[index];
}

/*==============================================================
| function: getPosition - get the contents, i.e color, of
| a given position
==============================================================*/
char cubing::face::position(int l, int c) const
{
    return _squares[l*_n + c];
}

/*==============================================================
| function: setPosition - set the contents, i.e color, of
| a given position
==============================================================*/
void cubing::face::position(int l, int c, char new_square)
{
    _squares[l*_n + c] = new_square;
}

/*==============================================================
| function: getColumn
==============================================================*/
std::vector<char> cubing::face::column(int c) const
{
    std::vector<char> column(_n, 0);

    for(int i=0; i<_n; i++)
        column[i] = position(i, c);

    return column;
}

/*==============================================================
| function: setColumn
==============================================================*/
void cubing::face::column(int c, std::vector<char> new_column)
{
    for(int i=0; i<_n; i++)
        position(i, c, new_column[i]);
}

/*==============================================================
| function: setColumnBackwards
==============================================================*/
void cubing::face::column_backwards(int c, std::vector<char> new_column)
{
    for(int i=0; i<_n; i++)
        position(i, c, new_column[_n-i-1]);
}

/*==============================================================
| function: getLine
==============================================================*/
std::vector<char> cubing::face::line(int l) const
{
    std::vector<char> line(_n, 0);

    for(int i=0; i<_n; i++)
        line[i] = position(l, i);

    return line;
}

/*==============================================================
| function: setLine
==============================================================*/
void cubing::face::line(int l, std::vector<char> new_line)
{
    for(int i=0; i<_n; i++)
        position(l, i, new_line[i]);
}

/*==============================================================
| function: setLineBackwards\
==============================================================*/
void cubing::face::line_backwards(int l, std::vector<char> new_line)
{
    for(int i=0; i<_n; i++)
        position(l, i, new_line[_n-i-1]);
}

/*==============================================================
| function: rotateClockWise
==============================================================*/
void cubing::face::rotate_clock_wise()
{
    int size = _n*_n;
    std::vector<char> old_face(size, 0);

    for(int i=0; i<size; i++)
        old_face[i] = _squares[i];

    int new_l, new_c;
    for(int l=0; l<_n; l++)
        for(int c=0; c<_n; c++)
        {
            new_l = c;
            new_c = _n-l-1;
            position(new_l, new_c, old_face[l*_n + c]);
        }
}

/*==============================================================
| function: rotateCounterClockWise
==============================================================*/
void cubing::face::rotate_counter_clock_wise()
{
    int size = _n*_n;
    std::vector<char> old_face(size, 0);

    for(int i=0; i<size; i++)
        old_face[i] = _squares[i];

    int new_l, new_c;
    for(int l=0; l<_n; l++)
        for(int c=0; c<_n; c++)
        {
            new_l = _n-c-1;
            new_c = l;
            position(new_l, new_c, old_face[l*_n + c]);
        }
}

/*==============================================================
| function: allSameColor
==============================================================*/
bool cubing::face::all_same_color()
{
    char first_color = _squares[0];
    int  size = _n*_n;
    for(int i=1; i<size; i++)
        if(_squares[i] != first_color)
            return false;

    return true;
}

/*==============================================================
| function: "toString equivalent"
==============================================================*/
std::ostream& cubing::operator<<(std::ostream& os, const face& face)
{   
    int n = face.N();
    for(int l=0; l<n; l++)
    {
        for(int c=0; c<n; c++)
        {   
            os << face.position(l, c) << ' ';
        }
        os << std::endl; 
    }
    return os;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool cubing::operator==(const face& face_1, const face& face_2)
{
    if(face_1.N() != face_2.N())
        return false;

    int n = face_1.N();

    for(int i=0; i<n; i++)
        if(face_1.position_by_index(i) != face_2.position_by_index(i))
            return false;

    return true;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool cubing::operator!=(const face& face_1, const face& face_2)
{
    return !(face_1 == face_2);
}