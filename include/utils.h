#ifndef __UTILS__
#define __UTILS__

#include <iostream>
#include <fstream>


#include "myString.h"

using namespace std;

namespace utils
{
    void getOpenFilename(MyString &filename);
    
    void getSaveFilename(MyString &filename);
}

#endif  // end for __UTILS__
