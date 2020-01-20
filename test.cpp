#include <iostream>
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
void fun(int x) { cout << "fun(int)"<< endl; }
void fun(char *s) { cout <<"fun(char *)" << endl; }

int main()
{
    int x = NULL;
    fun(nullptr);
    return 0;
}
