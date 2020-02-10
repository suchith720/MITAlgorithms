#include "myString.h"

void MyString::initialize()
{
    m_length = 0;
    m_string = new char [m_length + 1];
    m_string[m_length] = '\0';
}

void MyString::clear()
{
    if( m_string != NULL )
        delete [] m_string;

    m_length = 0;
    m_string = new char [m_length + 1];
    m_string[m_length] = '\0';
}

MyString::MyString()
{
    initialize();
}

MyString::MyString(const char* str)
{
    if( str != NULL)
    {
        m_length =0;

        while( str[m_length] != '\0' )
            m_length++;

        m_string = new char [m_length + 1];

        strcpy(m_string, str);

    }
    else
        initialize();
}


MyString::MyString(const MyString &str)
{
    m_length = str.m_length;

    m_string = new char [m_length + 1];
    strcpy(m_string, str.m_string);
}

void MyString::operator = (const MyString &str)
{
    delete [] m_string;
    
    m_length = str.m_length;

    m_string = new char [m_length + 1];
    strcpy(m_string, str.m_string);
}

void MyString::input()
{
    char ch;

    if(m_length > 0)
    {
        delete [] m_string; 
        initialize();
    }

    int count = 0;

    char* strUpdate;

    while( cin.get(ch) && ch == '\n' );

    while( ch != '\n' )
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

        cin.get(ch);
    }
    
    m_string[count] = '\0';
}

int MyString::length()
{
    return m_length;
}

char* MyString::arrayPtr()
{
    return m_string;
}

void MyString::display()
{
    cout << m_string << endl;
}

MyString::~MyString()
{
    delete [] m_string;
}


