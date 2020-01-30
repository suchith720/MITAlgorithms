#ifndef __ALGORITHMS__
#define __ALGORITHMS__

#include <iostream>

#include "trace.h"
#include "peak.h"
#include "global.h"


using namespace std;


Location algorithm1(PeakProblem &problem, TraceRecord trace = TraceRecord(), const Location &location = Location() , bool rowSplit = false);

Location algorithm2(PeakProblem &problem, TraceRecord trace = TraceRecord(), const Location &location = Location(0,0) , bool rowSplit = false);

Location algorithm3(PeakProblem &problem, TraceRecord trace = TraceRecord(),  const Location &bestseen = Location() , bool rowSplit = false);
    
Location algorithm4(PeakProblem &problem, TraceRecord trace = TraceRecord(), const Location &bestSeen = Location(), bool rowSplit = true);

#endif  // end for __ALGORITHMS__
