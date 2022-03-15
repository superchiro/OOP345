// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/12/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#pragma once
#ifndef LINE_MANAGER_H
#define LINE_MANAGER_H
#include "Task.h"
#include "CustomerOrder.h"
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class LineManager{

    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
    Task* firstTask;
    Task* lastTask;

    public: 
        LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
        bool run(std::ostream&);
        void displayCompleted(std::ostream&) const;
        void validateTasks() const;

};



#endif //LINE_MANAGER_H