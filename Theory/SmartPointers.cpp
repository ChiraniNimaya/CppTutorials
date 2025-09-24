#include <iostream>
#include <memory>

int main(){
    std::cout << "\n=================Unique Pointer=================\n";
    std::unique_ptr<int> u1(new int(1));
    std::unique_ptr<int> u2 = std::make_unique<int>(2);
    std::unique_ptr<int> u3 = std::move(u1); //now u1 is null, ownership is transferred
    // std::unique_ptr<int> u4 = u2; // error: cannot copy unique_ptr
    std::cout << "u3 value: " << *u3 << std::endl;

    std::cout << "\n=================Shared Pointer=================\n";
    // the memory is deallocated only in case of last shared_ptr object will be deleted - like Garbage collector
    std::shared_ptr<int> sharedInt = std::make_shared<int>(12);
    std::cout << *sharedInt << std::endl; // 12
    std::shared_ptr<int> sharedInt2 = sharedInt;
    *sharedInt = 100;
    std::cout << *sharedInt << std::endl; // 100
    std::cout << *sharedInt2 << std::endl; // 100
    std::cout << sharedInt.use_count() << std::endl; // 2
    sharedInt.reset();
    std::cout << sharedInt.use_count()  << std::endl; // 0
    std::cout << sharedInt2.use_count() << std::endl; // 1

    std::cout << "\n=================Weak Pointer=================\n";
    std::shared_ptr<int> sharedInt3 = std::make_shared<int>(42);
    std::weak_ptr<int> weakInt = sharedInt3;
    std::cout << "Owners: " << sharedInt3.use_count() << std::endl;
    
    if (auto shared = weakInt.lock()) {
        std::cout << "Value: " << *shared << std::endl;
    } else {
        std::cout << "Not available" << std::endl;
    }
    // freeing the shared pointer
    sharedInt3.reset();
    if (auto shared = weakInt.lock()) {
        std::cout << "Value: " << *shared << std::endl;
    } else {
        std::cout << "Not available" << std::endl;
    }

    return 0;
}