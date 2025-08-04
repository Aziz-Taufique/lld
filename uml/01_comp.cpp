#include <iostream>

class A
{
public:
    void printA()
    {
        std::cout << "Hello from calss A" << std::endl;
    }
};

class B
{

public:
    A *a;

    B()
    {
        a = new A();
    }

    void printB()
    {
        std::cout << "Hello from class B" << std::endl;
    }
};

int main()
{
    B *b = new B();
    b->printB();
    b->a->printA();
}