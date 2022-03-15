// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include "String.h"


namespace sdds {

    unsigned int g_maxSize = 3;

    String::String(const char* s) {

        if(s == nullptr) {
            string[0] = '\0';
        } else {
            strncpy(string, s, g_maxSize);
            string[g_maxSize - 1] = '\0';
        }
    }

    void String::display(std::ostream& os) const {

        os << string;
    }


    std::ostream &operator<<(std::ostream& os, const String &s) {
        static int counter = 0;

        std::cout << counter << ": " ;
        s.display(os);

        counter ++;

        return os;
    }
}