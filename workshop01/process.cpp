// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <iostream>
#include "String.h"

namespace sdds
{
    void process(const char* str)
    {
        String a = String(str);
        std::cout << a << std::endl;
    }
}