#include <iostream>

// Abstract Factory method:-
//  provides an interface for creating families of related objects without specifying there concrete class.

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

class GarlicBread
{
public:
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        std::cout << "Preparing basic garlic bread" << std::endl;
    }
};

class CheeseGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        std::cout << "Preparing basic cheese barlic bread" << std::endl;
    }
};

class BasicWheatBread : public GarlicBread
{
public:
    void prepare() override
    {
        std::cout << "Preparing basic wheat bread" << std::endl;
    }
};

class CheeseWheatBread : public GarlicBread
{
public:
    void prepare() override
    {
        std::cout << "Preparing basic cheese bread" << std::endl;
    }
};

class MealFactory
{
public:
    virtual Burger *createBurger(std::string type) = 0;
    virtual GarlicBread *createGarlicBread(std::string type) = 0;
};

class SinghBurger : public MealFactory
{
public:
    Burger *createBurger(std::string type) override
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

    GarlicBread *createGarlicBread(std::string type) override
    {
        if (type == "basic")
            return new BasicGarlicBread();
        else if (type == "cheese")
            return new CheeseGarlicBread();
        else
        {
            std::cout << "Invalid cheese garlic bread type" << std::endl;
            return nullptr;
        }
    }
};

class KingBurger : public MealFactory
{
public:
    Burger *createBurger(std::string type) override
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

    GarlicBread *createGarlicBread(std::string type)
    {
        if (type == "basic")
            return new BasicGarlicBread();
        else if (type == "cheese")
            return new CheeseGarlicBread();
        else
        {
            std::cout << "Invalid garlic bread type." << std::endl;
            return nullptr;
        }
    }
};

int main()
{
    std::string burgerType = "standard";
    std::string garlicBreadType = "cheese";

    MealFactory *mealFactory = new KingBurger();

    Burger *getBurger = mealFactory->createBurger(burgerType);
    GarlicBread *garlicBread = mealFactory->createGarlicBread(garlicBreadType);

    getBurger->prepare();
    garlicBread->prepare();
}