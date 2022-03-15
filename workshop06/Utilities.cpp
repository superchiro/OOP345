// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Utilities.h"

namespace sdds {

    Vehicle* createInstance(std::istream& in) {
        std::string copy;
        char type = '\0';
        char delimiter = '\0';

        std::getline(in, copy);
        std::stringstream ss(copy);
        ss >> type >> delimiter;

        if (ss) {
            switch (type) {
                case 'c':
                case 'C':
                    return new Car(ss);
                    break;
                case 'r':
                case 'R':
                   return new Racecar(ss);
                   break;
                default:
                    throw type;
                    break;
            }
        }
        return nullptr;
    }
}
