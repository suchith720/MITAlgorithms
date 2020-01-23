#include <iostream>
#include <fstream>

using namespace std;

class MyString
{
    char* m_string;
    int m_length;

    void reset()
    {
        m_length = 0;
        m_string = new char [m_length + 1];
        m_string[m_length] = '\0';
    }

    public:

    MyString()
    {
        reset();
    }

    MyString(const MyString &str)
    {
        m_length = str.m_length;

        m_string = new char [m_length + 1];
        strcpy(m_string, str.m_string);
    }


    void operator = (const MyString &str)
    {
        delete [] m_string;
        
        m_length = str.m_length;

        m_string = new char [m_length + 1];
        strcpy(m_string, str.m_string);
    }



    void input()
    {
        char ch;

        if(m_length > 0)
        {
            delete [] m_string; 
            reset();
        }

        int count = 0;

        char* strUpdate;

        while( cin.get(ch) && ch != '\n' )
        {
            m_string[count] = ch;
            count ++;

            if(count == m_length)
            {
                m_string[count]='\0';

                m_length *= 2;
                strUpdate = new char[m_length + 1];
                strcpy(strUpdate, m_string);
                delete [] m_string;

                m_string = strUpdate;
            }
        }
        
        m_string[count] = '\0';
    }

    int length()
    {
        return m_length;
    }

    char* arrayPtr()
    {
        return m_string;
    }

    void display()
    {
        cout << m_string << endl;
    }

    ~MyString()
    {
        delete [] m_string;
    }

};

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
            filename.reset();
    }
            
    fileExists.close();
}

