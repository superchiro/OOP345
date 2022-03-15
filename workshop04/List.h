// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.



#ifndef INC_3RDSEMESTER_LIST_H
#define INC_3RDSEMESTER_LIST_H

namespace sdds {

    template <typename T, size_t N>

    class List {

        size_t num = 0;
        T arr[N];

    public:

        size_t size() const {
            return num;
        }

        const T& operator[](size_t i) const {
            return arr[i];
        }

        void operator+=(const T& tt) {
            if(N > num) {
                arr[num] = tt;
                num++;
            }
        }
    };


}

#endif //INC_3RDSEMESTER_LIST_H
