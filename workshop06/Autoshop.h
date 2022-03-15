// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef INC_3RDSEMESTER_AUTOSHOP_H
#define INC_3RDSEMESTER_AUTOSHOP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles;

    public:
        Autoshop() = default;
        Autoshop& operator +=(Vehicle* theVehicle);
        void display (std::ostream& out) const;
        ~Autoshop();
        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
                if (test(*i)) {
                        vehicles.push_back(*i);
                }
            }
        }


    };
}

#endif //INC_3RDSEMESTER_AUTOSHOP_H
