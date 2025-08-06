#include <iostream>
using namespace std;

// Exception rule.
// A subclass should throw fewer or narrower exception. but not exceptional or broader exceptions than the parent.
// C++ does not enforce this. Hence no compilation error.

/*
std::exception
│
├── std::logic_error        // Compile-time logical errors
│   ├── std::invalid_argument
│   ├── std::domain_error
│   ├── std::length_error
│   └── std::out_of_range
│
├── std::runtime_error      // Errors detectable only at runtime
│   ├── std::range_error
│   ├── std::overflow_error
│   ├── std::underflow_error
│   └── std::ios_base::failure
│
├── std::bad_alloc
├── std::bad_cast
├── std::bad_typeid
└── std::bad_exception
*/

class Parent
{
public:
    virtual void getValue() noexcept(false)
    {
        throw logic_error("Parent error");
    }
};

class Child : public Parent
{
public:
    void getValue() noexcept(false) override
    {
        throw out_of_range("child error");
    }
};

class Client
{
public:
    Parent *p;
    Client(Parent *p) : p(p) {}

    void takeValue()
    {
        try
        {
            p->getValue();
        }
        catch (const logic_error &e)
        {
            cout << "Logic error exception occured : " << e.what() << endl;
        }
    }
};

int main()
{
    Parent *p = new Parent();
    Parent *c = new Child();

    // Client *client = new Client(p);
    Client *client = new Client(c);
    client->takeValue();
}