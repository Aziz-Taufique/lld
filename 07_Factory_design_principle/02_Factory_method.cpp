#include <iostream>

// Factory method:- Defines an interface for creating objects but allows subclasses to decide which class to instantiate.

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

class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        std::cout << "Preparing basic wheat burger" << std::endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        std::cout << "Preparing Standard wheat burger" << std::endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        std::cout << "Preparing premium wheat burger" << std::endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *createBurger(std::string type) = 0;
};

class SinghBurger : public BurgerFactory
{
public:
    Burger *createBurger(std::string type)
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

class KingBurger : public BurgerFactory
{
public:
    Burger *createBurger(std::string type)
    {
        if (type == "basic")
            return new BasicWheatBurger();
        else if (type == "standard")
            return new StandardWheatBurger();
        else if (type == "premium")
            return new PremiumWheatBurger();
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

    BurgerFactory *burgerFactory = new KingBurger();
    Burger *burger = burgerFactory->createBurger(burgerType);
    burger->prepare();

    BurgerFactory *singhBurger = new SinghBurger();
    Burger *burger2 = singhBurger->createBurger("basic");
    burger2->prepare();
}