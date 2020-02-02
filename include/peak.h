#ifndef __PEAK_PROBLEM__
#define __PEAK_PROBLEM__

#include <iostream>

#include "trace.h"
#include "global.h"

using namespace std;

class TraceRecord;

//Having a destructor here will create a problem of dangling pointer.
//Its better if its main's responsibity to delete the array from the heap

class PeakProblem
{
    const int *const *m_array; 
    int m_startRow, m_startCol, m_numRow, m_numCol;

    public :

    PeakProblem();

    PeakProblem(const int *const * array, Bounds bounds);

    void loadPeakProblem(const int *const * array, Bounds bounds);

    //reason for const is, temporary object cannot have non-const reference.
    int get(const Location &location);

    Location getBetterNeighbor(const Location &location, TraceRecord trace = TraceRecord() );

    Location getMaximum(const Location &locations, TraceRecord trace = TraceRecord() );

    bool isPeak(const Location &location);

    PeakProblem getSubproblem(const Bounds &bounds);

    PeakProblem getSubproblemContaining(const Bounds boundList[], int listLen, const Location &location);

    Location getLocationInSelf(const PeakProblem &problem,const Location &location);

    //Helper function
    Bounds getBounds();
};

#endif  // end for __PEAK_PROBLEM__

