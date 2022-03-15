// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Racecar.h"
using namespace std;

namespace sdds {

        Racecar::Racecar(std::istream &in) : Car(in) {
        std::string copy;
        std::getline(in, copy, ',');

        m_booster = std::stod(trim(copy));

    }

    void Racecar::display(std::ostream &out) const {

        Car::display(out);
        out << "*";

    }

    double Racecar::topSpeed() const {
        return Car::topSpeed() * (1 + m_booster);
    }
}