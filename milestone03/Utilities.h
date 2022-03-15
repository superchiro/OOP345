// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/11/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef INC_3RDSEMESTER_UTILITIES_H
#define INC_3RDSEMESTER_UTILITIES_H

#include <iostream>
#include <string>

class Utilities {
    static size_t m_widthField;
    static char m_delimiter;

public:
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;

};

#endif //INC_3RDSEMESTER_UTILITIES_H
