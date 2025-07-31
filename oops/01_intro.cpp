#include <iostream>

class Car
{
public:
    virtual void startCar() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopCar() = 0;
    ~Car() {}
};

class SportsCar : public Car
{
public:
    int speed;
    int gear;
    std::string name;
    std::string model;
    bool isEngineOn;

    SportsCar(std::string name, std::string model)
    {
        this->name = name;
        this->model = model;
        isEngineOn = false;
        speed = 0;
        gear = 0;
    }

    void startCar() override
    {
        if (!isEngineOn)
        {
            isEngineOn = true;
            std::cout << "Engine started." << std::endl;
        }
    }

    void shiftGear(int gear)
    {
        if (!isEngineOn)
        {
            std::cout << "Engine is off cannot shift gear" << std::endl;
            return;
        }
        this->gear = gear;
        std::cout << "Gear shifted to " << gear << std::endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            std::cout << "Engine is off cannot accelerate" << std::endl;
        }
        speed += 20;
        std::cout << "Accelerated. Speed is now " << speed << std::endl;
    }

    void stopCar()
    {
        if (isEngineOn)
        {
            isEngineOn = false;
            speed = 0;
            gear = 0;
            std::cout << "Car stopped." << std::endl;
        }
    }

    void brake()
    {
        if (isEngineOn && speed > 0)
        {
            speed -= 10;
            std::cout << "Braked. Speed is now " << speed << std::endl;
        }
        else
        {
            std::cout << "Cannot brake. Either engine is off or speed is already 0." << std::endl;
        }
    }

    void display()
    {
        std::cout << "Car: " << name << " " << model << "\n";
        std::cout << "Speed: " << speed << " km/h\n";
        std::cout << "Gear: " << gear << "\n";
        std::cout << "Engine: " << (isEngineOn ? "On" : "Off") << std::endl;
    }
};

int main()
{
    SportsCar *car = new SportsCar("BMW", "M4");
    std::cout << car << std::endl;
    car->startCar();
    car->shiftGear(4);
    car->accelerate();
    // car->stopCar();
    car->brake();
    car->display();

    delete car;
    return 0;
}