// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "TimedEvents.h"

namespace sdds {

    TimedEvents::TimedEvents() {
        recordNum = 0;
    }

    void TimedEvents::startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::recordEvent(const char *event) {

        auto nano = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
        if (recordNum < max_num) {
            record[recordNum].eventName = event;
            record[recordNum].time = "nanoseconds";
            record[recordNum].recTime = nano;
            recordNum++;
        }

    }

    std::ostream &operator<<(std::ostream &os, const TimedEvents& obj) {

        os << "Execution Times:" << std::endl;
        os << "--------------------------" << std::endl;
        for(int i = 0; i < obj.recordNum; i++) {
            os << std::setw(20) <<  std::left << obj.record[i].eventName;
            os << std:: setw(12) <<  std::right <<  obj.record[i].recTime.count() << ' ';
            os <<obj.record[i].time << std::endl;
        }
        os << "--------------------------" << std::endl;
        return os;
    }


}




