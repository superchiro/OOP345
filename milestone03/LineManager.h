

#ifndef INC_3RDSEMESTER_LINEMANAGER_H
#define INC_3RDSEMESTER_LINEMANAGER_H

#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Task.h"
#include "CustomerOrder.h"


class LineManager {
    std::vector<Task*> AssemblyLine; //reference of task obj assembly line
    std::deque<CustomerOrder> ToBeFilled; //task that need to be filled
    std::deque<CustomerOrder> Completed; //task that completed
    unsigned int m_cntCustomerOrder; // num of customerorder obj start line
    Task* firstTask;
    Task* lastTask;

public:
    LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;



};

#endif //INC_3RDSEMESTER_LINEMANAGER_H
