#include "trace.h"

TraceRecord::TraceRecord()
{
    m_isTraceRecordOpen = false;
}

TraceRecord::TraceRecord(const TraceRecord &trace)
{
    m_logFile.copyfmt( trace.m_logFile );
    m_logFile.clear( trace.m_logFile.rdstate() );
    m_logFile.basic_ios<char>::rdbuf( trace.m_logFile.rdbuf() );

    m_isTraceRecordOpen = true;
}

TraceRecord::TraceRecord(const char * filename, ios_base::openmode fileMode)
{
    this->m_logFile.open(filename, fileMode | ios::out);
    m_isTraceRecordOpen = true; 

    if(! m_logFile.is_open() )
    {
        cout << "Unable to open track file." << endl;
        m_isTraceRecordOpen = false;
    }
}

TraceRecord::~TraceRecord()
{
    if(  m_isTraceRecordOpen )
    {
        m_logFile.flush();
        m_logFile.close();
    }

}

int TraceRecord::openTracer(const char *filename, ios_base::openmode fileMode)
{
    if( m_isTraceRecordOpen )
    {
        this->m_logFile.flush();
        this->m_logFile.close();
    }
    
    this->m_logFile.open(filename, fileMode);
    m_isTraceRecordOpen = true; 

    if(! m_logFile.is_open() )
    {
        cerr << "Unable to open track file." << endl;
        m_isTraceRecordOpen = false;
        return 0;
    }

    return 1;
}

int TraceRecord::closeTracer()
{
    if( ! m_isTraceRecordOpen )
        return 0;

    m_logFile.close();

    m_isTraceRecordOpen = false;

    return 1;
}



void TraceRecord::getMaximum(const Bounds &bounds, const Location &location, const Location &maximum) 
{
    if( ! m_isTraceRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"findingMaximum"<< endl;
    m_logFile <<"bounds"<<" "<<bounds.m_startRow<<" "<<bounds.m_startCol<<" "<<bounds.m_numRow<<" "<<bounds.m_numCol<< endl;
    m_logFile<<"coord"<<" "<<location.m_row<<" "<<location.m_col<<endl;

    
    m_logFile <<"type"<<" "<<"foundMaximum"<< endl;
    m_logFile<<"coord"<<" "<<maximum.m_row<<" "<<maximum.m_col<<endl;

}


void TraceRecord::getBetterNeighbor(const Location &neighbor, const Location &better) 
{
    if( ! m_isTraceRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"findingNeighbor"<< endl;
    m_logFile<<"coord"<<" "<<neighbor.m_row<<" "<<neighbor.m_col<<endl;


    m_logFile <<"type"<<" "<<"foundNeighbor"<< endl;
    m_logFile << "coord" << " " << better.m_row << " " << better.m_col << endl;

}

void TraceRecord::setProblemDimensions(PeakProblem &subproblem)
{
    if( ! m_isTraceRecordOpen )
        return;

    Bounds subproblemBounds = subproblem.getBounds();

    m_logFile <<"type"<<" "<<"subproblem"<< endl;
    m_logFile <<"startRow"<<" "<<subproblemBounds.m_startRow<<endl;
    m_logFile <<"numRows"<<" "<<subproblemBounds.m_numRow<<endl;
    m_logFile <<"startCol"<<" "<<subproblemBounds.m_startCol<<endl;
    m_logFile <<"numCols"<<" "<<subproblemBounds.m_numCol<<endl;

}

void TraceRecord::setBestSeen(const Location &bestSeen)
{
    if( ! m_isTraceRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"bestSeen"<< endl;
    m_logFile << "coord" << " " << bestSeen.m_row << " " << bestSeen.m_col << endl;


}

void TraceRecord::foundPeak(const Location &peak)
{
    if( ! m_isTraceRecordOpen )
        return;

    m_logFile <<"type"<<" "<<"foundPeak"<< endl;
    m_logFile << "coord" << " " << peak.m_row << " " << peak.m_col << endl;

}

//Helper function
bool TraceRecord::getTraceRecordStatus() const
{
    return m_isTraceRecordOpen;
}



