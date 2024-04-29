/*İREM TAZE 150200086*/

#include "./headworker.hpp"

// This uses the implicitly-defined copy constructor of Worker.
HeadWorker::HeadWorker( Worker &worker) 
: Worker(worker) { // Here you should pass the worker object to the Worker copy constructor
    increaseHeadWorkerCount(); 
}

/*Head worker is a kind of worker. It has a higher return than the regular worker. You can not directly hire
the head worker. You need to wait for 10 days after hiring a worker then it will be promoted automatically
by the Factory.
Implement declared functions in the header file. To implement the getReturnPerDay() function, use
the following formula:
daily return = (base return) + (experience) ∗ 5
*/
float HeadWorker::getReturnPerDay() {   
    float base_return = Worker::getReturnPerDay();
    float dailyreturn = base_return + (m_experience * 5);
    return dailyreturn;

 }
    

