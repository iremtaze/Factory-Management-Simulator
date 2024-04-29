/*İREM TAZE 150200086*/
#include "./worker.hpp"


//worker constructor implementation using the Unit constructor and initializing the experience to 0
Worker::Worker(std::string name, float cost_per_day, float base_return_per_day) :
    Unit(name, cost_per_day, base_return_per_day), m_experience(0) {}


void Worker::increaseHeadWorkerCount() {
    m_num_head_workers++;
}

int Worker::getExperience() const {
    return m_experience;
}

float Worker::getReturnPerDay() {
    //ATTENTION !! BE CAREFUL !! THERE IS OVERRIDING OF getReturnPerDay() FUNCTION
    float base_return = Unit::getReturnPerDay();

    float daily_return = base_return + (m_experience * 2) + (m_num_head_workers * 3);

    //every time getReturnPerDay is called, the worker's experience is increased by 1
    m_experience++;

    if(m_experience == 10) {
        increaseHeadWorkerCount();
    }

    return daily_return;
}