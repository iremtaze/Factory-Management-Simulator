/*İREM TAZE 150200086*/

#include "./simulation.hpp"
#include "./worker.hpp"
#include "./machine.hpp"
#include "./factory.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::istringstream;
using std::string;

// Constructor
Simulation::Simulation(Factory &factory, int total_days, string workers_list_path, string machines_list_path)
    : m_factory(&factory), m_total_days(total_days)
{
    srand(time(nullptr)); // Seed for random number generation

    // Load workers from file
    ifstream workerFile(workers_list_path);
    if (!workerFile) {
        cout << "Error: could not open file " << workers_list_path << endl;
        exit(1);
    }
    string line;
    while (getline(workerFile, line)) {
        istringstream iss(line);
        string workerName;
        float dailyCost, dailyReturn;
        if (iss >> workerName >> dailyCost >> dailyReturn) {
            m_labor_market.emplace_back(workerName, dailyCost, dailyReturn);
        }
    }
    workerFile.close();

    // Load machines from file
    ifstream machineFile(machines_list_path);
    if (!machineFile) {
        cout << "Error: could not open file " << machines_list_path << endl;
        exit(1);
    }
    while (getline(machineFile, line)) {
        istringstream iss(line);
        string machineName;
        float price, dailyCostMachine, dailyReturnMachine, failProb, repairCost;
        int repairTime;
        if (iss >> machineName >> price >> dailyCostMachine >> dailyReturnMachine >> failProb >> repairCost >> repairTime) {
            m_machines_market.emplace_back(machineName, price, dailyCostMachine, dailyReturnMachine, failProb, repairTime, repairCost);
        }
    }
    machineFile.close();
}

// Buy a random machine from the market
Machine Simulation::buyRandomMachine() {
    int index = rand() % m_machines_market.size(); // Generate a random index
    cout << m_machines_market[index].getName() << " is bought." << endl;
    return m_machines_market[index];
}

// Hire a random worker from the market
Worker Simulation::hireRandomWorker() {
    int index = rand() % m_labor_market.size(); // Generate a random index
    cout << m_labor_market[index].getName() << " is hired." << endl; 
    return m_labor_market[index];
}

// Main simulation run loop
void Simulation::run() {
    int day = 0; // Initialize day counter
    printWelcomeMessage();

    while (day < m_total_days) {
        cout << "Enter command: ";
        string command;
        cin >> command;
        
        // Extract action and number from command
        char action = command[0];
        int number = (command.size() > 1) ? stoi(command.substr(1)) : 0;

        switch (action) {
            case 'w': // Add workers
                for (int i = 0; i < number; i++) {
                    Worker newWorker = hireRandomWorker();
                    m_factory->addUnit(newWorker);
                }
                break;
            case 'm': // Add machines
                for (int i = 0; i < number; i++) {
                    Machine newMachine = buyRandomMachine();
                    m_factory->addUnit(newMachine);
                }
                break;
            case 'p': // Pass days
                for (int i = 0; i < number; i++) {
                    m_factory->passOneDay();
                    cout << "--- Day: " << (day + 1) << " ---" << endl;
                    cout << "Capital: " << m_factory->getCapital() << ", "
                         << "Workers: " << m_factory->getWorkerCount() << ", "
                         << "Machines: " << m_factory->getMachineCount() << ", "
                         << "Head Workers: " << m_factory->getHeadWorkerCount() << endl;
                    if (m_factory->isBankrupt()) {
                        cout << "The factory has gone bankrupt." << endl;
                        return;
                    }
                    day++; // Increment day counter
                }
                break;
            case 'q': // Quit simulation
                cout << "Exiting the simulation." << endl;
                return;
            default:
                cout << "Invalid command." << endl;
                break;
        }
    }
    cout << "Congratulations! You have earned " << m_factory->getCapital() << " in " << m_total_days << " days." << endl;
}

void Simulation::printWelcomeMessage() const
{
    cout << "Welcome to the Car Factory!" << endl;
    cout << "You have " << m_total_days << " days to make as much money as possible" << endl;
    cout << "You can add workers, machines, and fast forward days" << endl;

    cout << "Available commands:" << endl;
    cout << "    wX: adds X workers" << endl;
    cout << "    mX: adds X machines" << endl;
    cout << "    pX: passes X days" << endl;
    cout << "    q: exit the game properly" << endl;
}
