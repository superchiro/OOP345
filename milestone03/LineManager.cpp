#include "LineManager.h"

LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& ToFill){
    bool more;
    Utilities m_util;
    std::ifstream file(fileName);
    std::string str;
    size_t curN;
    std::vector<Task*> startTask;
    std::vector<Task*> endTask;
    if(!file){
        std::cout << "Unable to open file";
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
                curN = i;
            }
        }
        // std::cout << tasks[curN] -> getName();

        if(next.size()!= 0){
            for(size_t i = 0; i < tasks.size(); i++){
                if(tasks[i] -> getName() == next){
                    tasks[curN] -> setNextTask(*tasks[i]);
                    startTask.push_back(tasks[i]);
                }
            }
        }
    }
    file.close();

    for(size_t i = 0; i < tasks.size(); i++){
        if(tasks[i] != startTask[i]){
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

    for(size_t i = 0; i < AssemblyLine.size(); i ++){
        AssemblyLine[i]->runProcess(os);
    }

    for(size_t i = 0; i < AssemblyLine.size(); i ++){
        AssemblyLine[i]->moveTask();
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