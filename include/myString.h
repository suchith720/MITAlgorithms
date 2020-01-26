#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    char* m_string;
    int m_length;

    void initialize();
    void clear();

    public:

    MyString();

    MyString(const char* str);

    MyString(const MyString &str);

    void operator = (const MyString &str);

    void input();

    int length();

    char* arrayPtr();

    void display();

    ~MyString();

};
