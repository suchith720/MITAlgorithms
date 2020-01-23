#include <iostream>
#include <cstring>
using namespace std;

//passing 2D array into a function
//void printArray(int a, int b, const int (*(&arr))[3] )
//{
//  for(int i=0; i<a; i++)
//  {
//    for(int j=0; j < b; j++)
//    {
//      std::cout << arr[i][j] << "  ";
//    }
//    std::cout << std::endl;
//  }
//
//}
//
//void fun(int *arr)
//{
//  int *ptr, i;
//  ptr = &i;
//
//  unsigned int n = sizeof(arr)/sizeof(arr[0]);
//
//  for (i=0; i<n; i++)
//    std::cout <<  arr[i] << " ";
//
//  std::cout << std::endl;
//}
//
////-----------------------------------------------------------------
//
////int main()
////{
////  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
////  fun(arr);
////  return 0;
////}
//
//void passFunc(int (*a)[10]) //Array containing pointers
//{
//}
//
//int main()
//{
//  //const int arr[][3] = { {1, 2, 3}, {2, 3, 4} };
//  //printArray(2, 3, arr); 
//  int (*array)[10] = new int[10][10]; 
//  passFunc(array);
//
//  return 0;
//
//} 

//int main(int argc, char *argv[])
//{
//    //cerr << "Hello" << endl;
//    char *ptr = argv[1];
//    if( argc > 1)
//        cout << ptr <<endl;
//
//    return 0;
//}
//

//void fun(int x) { cout << "fun(int)"<< endl; }
//void fun(char *s) { cout <<"fun(char *)" << endl; }
//
//int main()
//{
//    int x = NULL;
//    fun(nullptr);
//    return 0;
//}

//Dynamic string handling

//class MyString
//{
//    char* m_string;
//    int m_length;
//
//    void reset()
//    {
//        m_length = 0;
//        m_string = new char [m_length + 1];
//        m_string[m_length] = '\0';
//    }
//
//    public:
//
//    MyString()
//    {
//        reset();
//    }
//
//    MyString(const MyString &str)
//    {
//        m_length = str.m_length;
//
//        m_string = new char [m_length + 1];
//        strcpy(m_string, str.m_string);
//    }
//
//
//    void operator = (const MyString &str)
//    {
//        delete [] m_string;
//        
//        m_length = str.m_length;
//
//        m_string = new char [m_length + 1];
//        strcpy(m_string, str.m_string);
//    }
//
//
//
//    void input()
//    {
//        char ch;
//
//        if(m_length > 0)
//        {
//            delete [] m_string; 
//            reset();
//        }
//
//        int count = 0;
//
//        char* strUpdate;
//
//        while( cin.get(ch) && ch != '\n' )
//        {
//            m_string[count] = ch;
//            count ++;
//
//            if(count == m_length)
//            {
//                m_string[count]='\0';
//
//                m_length *= 2;
//                strUpdate = new char[m_length + 1];
//                strcpy(strUpdate, m_string);
//                delete [] m_string;
//
//                m_string = strUpdate;
//            }
//        }
//        
//        m_string[count] = '\0';
//    }
//
//    int length()
//    {
//        return m_length;
//    }
//
//    char* arrayPtr()
//    {
//        return m_string;
//    }
//
//    void display()
//    {
//        cout << m_string << endl;
//    }
//
//    ~MyString()
//    {
//        delete [] m_string;
//    }
//
//};
//
//int main()
//{
//    MyString filename;
//
//    filename.input();
//
//    MyString updatedFile;
//
//    updatedFile = filename;
//
//    filename.display();
//    updatedFile.display();
//
//    return 0;
//}


#include "myString.h"

int main()
{
    //MyString filename;

    //filename.input();

    //MyString updatedFile;

    //updatedFile = filename;

    //filename.display();
    //updatedFile.display();
    
    MyString filename("Suchith Prabhu");

    cout << " display(): ";
    filename.display();

    filename.input();
    cout << " input(): ";
    filename.display();

    return 0;
}
