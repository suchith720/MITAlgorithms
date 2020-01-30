#ifndef __MY_STRING__
#define __MY_STRING__

#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    char* m_string;
    int m_length;

    void initialize();

    public:

    MyString();

    MyString(const char* str);

    MyString(const MyString &str);

    void clear();

    void operator = (const MyString &str);

    void input();

    int length();

    char* arrayPtr();

    void display();

    ~MyString();

};

#endif  // end for __MY_STRING__
