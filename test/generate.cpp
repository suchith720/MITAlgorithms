#include <iostream>

#include "utils.h"
#include "myString.h"
#include "randomProblem.h"

using namespace std;


int main(int argc, char *argv[])
{
    MyString filename; 

    if( argc > 1 )
        filename = MyString(argv[1]);

    int rows=10, cols=10;
    if( argc > 3 )
    {
        rows = atoi(argv[2]);
        cols = atoi(argv[3]);
    }

    int maximum = rows * cols * 2;
    if( argc > 4 )
        maximum = atoi(argv[4]);
    
    RandomProblem generated(rows, cols, maximum);

    cout << "Generated a matrix with "<< rows <<" row and "<< cols << " columns."<<endl;

    if( ! filename.length() )
    {
        filename = MyString("problem.txt");
        getSaveFilename(filename);
        
        if( !filename.length() ) 
            return 0;
    }

    generated.writeToFile(filename.arrayPtr());

    return 0;
}
