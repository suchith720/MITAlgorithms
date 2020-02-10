#include <iostream>

#include "myString.h"

using namespace std;

int main()
{
    char response[10];

    MyString str("Good morning Suchith Prabhu.");
    str.display();

    cin >> response;
    cout << response << endl;

    str = "How are your Suchith?";
    str.display();
    
    str.input();
    str.display();

    str = "Bye Suchith";
    str.display();

    return 0;
}
