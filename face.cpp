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
face::face(int n, vector<char> squares):
  _squares(squares),
  _n(n)
{

}

/*==============================================================
| function: getN
==============================================================*/
int face::get_n() const
{
    return _n;
}

/*==============================================================
| function: getPositionByIndex
==============================================================*/
char face::get_position_by_index(int index) const
{
    return _squares[index];
}

/*==============================================================
| function: getPosition - get the contents, i.e color, of
| a given position
==============================================================*/
char face::get_position(int l, int c) const
{
    return _squares[l*_n + c];
}

/*==============================================================
| function: setPosition - set the contents, i.e color, of
| a given position
==============================================================*/
void face::set_position(int l, int c, char new_square)
{
    _squares[l*_n + c] = new_square;
}

/*==============================================================
| function: getColumn
==============================================================*/
vector<char> face::get_column(int c) const
{
    vector<char> column(_n, 0);

    for(int i=0; i<_n; i++)
        column[i] = get_position(i, c);

    return column;
}

/*==============================================================
| function: setColumn
==============================================================*/
void face::set_column(int c, vector<char> new_column)
{
    for(int i=0; i<_n; i++)
        set_position(i, c, new_column[i]);
}

/*==============================================================
| function: setColumnBackwards
==============================================================*/
void face::set_column_backwards(int c, vector<char> new_column)
{
    for(int i=0; i<_n; i++)
        set_position(i, c, new_column[_n-i-1]);
}

/*==============================================================
| function: getLine
==============================================================*/
vector<char> face::get_line(int l) const
{
    vector<char> line(_n, 0);

    for(int i=0; i<_n; i++)
        line[i] = get_position(l, i);

    return line;
}

/*==============================================================
| function: setLine
==============================================================*/
void face::set_line(int l, vector<char> new_line)
{
    for(int i=0; i<_n; i++)
        set_position(l, i, new_line[i]);
}

/*==============================================================
| function: setLineBackwards\
==============================================================*/
void face::set_line_backwards(int l, vector<char> new_line)
{
    for(int i=0; i<_n; i++)
        set_position(l, i, new_line[_n-i-1]);
}

/*==============================================================
| function: rotateClockWise
==============================================================*/
void face::rotate_clock_wise()
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
            set_position(new_l, new_c, old_face[l*_n + c]);
        }
}

/*==============================================================
| function: rotateCounterClockWise
==============================================================*/
void face::rotate_counter_clock_wise()
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
            set_position(new_l, new_c, old_face[l*_n + c]);
        }
}

/*==============================================================
| function: allSameColor
==============================================================*/
bool face::all_same_color()
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
ostream& operator<<(ostream& os, const face& face)
{   
    int n = face.get_n();
    for(int l=0; l<n; l++)
    {
        for(int c=0; c<n; c++)
        {   
            os << face.get_position(l, c) << ' ';
        }
        os << endl; 
    }
    return os;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator==(const face& face_1, const face& face_2)
{
    if(face_1.get_n() != face_2.get_n())
        return false;

    int n = face_1.get_n();

    for(int i=0; i<n; i++)
        if(face_1.get_position_by_index(i) != face_2.get_position_by_index(i))
            return false;

    return true;
}

/*==============================================================
| function: "comparison"
==============================================================*/
bool operator!=(const face& face_1, const face& face_2)
{
    return !(face_1 == face_2);
}