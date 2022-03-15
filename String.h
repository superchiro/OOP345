// Name: Chihiro Kawaguchi

// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/15
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef INC_3RDSEMESTER_STRING_H
#define INC_3RDSEMESTER_STRING_H

namespace sdds {

    extern unsigned int g_maxSize;

    class String {

        char string[3];
    public:

        String (const char* s);
        void display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream&, const String& s);
}

#endif //INC_3RDSEMESTER_STRING_H
