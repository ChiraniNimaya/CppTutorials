#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

bool bufferedFileLoader()
{
    //Do some file loading task
    size_t bytesLoaded = 0;
    while (bytesLoaded < 20000)
    {
        std::cout << "thread: loading file ... \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 1000;
    }

    return true;
}

int main()
{
    //std::future<result_type> = std::async(std::launch_policy, funtion, args)
                                    // std::launch::async -> launch the thread asynchronously
                                    // std::launch::deferred -> executed only when requested
    std::future<bool> backgroundThread = std::async(std::launch::async, bufferedFileLoader);

    // enum class future_status {
    //     ready, 
    //     timeout,
    //     deferred
    // };
    std::future_status status;

    //Main program loop
    while(true)
    {
        std::cout << "Main thread is running\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        //waits for the result, returns if it is not available for the specified timeout duration
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));

        //If data is ready(background thread has completed)
        if (status == std::future_status::ready)
        {
            std::cout << "Result is ready\n";
            break;
        }
    }

    std::cout << "Programe is terminated\n";

    return 0;
}