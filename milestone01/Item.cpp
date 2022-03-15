// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iomanip>
#include "Item.h"

size_t Item::m_widthField;

Item::Item(std::string &str) {

    Utilities utilities;
    size_t pos = 0;
    bool more = false;

    m_name = utilities.extractToken(str, pos, more);
    if (pos != std::string::npos) {
        std::string temp = utilities.extractToken(str, pos, more);
        m_serialNumber = stoi(temp);
       // m_serialNumber = utilities.extractToken(str, pos, more); //can not assing string to int
    }

    if (pos != std::string::npos) {
        std::string temp = utilities.extractToken(str, pos, more);
        m_quantity = stoi(temp);
    }

    if (pos != std::string::npos) {
        m_description = utilities.extractToken(str, pos, more);
    }

    if (m_widthField < utilities.getFieldWidth()) {
        m_widthField = utilities.getFieldWidth();
    }

}

const std::string &Item::getName() const {
    return m_name;
}

const unsigned int Item::getSerialNumber() {
    unsigned int next = m_serialNumber;
    m_serialNumber ++;
    return next;
}

const unsigned int Item::getQuantity() {
    return m_quantity;
}

void Item::updateQuantity() {
    if(m_quantity > 0) {
        m_quantity--;
    }
}

void Item::display(std::ostream &os, bool full) const {

    if (full == false) {
        os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "] ";
    } else {
        os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber <<
        "] Quantity: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_quantity << "Description: " << m_description;
    }
    os << std::endl;

}
