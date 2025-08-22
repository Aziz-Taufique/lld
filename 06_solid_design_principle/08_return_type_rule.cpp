#include <iostream>

// Return type rule.
// Subtype overriden method return type should be either identical. or narrower then the partent's method's return type.
// This is also called as return type covariance.
// c++ enforce this by covariance.
class Animal
{
    // some common animal method;
};

class Dog : public Animal
{
    // Additiocal dog methods specific to dog.
};

class Parent
{
public:
    virtual Animal *getAnimal()
    {
        std::cout << "Paretn: Returning animal instance" << std::endl;
        return new Animal();
    }
};

class Child : public Parent
{
public:
    Animal *getAnimal() override
    {

        std::cout << "Child: Returning dog instance" << std::endl;
        return new Dog();
    }
};

class Client
{
    Parent *p;

public:
    Client(Parent *p) : p(p) {}

    void takeAnimal()
    {
        p->getAnimal();
    }
};

int main()
{
    Parent *p = new Parent();
    Parent *c = new Child();
    Client *client = new Client(p);
    // Client *client = new Client(c);
    client->takeAnimal();
    return 0;
}