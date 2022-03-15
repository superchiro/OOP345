// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <iomanip>
#include <string>
#include <iostream>

#ifndef INC_3RDSEMESTER_ITEM_H
#define INC_3RDSEMESTER_ITEM_H

class Item{

    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber;
    unsigned int m_quantity;
    static size_t m_widthField;

public:

    Item(const std::string& str);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;


};

#endif //INC_3RDSEMESTER_ITEM_H
