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

PeakProblem::PeakProblem():m_array(NULL)
{
}

PeakProblem::PeakProblem(const int *const *const array,const Bounds bounds): m_array(array)
{
    this->m_startRow = bounds.m_startRow;
    this->m_startCol = bounds.m_startCol;
    this->m_numRow = bounds.m_numRow;
    this->m_numCol = bounds.m_numCol;
}

int PeakProblem::get(const Location &location)
{
    int r = location.m_row, c = location.m_col;
    
    if( ! ( 0 <= r && r < this->m_numRow ) )
        return 0;
    if( ! ( 0 <= c && c < this->m_numCol ) )
        return 0;

    return this->m_array[this->m_startRow + r][ this->m_startCol + c];
}

//add checking
Location PeakProblem::getBetterNeighbor(const Location &location)
{
    int r = location.m_row, c = location.m_col;

    if( r-1 >=0 && this->get(Location(r-1, c)) > this->get(Location(r, c)) )
        r = r-1;
    if( c-1 >=0 && this->get(Location(r, c-1)) > this->get(Location(r, c)) )
        c = c-1;
    if( r+1 < this->m_numRow && this->get(Location(r+1, c)) > this->get(Location(r, c)) )
        r = r+1;
    if( c+1 < this->m_numCol && this->get(Location(r, c+1)) > this->get(Location(r, c)) )
        c = c+1;

    return Location(r, c); 

    //add trace

}

Location PeakProblem::getMaximum(const Location &locations)
{
    Location bestLoc;

    int bestVal=0;

    int midRow = locations.m_row, midCol = locations.m_col;

    int r, c;
    
    if( midCol > 0 )
    {
        c = midCol;
        for(r=0; r < this->m_numRow ; r++)
        {
             if( bestLoc.m_row == -1 || this->get(Location(r, c)) > bestVal )
             {
                 bestLoc.m_row = r;
                 bestLoc.m_col = c;
                 bestVal = this->get(Location(r, c));
             }
        }
    }
    
    if( midRow > 0 )
    {
        r = midRow;
        for(c=0 ; c < this->m_numCol; c++)
        {

            if( bestLoc.m_row == -1 || this->get(Location(r, c)) > bestVal )
            {
                bestLoc.m_row = r;
                bestLoc.m_col = c;
                bestVal = this->get(Location(r, c));
            }
        }
    }


    return bestLoc;

    //add trace
}

bool PeakProblem::isPeak(const Location &location)
{
    Location betterLocation = this->getBetterNeighbor(location);

    if( betterLocation == location)
        return true;
    else
        return false;
}

//Add bound checking
PeakProblem PeakProblem::getSubproblem(const Bounds &bounds)
{
    int startRow = bounds.m_startRow, startCol = bounds.m_startCol;
    int numRow = bounds.m_numRow, numCol = bounds.m_numCol;

    if( ! ( startRow >= 0 && startRow + numRow <= this->m_numRow ) )
        return PeakProblem();

    if( ! ( startCol >= 0 && startCol + numCol <= this->m_numCol ) )
        return PeakProblem();


    Bounds newBounds(this->m_startRow + startRow, 
            this->m_startCol + startCol, numRow, numCol);

    return PeakProblem(this->m_array, newBounds);
}

//Update with table doubling alogithm
PeakProblem PeakProblem::getSubproblemContaining(const Bounds boundList[], int listLen, const Location &location)
{
    int r = location.m_row, c = location.m_col;
    
    Bounds bounds;

    for(int i=0; i < listLen; i++)
    {
        bounds = boundList[i];

        if( bounds.m_startRow <= r && r < bounds.m_startRow + bounds.m_numRow)
        {
            if( bounds.m_startCol <=c && c < bounds.m_startCol + bounds.m_numCol)
                return this->getSubproblem(bounds);
        }
        
    }
    
    // shouldn't reach here
    return *this;

}

Location PeakProblem::getLocationInSelf(const PeakProblem &problem, const Location &location)
{
    int r = location.m_row, c = location.m_col;

    int newRow = r + problem.m_startRow - this->m_startRow;
    int newCol = c + problem.m_startCol - this->m_startCol;

    return Location(newRow, newCol);
}

Bounds PeakProblem::getBounds()
{
    Bounds bounds(this->m_startRow, this->m_startCol, this->m_numRow, this->m_numCol);
    return bounds;
}

    


    





