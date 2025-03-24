#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

//global variables
std::mutex gMutex;
std::condition_variable gConditionVariable;

int main()
{
    //result of worker thread
    int result = 0;
    //bool which indicates whether work has done or not
    bool notified = false;

    //Reporting thread, must wait until work is done by worker
    std::thread reporter([&]
    {
        std::unique_lock<std::mutex> reporterLock(gMutex);
        if (!notified)
            gConditionVariable.wait(reporterLock);
        std::cout << "Result = " << result << ", reported by Reporter\n";
    });

    //Working thread
    std::thread worker([&]
    {
        //lock before start work
        std::unique_lock<std::mutex> workerLock(gMutex);

        //work
        result = 4 + 3 + 199;

        //work is done, notify it
        notified = true;

        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Work has done\n";

        //Wake up another waiting thread
        gConditionVariable.notify_one();

        

    });

    reporter.join();
    worker.join();

    std::cout << "Program is completed\n";

    return 0;
}