
#ifndef INC_3RDSEMESTER_RESERVATION_H
#define INC_3RDSEMESTER_RESERVATION_H

#include <iostream>

namespace sdds {

    class Reservation {
        std::string resId;
        std::string resName;
        std::string mail;
        int num;
        int day;
        int hour;

    public:
        Reservation();
        Reservation(const std::string& m_res);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };

    void trim(std::string& m_res);

}

#endif //INC_3RDSEMESTER_RESERVATION_H
