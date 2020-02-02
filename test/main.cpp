#include <iostream>

#include "peak.h"
#include "algorithms.h"
#include "utils.h"
#include "trace.h"
#include "randomProblem.h"
#include "myString.h"


#define NUM_ALGORITHMS 4

using namespace std;

typedef Location (*algorithmList) (PeakProblem&, TraceRecord, const Location&, bool);

void loadProblem(RandomProblem &matrix, const char *file = "problem.txt")
{
    matrix.readFromFile( file );
}

int main(int argc, char *argv[])
{

    RandomProblem matrix;

    MyString filename("problem.txt");

    if( argc > 1 )
        loadProblem(matrix, argv[1]);
    else
    {
        utils::getOpenFilename( filename );
        loadProblem(matrix, filename.arrayPtr() );
    }
    
    algorithmList function[ NUM_ALGORITHMS ] = { algorithm1, algorithm2, algorithm3, algorithm4 };
    
    Bounds matrixBounds(0, 0, matrix.getNumRows(), matrix.getNumColumns() );
    PeakProblem problem(matrix.arrayPtr(), matrixBounds);

    TraceRecord trace;

    for( int i=0; i < NUM_ALGORITHMS ; i++ )
    {
        filename = "log.txt";
        utils::getOpenFilename( filename );
        trace.openTracer(filename.arrayPtr() );

        Location peak = function[i](problem, trace, Location(), true);

        if( problem.isPeak(peak) )
            cout <<"Algorithm "<<i+1<<" : ( "<< peak.m_row <<" , "<< peak.m_col <<" ) " << "is a peak." << endl;
        else
            cout <<"Algorithm "<<i+1<<" : ( "<< peak.m_row <<" , "<< peak.m_col <<" ) " << "is NOT a peak." << endl;
        
    }

    return 0;
}







