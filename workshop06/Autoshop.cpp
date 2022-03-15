// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Autoshop.h"

namespace sdds {

    Autoshop &Autoshop::operator+=(Vehicle* theVehicle) {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream &out) const {

        std::cout << "---------------------------------"<< std::endl;
        std::cout << "| Cars in the autoshop!         |" << std::endl;
        std::cout << "---------------------------------"<< std::endl;

        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i) -> display(out);
            out << std::endl;

        }
        out << "--------------------------------------" << std::endl;
    }

    Autoshop::~Autoshop() {
        while(!m_vehicles.empty()) {
            m_vehicles.pop_back();
        }
    }
}