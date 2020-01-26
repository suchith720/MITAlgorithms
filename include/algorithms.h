#include <iostream>
#include "peak.h"
#include "trace.h"

using namespace std;


Location algorithm1(const PeakProblem &problem, const TraceRecord &trace = TraceRecord(), const Location &location = Location() , bool rowSplit = false);

Location algorithm2(const PeakProblem &problem, const TraceRecord &trace = TraceRecord(), const Location &location = location(0,0) , bool rowSplit = false);

Location algorithm3(const PeakProblem &problem, const TraceRecord &trace = TraceRecord(),  const Location &bestseen = location() bool rowSplit = false);
    
Location algorithm4(const PeakProblem &problem, const TraceRecord &trace = TraceRecord(), const Location &bestSeen = location(), bool rowSplit = true);
