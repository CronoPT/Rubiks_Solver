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

#ifndef __FACE_H__
#define __FACE_H__ 

#include <vector>
#include <iostream>

using namespace std;

#define WHITE  'W'
#define RED    'R'
#define GREEN  'G'
#define ORANGE 'O'
#define BLUE   'B'
#define YELLOW 'Y'

/*==============================================================
| class: Face - the representation of a Rubik's cube face of
| size _n. For example a standart 3x3 Rubik's cube has 6 
| faces in wich _n = 3.
==============================================================*/
class face
{  
    private:
        vector<char> _squares;
        int _n;

    public:
        face(int n, vector<char> squares);
        int   get_n() const;
        char  get_position_by_index(int index) const;
        char  get_position(int l, int c) const;
        void  set_position(int l, int c, char newSquare);
        vector<char> get_column(int c) const;
        void  set_column(int c, vector<char> squares);
        void  set_column_backwards(int c, vector<char> squares);
        vector<char> get_line(int l) const;
        void  set_line(int l, vector<char> squares);
        void  set_line_backwards(int l, vector<char> squares);
        void  rotate_clock_wise();
        void  rotate_counter_clock_wise();
        bool  all_same_color();
        friend ostream& operator<<(ostream& os, const face& face);
        friend bool     operator==(const face& face_1, const face& face_2);
        friend bool     operator!=(const face& face_1, const face& face_2);   
};

#endif