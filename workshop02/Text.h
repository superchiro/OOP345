// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//

#ifndef INC_3RDSEMESTER_TEXT_H
#define INC_3RDSEMESTER_TEXT_H

#include <iostream>
#include <fstream>
#include <utility>
#include <string>

namespace sdds {

    class Text {
        std::string *S;
        size_t track;

    public:
        Text();
        Text(const std::string);
        Text(const Text&);
        Text& operator = (const Text&);
        ~Text();
        size_t size() const;


    };

}


#endif //INC_3RDSEMESTER_TEXT_H
