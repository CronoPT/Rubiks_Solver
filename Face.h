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
class Face
{  
    private:
        vector<char> _squares;
        int _n;

    public:
        Face(int n, vector<char> squares);
        int   getN() const;
        char  getPositionByIndex(int index) const;
        char  getPosition(int l, int c) const;
        void  setPosition(int l, int c, char newSquare);
        vector<char> getColumn(int c) const;
        void  setColumn(int c, vector<char> squares);
        void  setColumnBackwards(int c, vector<char> squares);
        vector<char> getLine(int l) const;
        void  setLine(int l, vector<char> squares);
        void setLineBackwards(int l, vector<char> squares);
        void  rotateClockWise();
        void  rotateCounterClockWise();
        bool  allSameColor();
        friend ostream& operator<<(ostream& os, const Face& face);
        friend bool     operator==(const Face& face_1, const Face& face_2);
        friend bool     operator!=(const Face& face_1, const Face& face_2);   
};

#endif