#include <iostream>
#include "peak.h"

using namespace std;

Location algorithm1(const PeakProblem &problem)
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <= 0 )
        return Location();

    int mid = problemBounds.m_numCol / 2;
    
    int subStartR = 0, subNumR = problem.m_numRow;
    int subStartC1 = 0, subNumC1 = mid;
    int subStartC2 = mid + 1, subNumC2 = problem.m_numCol - (mid + 1);

    Bounds subproblems[2];

    subproblems[0] = Bounds(subStartR, subStartC1, subNumR, subNumC1);
    subproblems[1] = Bounds(subStartR, subStartC2, subNumR, subNumC2);

    Location divider( -1, mid);

    Location bestLoc = problem.getMaximum(divider);

    Location neighbor = problem.getBetterNeighbor(bestLoc);

    if( neighbor == bestLoc )
        return bestLoc;

    PeakProblem sub = problem.getSubproblemContaining(subproblems, 2, neighbor);

    Location result = algorithm1(sub);

    return problem.getLocationInSelf(sub, result);

}

Location algorithm2(const PeakProblem &problem, const Location &location = location(0,0) )
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <=0 )
        return Location();

    Location nextLocation = problem.getBetterNeighbor(location);

    if( mexLocation == location)
        return nextLocation;
    else
        return algorithm2(problem, nextLocation);

}

Location algorithm3(const PeakProblem &problem, const Location &bestseen = location() )
{
    Bounds problemBounds = problem.getBounds();

    if( problemBounds.m_numRow <=0 || problemBounds.m_numCol <=0 )
        return Location();

    int midRow = problem.m_numRow / 2;
    int midCol = problem.m_numCol / 2;

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

    Location crossLoc = problem.getMaximum(cross);
    Location neighbor = problem.getBetterNeighbor(crossLoc);

    if( bestSeen.m_row == -1 || problem.get(neighbor) > problem.get(bestSeen) )
        bestSeen = neighbor;

    if( crossLoc == neighbor)
        return crossLoc;

    PeakProblem sub = problem.getSubproblemContaining(subproblems, 4, bestSeen);
    Location newBest = sub.getLocationInSelf(problem, bestSeen);

    Location result = algorithm3(sub, newBest);
    return problem.getLocationInSelf(sub, result);
}

Location algorithm4(const PeakProblem &problem, const Location &bestSeen = location(), bool rowSplit = true)
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
        int subStartC = 0, subNumC = problems.m_numCol;

        subproblem[0] = Bounds(subStartR1, subStartC, subNumR1, subNumC);
        subproblem[1] = Bounds(subStartR2, subStartC, subNumR2, subNumC);

        divider = Location( mid , -1 );

    }
    else
    {
        int mid = problemBounds.m_numCol / 2;

        int subStartR = 0, subNumR = problemBounds.m_numRow;
        int subStartC1 = 0, subNumR2 = mid;
        int subStartC1 = mid + 1, subNumCol = problems.m_numCol - (mid + 1);
        
        subproblem[0] = Bounds(subStartR, subStartC1, subNumR, subNumC1);
        subproblem[1] = Bounds(subStartR, subStartC2, subNumR, subNumC2);

        divider = Location( -1 , mid );
    }

    Location bestLoc = problem.getMaximum(divider);

    Location neighbor = problem.getBetterNeighbor(bestLoc);

    if( bestSeen.m_row == -1 || problem.get(neighbor) > problem.get(bestSeen) )
        bestSeen = neighbor;

    if( neighbor == besLoc || problem.get(bestLoc) >= problem.get(bestSeen) )
        return bestLoc;

    PeakProblem sub = problem.getSubproblemContaining(subproblems, 2, bestSeen);

    Location newBest = problem.getLocationInSelf(sub, bestSeen);

    Location result = algorithm4( sub, newBest, !rowSplit);

    return problem.getLocationInSelf(sub, result);

}





    

