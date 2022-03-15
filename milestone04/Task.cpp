// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/12/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#include "Task.h"

Task::Task(const std::string& str) : Task::Item(str){
    m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os){


   if(!m_orders.empty()){
        if(!m_orders.back().getItemFillState(this->getName())){
            m_orders.back().fillItem(*this, os);
        }
    }
}


bool Task::moveTask(){

    bool move = true;

    if(!m_orders.empty()){
        if (m_pNextTask != nullptr && m_orders.back().getItemFillState(getName())) {
            m_pNextTask -> m_orders.push_front(std::move(m_orders.back()));
            m_orders.pop_back();
         } else {
             move = false;
         }
	} 
    return move;
}

void Task::setNextTask(Task& src){
    m_pNextTask = &src;
} 

bool Task::getCompleted(CustomerOrder& src){

    bool complete = false;

	if (!m_orders.empty() && m_orders.back().getOrderFillState()) {
		src = std::move(m_orders.back());
		m_orders.pop_back();
		complete = true;
	}
	return complete;

}

void Task::validate(std::ostream& os){
    if(m_pNextTask != nullptr){
        os << getName() << " --> " << m_pNextTask->getName() << std::endl;
    } else {
        os << getName() << " --> " << "END OF LINE" << std::endl;
    }
}

Task& Task::operator+=(CustomerOrder&& src){
    m_orders.push_front(std::move(src));
    return *this;
}
