// singleton design principle:- create a single obj.
// 1. create a private constructor
// 2. Create a static instance (getInstance) that returns the same instance every time.

// use case:-
// 1. logging system. -> logger
// 2. database system.
// 3. configuration manger.

#include <iostream>
#include <mutex>
#include <thread>

int cnt = 0;

class Singleton
{
private:
    static Singleton *instance;
    static std::mutex m;
    Singleton()
    {
        std::cout << "Singleton constructor called." << std::endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(m);
            if (instance == nullptr)
            {
                cnt++;
                instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton *Singleton::instance = nullptr;
std::mutex Singleton::m;

int main()
{
    // Singleton *s1 = Singleton::getInstance();
    // Singleton *s2 = Singleton::getInstance();

    // std::thread t1(&Singleton::getInstance);
    // std::thread t2(&Singleton::getInstance);

    // t1.join();
    // t2.join();

    // std::cout << cnt << std::endl;

    Singleton *ptr1 = nullptr;
    Singleton *ptr2 = nullptr;

    std::thread t1([&]()
                   { ptr1 = Singleton::getInstance(); });

    std::thread t2([&]()
                   { ptr2 = Singleton::getInstance(); });

    t1.join();
    t2.join();

    std::cout << "Constructor call count: " << cnt << std::endl;
    std::cout << "Are objects identical? " << (ptr1 == ptr2 ? "Yes" : "No") << std::endl;
    std::cout << "ptr1 address: " << ptr1 << "\nptr2 address: " << ptr2 << std::endl;

    // std::cout << (s1 == s2) << std::endl;
    return 0;
}