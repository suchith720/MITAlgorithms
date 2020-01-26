#include <iostream>

#include "peak.h"
#include "algorithms.h"
#include "utils.h"
#include "track.h"
#include "randomProblem.h"
#include "myString.h"


#define NUM_ALGORITHMS 4

using namespace std;

typedef Location (*algorithmList) (const PeakProblem&, const TraceRecord&, const Location&, bool);

void loadProblem(RandomProblem &load, const char *file = "problem.txt")
{
    load.readFromFile( file );
}

int main()
{

    RandomProblem load;

    MyString filename("problem.txt");

    if( argc > 1 )
        utils::loadProblem(load, argv[1]);
    else
    {
        utils::getOpenFilename( filename );
        loadProblem(load, filename.arrayPtr() );
    }
    
    algorithmList function[ NUM_ALGORITHMS ] = { algorithm1, algorithm2, algorithm3, algorithm4 };
    
    Bounds loadBounds(0, 0, load.getRows(), load.getCols() );
    PeakProblem problem(load.arrayPtr(), loadBounds);

    TraceRecord trace;

    for( int i=0; i < NUM_ALGORITHMS ; i++ )
    {
        filename = "log.txt";
        utils::getOpenFilename( filename );
        trace.openTracer(filename.arrayPtr() );

        Location peak = function[i](problem, trace);

        if( problem.isPeak(peak) )
            cout <<"Algorithm "<<i+1<<" : ( "<< peak.m_row <<" , "<< peak.m_col <<" ) " << "is a peak." << endl;
        else
            cout <<"Algorithm "<<i+1<<" : ( "<< peak.m_row <<" , "<< peak.m_col <<" ) " << "is NOT a peak." << endl;
        
    }

    return 0;
}







