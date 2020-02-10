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
    
    RandomProblem generated;

    cout << "Generating a matrix with "<< rows <<" row and "<< cols << " columns."<<endl;

    if( ! filename.length() )
    {
        filename = MyString("data/problem.txt");
        utils::getSaveFilename(filename);
        
        if( !filename.length() ) 
            return 0;
    }
    
    cout << "Generate a random problem." << endl;
    cout << "Yes (y) or No (c)? "<< endl;

    char generate_ans;
    cin >> generate_ans;

    while(generate_ans != 'y' && generate_ans != 'n')
    {
        cout << "Generate a random problem." << endl;
        cout << "Yes (y) or No (c)? "<< endl;
    }

    if( generate_ans == 'y')
        generated.generate(rows, cols, maximum);


    generated.writeToFile(filename.arrayPtr());

    return 0;
}
