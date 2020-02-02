#include "global.h"

Bounds::Bounds(int startRow, int startCol, int numRow, int numCol): m_startRow(startRow), m_startCol(startCol), m_numRow(numRow), m_numCol(numCol)
{
}

Bounds::Bounds()
{
}


Location::Location(int r, int c): m_row(r), m_col(c) 
{
}

Location::Location() 
{
    m_row = m_col = -1;
}

bool Location::operator==(const Location &location)
{
    if( this->m_row == location.m_row && this->m_col == location.m_col )
        return true;
    
    return false;
}

