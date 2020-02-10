#include "utils.h"

void utils::getOpenFilename(MyString &filename)
{
    cout << "Enter a file name to load ";
    if(filename.length() != 0)
        cout << "(default : " << filename.arrayPtr() << ")";
    cout << " : " << endl;
    

    MyString enteredFilename;
    enteredFilename.input();

    if( strcmp(enteredFilename.arrayPtr()," ") )
        filename = enteredFilename;

    ifstream fileExists( filename.arrayPtr() );

    if( ! fileExists.is_open() )
    {
        cout << "The file "<< filename.arrayPtr() << " doesn't exist." << endl;
        cout << "Enter another name (f), ok (o), or cancel (c)? : " ;

        char check;
        cin >> check;

        while(check != 'f' && check != 'c' && check != 'o')
        {
            cout << "The file "<< filename.arrayPtr() << " doesn't exist." << endl;
            cout << "Enter another name (f), ok (o), or cancel (c)? : ";
        }

        if( check == 'f')
            getOpenFilename(filename);
        else if( check == 'c')
            filename.clear();
    }
            
    fileExists.close();


}

void utils::getSaveFilename(MyString &filename)
{
    cout << "Enter a file name to save to ";
    if(filename.length() != 0)
        cout << "(default : " << filename.arrayPtr() << ")";
    cout << " : " << endl;
    
    MyString enteredFilename;
    enteredFilename.input();

    if(  strcmp(enteredFilename.arrayPtr()," ") )
        filename = enteredFilename;
    
    ifstream fileExists( filename.arrayPtr() );
    if( fileExists.is_open() )
    {
        cout << "The file "<< filename.arrayPtr() << " already exists." << endl;
        cout << "Overwrite (o), enter another name (f), or cancel (c)? : " ;

        char check;
        cin >> check;

        while(check != 'o' && check != 'f' && check != 'c')
        {
            cout << "The file "<< filename.arrayPtr() << " already exists." << endl;
            cout << "Overwrite (o), enter another name (f), or cancel (c)? : ";
        }

        if( check == 'f')
            getSaveFilename(filename);
        else if( check == 'c')
            filename.clear();
    }
            
    fileExists.close();
}

