/*İREM TAZE 150200086*/

#include "./machine.hpp"
#include <cstdlib> // For std::rand()

Machine::Machine(std::string name, float price, float cost_per_day, float base_return_per_day, float failure_probability, int repair_time, float repair_cost)
    : Unit(name, cost_per_day, base_return_per_day), m_failure_probability(failure_probability), m_repair_time(repair_time), m_price(price), m_repair_cost(repair_cost), m_days_until_repair(0) {}

/*Implement declared functions in the header file. Inside the getReturnPerDay() function, follow the
these steps:
1. Check if the machine is currently broken. If so, return 0.
2. Machine will fail with probability m_failure_probability. Using std::rand() function, check if
it is failed or not. If it fails, it will not be used for m_repair_time days. And return -m_repair_cost
3. If it does not fail, return the base return value*/

float Machine::getReturnPerDay() {
    if(m_days_until_repair > 0) {
        m_days_until_repair--; // Decrease the days until repair BECAUSE THE MACHINE IS BROKEN
        return 0;
    }
    

    if(std::rand() % 100 < m_failure_probability * 100) {
        m_days_until_repair = m_repair_time - 1;
        return -m_repair_cost; //// Return the negative repair cost indicating a failure cost
    }


    return Unit::getReturnPerDay();

}   

float Machine::getPrice() const {
    return m_price;
}

