#include <iostream>
#include <cstdlib>
#include <fstream>

#include "utils.h"
#include "myString.h"

using namespace std;

class RandomProblem
{
    int** m_array;

    int m_rows, m_columns, m_max;

    public:
    
    RandomProblem();
    void generate(int rows=10, int cols=10, int max=1000);
    int readFromFile(const char* filename);
    int writeToFile(const char* filename);
    ~RandomProblem();

    int writeToFile(const char* filename);

};

RandomProblem::RandomProblem(int rows, int cols, int max)
{
    m_array = NULL;
    m_rows = m_cols = 0;
    m_max = 1000;
}

void RandomProblem::generate(int rows, int cols, int max)
{
    if( m_array != NULL)
        return;

    m_rows = rows;
    m_cols = cols;
    m_max = max;

    srand(time(NULL));
    
    m_array = new int* [m_rows];
    
    for(int i=0; i< m_rows; i++)
    {
        m_array[i] = new int [m_cols];

        for(int j=0; j < m_cols; j++)
            inputFile >> m_array[i][j];
    }

}
int RandomProblem::readFromFile(const char* filename)
{
    if( m_array != NULL)
        return 0;

    ifstream inputFile(filename);

    if( ! inputFile.is_open() )
    {
        cerr << "Unable to read the problem file : " << __PRETTY_FUNCTION__ << endl;
        return 0;
    }

    inputFile >> m_rows >> m_cols;

    m_array = new int* [m_rows];
    
    for(int i=0; i< m_rows; i++)
    {
        m_array[i] = new int [m_cols];

        for(int j=0; j < m_cols; j++)
            inputFile >> m_array[i][j] = rand()%max;
    }


}

int RandomProblem::writeToFile(const char* filename)
{
    if( m_array == NULL)
        return 0;

    ofstream outputFile(filename, ios::trunc);

    if( !outputFile.is_open() )
    {
        cerr << "Unable to write to problem file : " << __PRETTY_FUNCTION__ <<endl;
        return 0;
    }
    
    outputFile << m_rows << endl;
    outputFile << m_cols << endl;

    for(int i=0; i < m_rows; i++)
    {
        for(int j=0; j < m_cols; j++)
            outputFile << m_array[i][j] << " "; 

        outputFile << endl;
    }

    return 1;
}


}

RandomProblem::~RandomProblem()
{
    for(int i=0; i< m_rows; i++)
    {
        delete [] m_array[i];
    }

    delete [] m_array;
}

   

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
