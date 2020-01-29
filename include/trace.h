#ifndef __TRACE_RECORD__
#define __TRACE_RECORD__

#include <iostream>
#include <fstream>

#include "peak.h"
#include  "global.h"

using namespace std;

class PeakProblem;

class TraceRecord
{
    ofstream m_logFile;
    bool m_isTraceRecordOpen;

    public:

        TraceRecord();

        TraceRecord(const char * filename,  ios_base::openmode fileMode = ios::trunc);

        int openTracer(const char *filename, ios_base::openmode fileMode = ios::trunc);

        int closeTracer();

        void getMaximum(const Bounds &bounds, const Location &location, const Location &maximum);

        void getBetterNeighbor(const Location &neighbor, const Location &better);

        void setProblemDimensions(PeakProblem &subprolem);

        void setBestSeen(const Location &bestSeen);

        void foundPeak(const Location &peak);

        ~TraceRecord();

        //Helper function
        bool getTraceRecordStatus() const;

};

#endif  //end for __TRACE_RECORD__

