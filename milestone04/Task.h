// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/12/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#pragma once
#ifndef TASK_H
#define TASK_H
#include "Item.h"
#include "CustomerOrder.h"
#include <deque>
#include <iostream>

class Task : public Item {
    std::deque<CustomerOrder> m_orders;
    Task* m_pNextTask;
    
    public:
        Task(const std::string&);

        Task(const Task&) = delete;
        Task& operator =(const Task&) = delete;
        Task(const Task&&) = delete;
        Task& operator =(const Task&&) = delete;

        void runProcess(std::ostream&);
        bool moveTask();
        void setNextTask(Task&);
        bool getCompleted(CustomerOrder&);
        void validate(std::ostream&);
        Task& operator += (CustomerOrder&&);

};

#endif // TASK_H