#include <iostream>
#include <mutex>
#include <thread>

int cnt = 0;

class Singleton
{
private:
    static Singleton *instance;
    Singleton()
    {
        std::cout << "Singleton constructor called." << std::endl;
    }

public:
    static Singleton *getInstance()
    {
        return instance;
    }
};

Singleton *Singleton::instance = new Singleton();

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    std::cout << (s1 == s2) << std::endl;
    return 0;
}