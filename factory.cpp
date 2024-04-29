/*İREM TAZE 150200086*/

#include "./factory.hpp"
using std::cout;
using std::endl;
using std::stoi;

Factory:: Factory(float capital) : m_capital(capital), m_is_bankrupt(false) {}

void Factory::addUnit(const Worker &rhs_worker) {
    m_workers.push_back(rhs_worker);
}

void Factory::addUnit(const Machine &rhs_machine) {
    m_machines.push_back(rhs_machine);
}

bool Factory::isBankrupt() const {
    return m_is_bankrupt;
}

float Factory::getCapital() const {
    return m_capital;
}

int Factory::getWorkerCount() const {
    return m_workers.size();
}

int Factory::getMachineCount() const {
    return m_machines.size();
}

int Factory::getHeadWorkerCount() const {
    return m_head_workers.size();
}
void Factory::passOneDay(){
    for (auto &worker : m_workers){
        m_capital -= worker.getCostPerDay();
        m_capital += worker.getReturnPerDay();
    }
    for (auto &head_worker : m_head_workers){
        m_capital -= head_worker.getCostPerDay();
        m_capital += head_worker.getReturnPerDay();
    }
    for (auto &machine : m_machines){
        m_capital -= machine.getCostPerDay();
        m_capital += machine.getReturnPerDay();
    }
    if (m_capital < 0){
        m_is_bankrupt = true;
    }   
    for (auto temp = m_workers.begin(); temp != m_workers.end();){
        if (temp->getExperience() > 10){
            HeadWorker head_worker(*temp);
            m_head_workers.push_back(head_worker);
            cout<< temp->getName() << " has been promoted." << endl;
            temp = m_workers.erase(temp);
        } else {
            ++temp;
        }
    }
}