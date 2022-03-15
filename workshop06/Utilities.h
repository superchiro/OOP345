// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/05
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef INC_3RDSEMESTER_UTILITIES_H
#define INC_3RDSEMESTER_UTILITIES_H

#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
#include <sstream>
#include <fstream>
#include <iostream>

namespace sdds {
    Vehicle* createInstance(std::istream& in);
}


#endif //INC_3RDSEMESTER_UTILITIES_H
