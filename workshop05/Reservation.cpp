//
// Created by user on 2019-09-30.
//

#include <iomanip>
#include <string>
#include "Reservation.h"

//using namespace std;

namespace sdds {

    Reservation::Reservation() {

        resId = {};
        resName = {};
        mail = {};
        num = 0;
        day = 0;
        hour = 0;
    }

    void trim(std::string& str) {

        size_t i = 0;
        for (i = 0; i < str.length() && str[i] == ' '; i++){
            str = str.substr(i);
        }

        for (i = str.length(); i > 0 && str[i] == ' '; i--) {
            str = str.substr(i);
        }
    }

    Reservation::Reservation(const std::string& m_res) {

        std::string copy = m_res;
        trim(copy);

        size_t position = copy.find(":");
        resId = copy.substr(0, position);
        trim(resId);
        copy.erase(0, position + 1);

        position = copy.find(",");
        resName = copy.substr(0, position);
        trim(resName);
        copy.erase(0, position + 1);

        position = copy.find(",");
        mail = copy.substr(0, position);
        trim(mail);
        copy.erase(0, position + 1);

        position = copy.find(",");
        num = std::stoi(copy.substr(0, position));
        copy.erase(0, position + 1);

        position = copy.find(",");
        day = std::stoi(copy.substr(0, position));
        copy.erase(0, position + 1);

        position = copy.find(",");
        hour = std::stoi(copy.substr(0, position));
        copy.erase(0, position + 1);
    }

    std::ostream &operator<<(std::ostream &os, const Reservation& res) {

        if (res.hour > 5 && res.hour < 10) {

            os << "Reservation" << res.resId << ":"
            << std::setw(10) << std::left << res.resName
            << std::setw(20) << std::left << "<" << res.mail << ">"
            << "Breakfast on day " << res.day
            << " @ " << res.hour
            << " for " << res.num  << " people";

        } else if (res.hour > 10 && res.hour < 16) {

            os << "Reservation" << res.resId << ":"
               << std::setw(10) << std::left << res.resName
               << std::setw(20) << std::left << "<" << res.mail << ">"
               << "Lunch on day " << res.day
               << " @ " << res.hour
               << " for " << res.num  << " people";

        }  else if (res.hour > 16 && res.hour < 22) {

            os << "Reservation" << res.resId << ":"
               << std::setw(10) << std::left << res.resName
               << std::setw(20) << std::left << "<" << res.mail << ">"
               << "Dinner on day " << res.day
               << " @ " << res.hour
               << " for " << res.num  << " people";

        } else {

            os << "Reservation" << res.resId << ":" ;
            os << std::setw(10) << std::left << res.resName;
            os << std::setw(20) << std::left << "<" << res.mail << ">";
            os << "Drinks on day " << res.day;
            os << " @ " << res.hour;
            os << " for " << res.num  << " people";

        }

        os << std::endl;

        return os;
    }


}