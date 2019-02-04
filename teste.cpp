
#include "Face.h"
#include <vector>

using namespace std;

int main()
{   
    vector<char> aux = {GREEN, RED, ORANGE, WHITE, GREEN, WHITE, BLUE, ORANGE, RED};
    Face face(3, aux);
    cout << face << endl;
    face.rotateClockWise();
    cout << face << endl;
    face.rotateCounterClockWise();
    cout << face << endl;

    vector<char> column = face.getColumn(2);
    for(int i=0; i<face.getN(); i++)
        cout << column[i] << ' ';
    cout << endl;
}