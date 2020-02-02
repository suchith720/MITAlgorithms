#ifndef __GLOBAL__
#define __GLOBAL__

#include <iostream>
using namespace std;

struct Bounds
{
    int m_startRow, m_startCol, m_numRow, m_numCol;

    Bounds(int startRow, int startCol, int numRow, int numCol);

    Bounds();

};

struct Location
{
    int m_row,m_col;

    Location(int r, int c);

    Location();

    bool operator==(const Location &location);
        
};

#endif  // end for __GLOBAL__

