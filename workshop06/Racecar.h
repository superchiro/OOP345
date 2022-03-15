// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef INC_3RDSEMESTER_RACECAR_H
#define INC_3RDSEMESTER_RACECAR_H

#include "Car.h"

namespace sdds {
    class Racecar : public Car {
        double m_booster;

    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;
    };
}

#endif //INC_3RDSEMESTER_RACECAR_H
