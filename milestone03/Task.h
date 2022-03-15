

#ifndef INC_3RDSEMESTER_TASK_H
#define INC_3RDSEMESTER_TASK_H

#include <deque>
#include <iostream>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {

    std::deque<CustomerOrder> m_order;
    Task* pNextTask;

public:
    Task(const std::string&);

    Task(Task&) = delete;
    Task(Task&&) = delete;
    Task& operator=(Task&) = delete;
    Task& operator=(Task&&) = delete;

    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream& os);
    Task& operator+=(CustomerOrder&&);




};

#endif //INC_3RDSEMESTER_TASK_H
