#include <iostream>
#include <fstream>

using namespace std;

class TraceRecord
{
    ofstream m_logFile;
    bool m_isTrackRecordOpen;

    public:

        TraceRecord();
        TraceRecord(const char &filename[], int fileMode);
        void getMaximum(const Location &location, const Location &maximum);
        void getBetterNeighbor(const Location &neighbor, const Location &better);
        void setProblemDimensions(PeakProblem &subprolem);
        void setBestSeen(const Location &bestSeen);
        void foundPeak(const Location &peak);
        ~TraceRecord();

        //Helper function
        bool getTrackRecordStatus();

};

TraceRecord::TraceRecord()
{
}

TraceRecord::TraceRecord(const char &filename[], int fileMode = ios::trunc)
{
    this->m_logFile.open(filename, fileMode);
    m_isTrackRecordOpen = true; 

    if(! m_logFile.is_open() )
    {
        cout << "Unable to open track file." << endl;
        m_isTrackRecordOpen = false;
    }
}

TrackRecord::~TrackRecord()
{
    if(  m_isTrackRecordOpen )
    {
        m_logFile.flush();
        m_logFile.close();
    }

    cout << "Closing track file." << endl;

}

void TrackRecord::getMaximum(const Bounds &bounds, const Location &location, const Location &maximum)
{
    if( ! m_isTrackRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"findingMaximum"<< endl;
    m_logFile <<"bounds"<<" "<<bounds.m_startRow<<" "<<bounds.m_startCol<<" "<<bounds.m_numRow<<" "<<bounds.m_numCol<< endl;
    m_logFile<<"coord"<<" "<<location.m_row<<" "<<location.m_col<<endl;

    
    m_logFile <<"type"<<" "<<"foundMaximum"<< endl;
    m_logFile<<"coord"<<" "<<maximum.m_row<<" "<<maximum.m_col<<endl;

}


void TrackRecord::getBetterNeighbor(const Location &neighbor, const Location &better)
{
    if( ! m_isTrackRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"findingNeighbor"<< endl;
    m_logFile<<"coord"<<" "<<neighbor.m_row<<" "<<neighbor.m_col<<endl;


    m_logFile <<"type"<<" "<<"foundNeighbor"<< endl;
    m_logFile << "coord" << " " << better.m_row << " " << better.m_col << endl;

}

void TrackRecord::setProblemDimensions(PeakProblem &subprolem)
{
    if( ! m_isTrackRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"subproblem"<< endl;
    m_logFile <<"startRow"<<" "<<subproblem.m_startRow<<endl;
    m_logFile <<"numRows"<<" "<<subproblem.m_numRow<<endl;
    m_logFile <<"startCol"<<" "<<subproblem.m_startCol<<endl;
    m_logFile <<"numCols"<<" "<<subproblem.m_numCol<<endl;

}

void TrackRecord::setBestSeen(const Location &bestSeen)
{
    if( ! m_isTrackRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"bestSeen"<< endl;
    m_logFile << "coord" << " " << bestSeen.m_row << " " << bestSeen.m_col << endl;


}

void TrackRecord::foundPeak(const Location &peak)
{
    if( ! m_isTrackRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"foundPeak"<< endl;
    m_logFile << "coord" << " " << peak.m_row << " " << peak.m_col << endl;

}

//Helper function
bool TrackRecord::getTrackRecordStatus()
{
    return m_isTrackRecordOpen;
}



