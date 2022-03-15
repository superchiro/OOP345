// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include "Utilities.h"

size_t Utilities:: m_widthField = 1;
char Utilities::m_delimiter;


void Utilities::setFieldWidth(size_t size) {
   // if (size != 0) {}
        m_widthField = size;

}

size_t Utilities::getFieldWidth() const {
    return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

    std::string copy = str.substr(next_pos);
    size_t position = copy.find(m_delimiter);
    if (position != std::string::npos) {
        copy = copy.substr(0, position);
        if (m_widthField < copy.length()) {
            setFieldWidth(copy.length());
        }
        next_pos += position +1;
        more = true;
    } else {
        if(copy[copy.length() - 1] == '\r'){
            copy = copy.substr(0, copy.length() - 1);
        }
        more = false;
    }
    return copy;
}

void Utilities::setDelimiter(const char delim) {
    m_delimiter = delim;
}

const char Utilities:: getDelimiter() const {
    return m_delimiter;
}


