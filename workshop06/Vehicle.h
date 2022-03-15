// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <string>

namespace sdds
{
    class Vehicle
    {
    public:
        virtual double topSpeed() const = 0;
        virtual void display(std::ostream&) const = 0;
        virtual std::string condition() const = 0;
        virtual ~Vehicle() {};
    };
}



#endif
