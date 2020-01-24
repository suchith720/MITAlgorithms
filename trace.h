#include <iostream>
#include <fstream>

using namespace std;

class TraceRecord
{
    ofstream m_logFile;
    bool m_isTraceRecordOpen;

    public:

        TraceRecord();

        TraceRecord(const char &filename[], int fileMode = ios::trunc);

        int openTracer(const char *filename, int fileMode = ios::trunc);

        int closeTracer();

        void getMaximum(const Location &location, const Location &maximum);

        void getBetterNeighbor(const Location &neighbor, const Location &better);

        void setProblemDimensions(PeakProblem &subprolem);

        void setBestSeen(const Location &bestSeen);

        void foundPeak(const Location &peak);

        ~TraceRecord();

        //Helper function
        bool getTraceRecordStatus();

};
