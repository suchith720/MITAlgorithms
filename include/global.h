#ifndef __GLOBAL__
#define __GLOBAL__

#include <iostream>
using namespace std;

struct Bounds
{
    int m_startRow, m_startCol, m_numRow, m_numCol;

    Bounds(int startRow, int startCol, int numRow, int numCol): m_startRow(startRow), m_startCol(startCol), m_numRow(numRow), m_numCol(numCol)
    {}

    Bounds() {}

};

struct Location
{
    int m_row,m_col;

    Location(int r, int c): m_row(r), m_col(c) {}
    Location() 
    {
        m_row = m_col = -1;
    }

    bool operator==(const Location &location)
    {
        if( this->m_row == location.m_row && this->m_col == location.m_col )
            return true;
        
        return false;
    }
        
};

#endif  // end for __GLOBAL__

