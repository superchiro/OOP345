// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"

namespace sdds {

    Car::Car(std::istream &is) {

        std::string copy;
        std::getline(is, copy, ',');
        m_maker = trim(copy);

        std::getline(is, copy, ',');
        trim(copy);

        if(copy == "" || copy == "n") {
            m_condition = "new";
        } else if (copy == "u") {
            m_condition = "used";
        } else if (copy == "b") {
            m_condition = "broken";
        } else {
            throw "Invalid condition";
        }

        std::getline(is, copy, ',');
        try {
            m_topSpeed = std::stod(trim(copy));
        } catch(...) {
            throw "Invalid speed";
        }
        //catch(..) invalid number
    }


    std::string Car::condition() const {
        return m_condition;

    }

    double Car::topSpeed() const {
        return m_topSpeed;
    }

    void Car::display(std::ostream &out) const {

        std::cout << "| " << std::setw(10) << std::left << m_maker << " | "
        << std::setw(6) << std::right << m_condition << " | "
        << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " | ";

    }

    std::string& Car::trim(std::string &str) {

        while(str.length() > 0 && str[0] == ' ') {
            str.erase(0, 1);
        }
        while (str.length() > 0 && str[str.length() - 1] == ' ') {
            str.erase(str.length() -1, 1);
        }

        return str;
    }

}

