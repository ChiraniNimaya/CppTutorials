#include <iostream>
#include <memory>
#include <fstream>
#include <thread>

//Resource Acquisition Is Initialization
//Suppose there is a  “resource” in terms of Files, Memory, Sockets, etc.  
//RAII means that an object’s creation and destruction are tied to a resource being acquired and released.

class FileHandler{
    private:
        std::ofstream fileStream;
    public:
        FileHandler(const std::string& fileName) : fileStream(fileName) 
        {
            if (!fileStream.is_open()){
                throw std::runtime_error("Unable to open file");
            }
        }
        ~FileHandler()
        {
            if (fileStream.is_open()){
                fileStream.close();
            }
        }
        void writeToFile (const std::string& data)
        {
            fileStream << data;
        }
};

class ThreadWrapper{
    private:
        std::thread *thr;
    public:
        ThreadWrapper(std::thread *t) : thr(t) {
            std::cout << "Wrapper constructor is called\n";
        }
        ~ThreadWrapper() {
            thr->join(); //even if an exception is thrown, cleanup is guaranteed
            std::cout << "Wrapper destructor is called\n";
        }
};

void func2()
{
    std::cout << "We are in func2\n";
}

void func1()
{
    std::cout << "We are in func1\n";
    std::thread t1(func2);
    ThreadWrapper w(&t1);
    std::exception e;

    try
    {
        for (int i = 0; i < 100; i++)
        {
            //Lets say an exception is thrown at some condition
            if (i == 60)
                throw e;
        }
    }
    catch (...)
    {
        throw;
    }

//    t1.join();
}


int main(){
    std::cout << "\n=================RAII for File Handling=================\n";
    try {
        FileHandler fileHandler("example.txt");
        fileHandler.writeToFile("Hello, RAII!");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n=================RAII for Threads=================\n";
    try {
        func1();
    }
    catch (...) {
    }
    return 0;
}