// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef INC_3RDSEMESTER_CAR_H
#define INC_3RDSEMESTER_CAR_H

#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle{

        std::string m_maker;
        std::string m_condition;
        double m_topSpeed;

    public:
        Car(std::istream &is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream &out) const;
        std::string& trim(std::string &str);

    };

}
#endif //INC_3RDSEMESTER_CAR_H
