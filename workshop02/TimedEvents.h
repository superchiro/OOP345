// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/09/23
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef INC_3RDSEMESTER_TIMEDEVENTS_H
#define INC_3RDSEMESTER_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <iomanip>

namespace sdds {

    const int max_num = 7;
    //static int record[max_num];

    class TimedEvents {

        int recordNum;

        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

        struct {

            const char* eventName;
            const char* time;
            std::chrono::steady_clock::duration recTime;
        }record[max_num];

    public:

        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char* event);
        friend std::ostream& operator<<(std::ostream& os, const TimedEvents&);

    };

}


#endif //INC_3RDSEMESTER_TIMEDEVENTS_H
