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

#define WHITE  'W'
#define RED    'R'
#define GREEN  'G'
#define ORANGE 'O'
#define BLUE   'B'
#define YELLOW 'Y'

namespace cubing 
{

/*==============================================================
| class: Face - the representation of a Rubik's cube face of
| size _n. For example a standart 3x3 Rubik's cube has 6 
| faces in wich _n = 3.
==============================================================*/
class face
{  
    private:
        std::vector<char> _squares;
        int _n;

    public:
        face(int n, std::vector<char> squares);
        int  N() const;
        char position_by_index(int index) const;
        char position(int l, int c) const;
        void position(int l, int c, char newSquare);
        std::vector<char> column(int c) const;
        void column(int c, std::vector<char> squares);
        void column_backwards(int c, std::vector<char> squares);
        std::vector<char> line(int l) const;
        void line(int l, std::vector<char> squares);
        void line_backwards(int l, std::vector<char> squares);
        void rotate_clock_wise();
        void rotate_counter_clock_wise();
        bool all_same_color();
        friend std::ostream& operator<<(std::ostream& os, const face& face);
        friend bool operator==(const face& face_1, const face& face_2);
        friend bool operator!=(const face& face_1, const face& face_2);   
};

} //cubing

#endif