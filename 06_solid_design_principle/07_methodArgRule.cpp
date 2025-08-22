#include <iostream>

// Method arg rules:-
// Subtype method arguments can be identical or wider than the supertype.
// cpp impose this by keeping signature identical.
class Parent
{
public:
    virtual void printMsg(std::string msg)
    {
        std::cout << "Parent: " << msg << std::endl;
    }
};

class Child : public Parent
{
public:
    void printMsg(std::string msg) override
    {
        std::cout << "Child " << msg << std::endl;
    }
};

class Client
{
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }

    void print(std::string msg)
    {
        p->printMsg(msg);
    }
};

int main()
{
    Parent *parent = new Parent();
    Parent *child = new Child();

    // Client *client = new Client(parent);
    Client *client = new Client(child);
    client->print("looo");
    return 0;
}
