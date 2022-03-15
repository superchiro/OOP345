#include "Task.h"

Task::Task(const std::string& str) : Task::Item(str){
    pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os){


    if(!m_order.empty()){
        if(!m_order.back().getItemFillState(this->getName())){
            m_order.back().fillItem(*this, os);
        }
    }
}


bool Task::moveTask(){

    if(!m_order.empty()){
        if (pNextTask != nullptr && m_order.back().getItemFillState(getName())) {
            pNextTask -> m_order.push_front(std::move(m_order.back()));
            m_order.pop_back();
        } else {
            return false;
        }
    }
    return true;
}

void Task::setNextTask(Task& obj){
    pNextTask = &obj;
}

bool Task::getCompleted(CustomerOrder& obj){
    if (!m_order.empty() && m_order.back().getOrderFillState()) {
        obj = std::move(m_order.back());
        m_order.pop_back();
        return true;
    }
    return false;

}

void Task::validate(std::ostream& os){
    if(pNextTask != nullptr){
        os << getName() << " --> " << pNextTask->getName() << std::endl;
    } else {
        os << getName() << " --> " << "END OF LINE" << std::endl;
    }
}

Task& Task::operator+=(CustomerOrder&& obj){
    m_order.push_front(std::move(obj));
    return *this;
}
