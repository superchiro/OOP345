// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef INC_3RDSEMESTER_LVPAIR_H
#define INC_3RDSEMESTER_LVPAIR_H

#include <iostream>

namespace sdds {

    template<typename L, typename V>
    class LVPair {

        L typeL;
        V typeV;

    public:
        LVPair() {}

        LVPair(const L &aa, const V &bb) {
            typeL = aa;
            typeV = bb;
        }

        const L &key() const {
            return typeL;
        }

        const V &value() const {
            return typeV;
        }

        void display(std::ostream &os) const {

            os << typeL << " : " << typeV << std::endl;
        }

    };

}

template<typename L, typename V>
std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
    pair.display(os);
    return os;
}

#endif //INC_3RDSEMESTER_LVPAIR_H
