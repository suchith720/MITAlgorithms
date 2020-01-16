#include <iostream>
//#include "trace.h"

//Add trace at the end
//Make thing const as far as possible

struct Bounds
{
    int m_startRow, m_startCol, m_numRow, m_numCol;

    Bounds(int startRow, int startCol, int numRow, int numCol): m_startRow(startRow), m_startCol(startCol), m_numRow(numRow), m_numCol(numCol)
    {}

    Bounds() {}

};

//new feature tried
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

/*
struct CrossProduct
{
    Bounds bounds; 

    Location location;

    CrossProduct(const Bounds &bounds,const Location &location): bounds(bounds), location(location)
    {}

    CrossProduct()
    {
        location.m_row = location.m_col = -1;
    }

};
*/

    

//Having a destructor here will create a problem of dangling pointer.
//Its better if its main's responsibity to delete the array from the heap

class PeakProblem
{
    const int *const *const m_array; 
    int m_startRow, m_startCol, m_numRow, m_numCol;

    public :

    PeakProblem();
    PeakProblem(const int *const *const array, Bounds bounds);
    //reason for const is, temporary object cannot have non-const reference.
    int get(const Location &location);
    Location getBetterNeighbor(const Location &location);
    Location getMaximum(const Bounds &locations);
    bool isPeak(const Location &location);
    PeakProblem getSubproblem(const Bounds &bounds);
    PeakProblem getSubproblemContaining(const Bounds boundList[], int listLen, const Location &location);
    Location getLocationInSelf(const PeakProblem &problem,const Location &location);

    //Helper function
    Bounds getBounds();
};
