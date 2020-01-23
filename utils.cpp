#include <iostream>
#include <fstream>
#include "myString.h"

using namespace std;


void getOpenFilename(MyString &filename)
{
    cout << "Enter a file name to load from ";
    if(filename.length() != 0)
        cout << "(default : " << filename.arrayPtr() << ")";
    cout << " : " << endl;
    
    MyString enterFilename;
    enteredFilename.input();

    if( strcmp(enteredFilename.arrayPtr(),"") && !strcmp(filename.arrayPtr(), "") )
        filename = enteredFilename;
}

void getSaveFilename(MyString &filename)
{
    cout << "Enter a file name to save to ";
    if(filename.length() != 0)
        cout << "(default : " << filename.arrayPtr() << ")";
    cout << " : " << endl;
    
    MyString enterFilename;
    enteredFilename.input();

    if(  strcmp(enteredFilename.arrayPtr(),"") )
        filename = enteredFilename;
    
    ifstream fileExists( filename.arrayPtr() );
    if( fileExists.is_open() )
    {
        cout << "The file "<< filename.arrayPtr() << " already exists." << endl;
        cout << "Overwrite (o), enter another name (f), or cancel (c)? "<< endl;

        char check;
        cin >> check;

        while(check != 'o' && check != 'f' && check != 'c')
        {
            cout << "The file "<< filename.arrayPtr() << " already exists." << endl;
            cout << "Overwrite (o), enter another name (f), or cancel (c)? "<< endl;
        }

        if( check == 'f')
            getSaveFilename(filename);
        else if( check == 'c')
            filename.clear();
    }
            
    fileExists.close();
}

