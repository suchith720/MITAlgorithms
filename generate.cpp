#include <iostream>
#include <cstdlib>

using namespace std;

int** randomProblem(int rows=10, int columns=10, int max=1000)
{
    //array allocated in heap should be deallocated implicitly.

    int ** array;

    srand(time(NULL));
    
    array = new int* [rows];
    
    for(int i=0; i< rows; i++)
    {
        array[i] = new int [cols];

        for(int j=0; j < cols; j++)
            array[i][j] = rand()%max;
    }

    return array;
}
    

int main(int argc, char *argv[])
{
    const char *filename = nullptr; 
    if( argc > 1 )
        filename = argv[1];

    int rows=10, cols=10;
    if( argc > 3 )
    {
        rows = atoi(argv[2]);
        cols = atoi(argv[3]);
    }

    int maximum = rows * cols * 2;
    if( argc > 4 )
        maximum = atoi(argv[4]);
    
    int **generated = randomProblem(rows, cols, maximum);

    cout << "Generated a matrix with "<< rows <<" row and "<< cols << " columns."<<endl;

    if( !filename )
    {
        //to be implemented
        filename = getSaveFilename("problem.txt");
        if( !filename) 
            return;
    }

    //output the result


    return 0;
}
