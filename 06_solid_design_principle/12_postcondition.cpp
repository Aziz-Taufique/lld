#include <iostream>

class Car
{
protected:
    int speed;

public:
    Car()
    {
        speed = 0;
    }

    void accelerate()
    {
        speed += 20;
        std::cout << "Accelerating" << std::endl;
    }

    virtual void brake()
    {
        speed -= 20;
        std::cout << "Applying brake" << std::endl;
    }
};

class ElectricCar : public Car
{
    int charge;

public:
    ElectricCar()
    {
        charge = 0;
    }

    // postcondition : speed must reduce after brake;
    // postcondition : charge must increase after brake;
    void brake() override
    {
        speed -= 10;
        charge += 10;
        std::cout << "Applying brake" << std::endl;
    }

    void display()
    {
        std::cout << "speed is " << speed << std::endl;
        std::cout << "Charge is " << charge << std::endl;
    }
};

int main()
{
    Car *car = new Car();
    car->accelerate();
    car->brake();

    ElectricCar *electricCar = new ElectricCar();
    electricCar->accelerate();
    electricCar->brake();
    electricCar->display();
}
