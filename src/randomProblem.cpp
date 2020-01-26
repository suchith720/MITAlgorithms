#include "randomProblem.h"


RandomProblem::RandomProblem(int rows, int cols, int max)
{
    m_array = NULL;
    m_rows = m_cols = 0;
    m_max = 1000;
}

int** RandomProblem::arrayPtr()
{
    return m_array;
}

int getRows()
{
    return m_rows;
}

int getCols()
{
    return m_cols;
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


RandomProblem::~RandomProblem()
{
    for(int i=0; i< m_rows; i++)
    {
        delete [] m_array[i];
    }

    delete [] m_array;
}


