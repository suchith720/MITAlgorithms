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
    Location() {}
};

//Having a destructor here will create a problem of dangling pointer.
//Its better if its main's responsibity to delete the array from the heap
class PeakProblem
{
    int **m_array, 
    int m_startRow, m_startCol, m_numRow, m_numCol;

    public :

    PeakProblem();
    PeakProblem(int **array, Bounds bounds);
    int get(Location location);
    void getBetterNeighbor(Location location);
    void getMaximum(int startRow, int startCol, int numRow, int numCol, 
            int &bestR, int &bestC);
    bool isPeak(int r, int c);
};

PeakProblem::PeakProblem()
{
}

PeakProblem::PeakProblem(int **array, Bounds bounds)
{
    self.m_array = array;

    self.m_startRow = bounds.m_startRow;
    self.m_startCol = bounds.m_startCol;
    self.m_numRow = bounds.m_numRow;
    self.m_numCol = bounds.m_numCol;
}

int PeakProblem::get(Location location)
{
    int r = location.m_row, c = location.m_col;
    
    if( ! ( 0 <= r && r < self.m_numRow ) )
        return 0;
    if( ! ( 0 <= c && c < self.m_numCol ) )
        return 0;

    return self.m_array[self.m_startRow + r][ self.m_startCol + c];
}

//add checking
Location PeakProblem::getBetterNeighbor(Location location)
{
    int r = location.m_row, c = location.m_col;

    if( r-1 >=0 && self.get(r-1, c) > self.get(r, c) )
        r = r-1;
    if( c-1 >=0 && self.get(r, c-1) > self.get(r, c) )
        c = c-1;
    if( r+1 < self.m_numRow && self.get(r+1, c) > self.get(r, c) )
        r = r+1;
    if( c+1 < self.m_numCol && self.get(r, c+1) > self.get(r, c) )
        c = c+1;

    return Location(r, c); 

    //add trace

}

Location PeakProblem::getMaximum(Location location)
{
    Location bestLoc(-1, -1);

    int bestVal=0;

    for(int r=0; r < location.r; r++)
    {
        for(int c=0; c < location.c; c++)
        {
            if( bestLoc.r == -1 || self.get(r, c) > bestVal )
            {
                bestLoc.r = r;
                bestLoc.c = c;
                bestVal = self.get(r, c);
            }

        }
    }

    return bestLoc;

    //add trace

}

bool PeakProblem::isPeak(Location location)
{
    Location betterLocation = self.getBetterNeighbor(location);

    if( betterLocation == location)
        return true;
    else
        return false;
}

//Add bound checking
PeakProblem PeakProblem::getSubproblem(Bounds &bounds)
{
    Bounds newBounds = {self.m_startRow + bound.m_startRow, 
        self.m_startCol + bound.m_startCol,
        bound.numRow,
        bound.numCol};

    return PeakProblem(self.m_array, newBounds);
}

//Update with table doubling alogithm
PeakProblem PeakProblem::getSubproblemContaining(Bounds boundList[], int listLen, Location location)
{
    int r = location.m_row, c = location.m_col;
    
    Bounds bounds;

    for(int i=0; i < listLen; i++)
    {
        bounds = boundList[i];

        if( bounds.m_startRow <= r && r < bounds.m_startRow + bounds.m_numRow)
        {
            if( bounds.m_startCol <=c && c < bounds.m_startCol + bounds.m_numCol)
                return self.getSubproblem(bounds);
        }
        
    }
    
    // shouldn't reach here
    return self;

}

Location getLocationInSelf(PeakProblem problem, Location location)
{
    int r = location.m_row, c = location.m_col;
    newRow = r + problem.m_startRow - self.m_startRow;
    newCol = c + problem.m_startCol - self.m_startCol;
    return Location(newRow, newCol);
}
    



    





