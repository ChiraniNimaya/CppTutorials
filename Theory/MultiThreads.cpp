#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

std::mutex carMutex;
static std::atomic<int> driveRounds = 0; //atomic variables are thread safe

void driveCar(std::string driverName)
{
    std::lock_guard<std::mutex> carLock(carMutex); //avoid deadlocks and unlock when descoped, cannot unlock manually
    //carMutex.lock() //have risk of deadlock and should be unlocked manually
    //std::unique_lock<std::mutex> carLock(carMutex);  //avoid deadlocks and unlock when descoped, can unlock manually
    std::cout << driverName << " is driving car." << std::endl;
    driveRounds.fetch_add(1);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << driverName << " is done driving." << std::endl;
    //carLock.unlock(); //manual unlock
}

int main()
{
    std::string driverName1 = "John";
    std::string driverName2 = "Amy";

    std::thread t1(driveCar, driverName1);
    std::thread t2(driveCar, driverName2);

    std::cout << " Thread1 id - " << t1.get_id() << std::endl;
    std::cout << " Thread2 id - " << t2.get_id() << std::endl;

    //End threads
    t1.join();
    t2.join();
    //wait is over for both threads

    std::cout << "Wait is over, Main thread is calling." << std::endl;
    std::cout << "Drive rounds = " << driveRounds.load() << std::endl;
    
    
    return 0;

}

// The RAII (Resource Acquisition Is Initialization) principle ensures that 
// resources are properly managed and do not lead to resource leaks or undefined behavior.