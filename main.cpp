#include <iostream>

//to be structured properly

#include "peak.h"
#include "algorithms.h"
#include "utils.h"

using namespace std;

void loadProblem(const char *file = "problem.txt", RandomProblem &problem)
{
    problem.readFromFile( file );
}

int main()
{
    RandomProblem problem;

    MyString filename("problem.txt");

    if( argc > 1 )
        loadProblem(argv[1], problem);
    else
    {
        getOpenFilename( filename );
        loadProblem(filename.arrayPtr(), problem);
    }



}







