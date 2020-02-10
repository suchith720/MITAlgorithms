#include "algorithms.h"

Location algorithm1(PeakProblem &problem, TraceRecord trace, Location location, bool rowSplit)
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <= 0 )
        return Location();

    int mid = problemBounds.m_numCol / 2;
    
    int subStartR = 0, subNumR = problemBounds.m_numRow;
    int subStartC1 = 0, subNumC1 = mid;
    int subStartC2 = mid + 1, subNumC2 = problemBounds.m_numCol - (mid + 1);

    Bounds subproblems[2];

    subproblems[0] = Bounds(subStartR, subStartC1, subNumR, subNumC1);
    subproblems[1] = Bounds(subStartR, subStartC2, subNumR, subNumC2);

    Location divider( -1, mid);

    Location bestLoc = problem.getMaximum(divider, trace);

    Location neighbor = problem.getBetterNeighbor(bestLoc, trace);

    if( neighbor == bestLoc )
    {
        if( trace.getTraceRecordStatus() )
            trace.foundPeak(bestLoc);

        return bestLoc;
    }

    PeakProblem sub = problem.getSubproblemContaining(subproblems, 2, neighbor);

    if( trace.getTraceRecordStatus() )
        trace.setProblemDimensions(sub); 

    Location result = algorithm1(sub, trace);

    return problem.getLocationInSelf(sub, result);

}

Location algorithm2(PeakProblem &problem, TraceRecord trace, Location location, bool rowSplit)
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <=0 )
        return Location();

    Location nextLocation = problem.getBetterNeighbor(location, trace);

    if( nextLocation == location)
    {
        if(trace.getTraceRecordStatus() )
            trace.foundPeak(location);
    
        return nextLocation;
    }
    else
        return algorithm2(problem, trace, nextLocation);

}

Location algorithm3(PeakProblem &problem, TraceRecord trace, Location bestSeen, bool rowSplit)
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <=0 )
        return Location();

    int midRow = problemBounds.m_numRow / 2;
    int midCol = problemBounds.m_numCol / 2;

    Bounds subproblems[4];
    
    int subStartR1 = 0, subNumR1 = midRow;
    int subStartR2 = midRow + 1, subNumR2 = problemBounds.m_numRow - (midRow + 1);
    int subStartC1 = 0, subNumC1 = midCol;
    int subStartC2 = midCol + 1, subNumC2 = problemBounds.m_numCol - (midCol + 1);

    subproblems[0] = Bounds(subStartR1, subStartC1, subNumR1, subNumC1);
    subproblems[1] = Bounds(subStartR1, subStartC2, subNumR1, subNumC2);
    subproblems[2] = Bounds(subStartR2, subStartC1, subNumR2, subNumC1);
    subproblems[3] = Bounds(subStartR2, subStartC2, subNumR2, subNumC2);

    Location cross(midRow, midCol);

    Location crossLoc = problem.getMaximum(cross, trace);
    Location neighbor = problem.getBetterNeighbor(crossLoc, trace);

    if( bestSeen.m_row == -1 || problem.get(neighbor) > problem.get(bestSeen) )
    {
        bestSeen = neighbor;

        if(trace.getTraceRecordStatus() )
            trace.setBestSeen(bestSeen);
    }
        
    if( crossLoc == neighbor)
    {
        if(trace.getTraceRecordStatus() )
            trace.foundPeak(crossLoc);

        return crossLoc;
    }

    PeakProblem sub = problem.getSubproblemContaining(subproblems, 4, bestSeen);
    Location newBest = sub.getLocationInSelf(problem, bestSeen);

    if(trace.getTraceRecordStatus() )
        trace.setProblemDimensions(sub);

    Location result = algorithm3(sub, trace, newBest);
    return problem.getLocationInSelf(sub, result);
}

Location algorithm4(PeakProblem &problem, TraceRecord trace, Location bestSeen, bool rowSplit)
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <=0 )
        return Location();

    Bounds subproblems[2];
    Location divider;

    if( rowSplit )
    {
        int mid = problemBounds.m_numRow / 2;

        int subStartR1 = 0, subNumR1 = mid;
        int subStartR2 = mid + 1, subNumR2 = problemBounds.m_numRow - (mid + 1);
        int subStartC = 0, subNumC = problemBounds.m_numCol;

        subproblems[0] = Bounds(subStartR1, subStartC, subNumR1, subNumC);
        subproblems[1] = Bounds(subStartR2, subStartC, subNumR2, subNumC);

        divider = Location( mid , -1 );

    }
    else
    {
        int mid = problemBounds.m_numCol / 2;

        int subStartR = 0, subNumR = problemBounds.m_numRow;
        int subStartC1 = 0, subNumC1 = mid;
        int subStartC2 = mid + 1, subNumC2 = problemBounds.m_numCol - (mid + 1);
        
        subproblems[0] = Bounds(subStartR, subStartC1, subNumR, subNumC1);
        subproblems[1] = Bounds(subStartR, subStartC2, subNumR, subNumC2);

        divider = Location( -1 , mid );
    }

    Location bestLoc = problem.getMaximum(divider, trace);

    Location neighbor = problem.getBetterNeighbor(bestLoc, trace);

    if( bestSeen.m_row == -1 || problem.get(neighbor) > problem.get(bestSeen) )
    {
        bestSeen = neighbor;

        if(trace.getTraceRecordStatus() )
            trace.setBestSeen(bestSeen);
    }

    if( neighbor == bestLoc || problem.get(bestLoc) >= problem.get(bestSeen) )
    {
        if(trace.getTraceRecordStatus() )
            trace.foundPeak(bestLoc);

        return bestLoc;
    }

    PeakProblem sub = problem.getSubproblemContaining(subproblems, 2, bestSeen);

    Location newBest = problem.getLocationInSelf(sub, bestSeen);

    if( trace.getTraceRecordStatus() )
        trace.setProblemDimensions(sub);

    Location result = algorithm4( sub, trace, newBest, !rowSplit);

    return problem.getLocationInSelf(sub, result);

}





    

