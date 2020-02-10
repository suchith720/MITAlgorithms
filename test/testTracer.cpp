#include <iostream>
#include <fstream>

#include "trace.h"
#include "global.h"
#include "myString.h"


using namespace std;

int main()
{
    MyString filename("data/log.txt");
    
    TraceRecord tracer;
    
    if( tracer.openTracer(filename.arrayPtr()) )
        cout << "Opened Tracer" << endl;
    else 
        cout << "Unable to open Tracer" << endl;

    tracer.foundPeak(Location(1,1));

    tracer.closeTracer();

    return 0;
}
