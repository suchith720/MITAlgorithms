#ifndef __RANDOM_PROBLEM__
#define __RANDOM_PROBLEM__

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


class RandomProblem
{
    int** m_array;

    int m_rows, m_cols, m_max;

    public:
    
    RandomProblem(int rows=10, int cols=10, int max=1000);
    void generate(int rows=10, int cols=10, int max=1000);
    int readFromFile(const char* filename);
    int writeToFile(const char* filename);
    ~RandomProblem();

    int** arrayPtr();
    int getNumRows();
    int getNumColumns();
};

#endif  // end for __RANDOM_PROBLEM__
