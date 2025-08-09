#include <iostream>

// Siple Factory:- A factory class that decides which concrete class to instantiate.

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        std::cout << "Preparing basic burger" << std::endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        std::cout << "Preparing Standard burger" << std::endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        std::cout << "Preparing premium burger" << std::endl;
    }
};

class BurgerFactory
{
public:
    Burger *prepareBurger(std::string type)
    {
        if (type == "basic")
            return new BasicBurger();
        else if (type == "standard")
            return new StandardBurger();
        else if (type == "premium")
            return new PremiumBurger();
        else
        {
            std::cout << "Invalid burger type" << std::endl;
            return nullptr;
        }
    }
};

int main()
{
    std::string burgerType = "standard";
    BurgerFactory *burgerFactory = new BurgerFactory();
    Burger *burger = burgerFactory->prepareBurger(burgerType);
    Burger *burger2 = burgerFactory->prepareBurger("basic");
    burger->prepare();
    burger2->prepare();
}