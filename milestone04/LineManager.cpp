// Name: Chihiro Kawaguchi
// Seneca Student ID: 127694180
// Seneca email: ckawaguchi@myseneca.ca
// Date of completion: 2019/12/01
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#include "LineManager.h"

LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& ToFill){
    bool more;
	Utilities m_util;
    std::ifstream file(fileName);
    std::string str;
    size_t cnt;
    std::vector<Task*> startingTasks;
    if(!file){
        std::cout << "Unable to open the file";
    } 
    
    while(!file.eof()){
        size_t next_pos = 0;
        more = true;
        std::getline(file, str);
        std::string cur = m_util.extractToken(str, next_pos, more);
        std::string next;
        if(more){
            next = m_util.extractToken(str, next_pos, more);
        }

        for(size_t i = 0; i < tasks.size(); i++){
            if(tasks[i] -> getName() == cur){
                cnt = i;
            }
        }
                       // std::cout << tasks[curN] -> getName();

        if(next.size()!= 0){
            for(size_t i = 0; i < tasks.size(); i++){
                if(tasks[i] -> getName() == next){
                    tasks[cnt] -> setNextTask(*tasks[i]);
                    startingTasks.push_back(tasks[i]);
                } 
            }
        }
    }
    file.close();
    
    for(size_t i = 0; i < tasks.size(); i++){
        if(tasks[i] != startingTasks[i]){
            firstTask = tasks[i];
        } else{
            lastTask = tasks[i];
        }
    }




    for(size_t i = 0; i < ToFill.size(); i++){
        ToBeFilled.push_front(std::move(ToFill[i]));
    }

   for(size_t i = 0; i < tasks.size(); i++){
        AssemblyLine.push_back(tasks[i]);
    }

    m_cntCustomerOrder = ToFill.size();
}

bool LineManager::run(std::ostream& os){
    if(!ToBeFilled.empty()){
        *firstTask += std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
    }


    for(auto task: AssemblyLine){
        task->runProcess(os);
    }

    for(auto task: AssemblyLine){
        task->moveTask();
    }


    CustomerOrder tmpObj;
    
    if(lastTask->getCompleted(tmpObj)){
        Completed.push_back(std::move(tmpObj));
    }

    return(Completed.size() == m_cntCustomerOrder);

}

void LineManager::validateTasks() const{
    for(size_t i = 0; i < AssemblyLine.size(); i++){
        AssemblyLine[i]->validate(std::cout);
    }
}

void LineManager::displayCompleted(std::ostream& os) const{
    for(size_t i = 0; i < Completed.size(); i++){
        Completed[i].display(os);
    }
}