#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
class Car
{
protected:
    std::string model;
    std::string brand;
    bool isEngineOn;
    int currentSpeed;
    bool window;
    bool wiper;
    std::vector<bool> doors;

public:
    Car(std::string model, std::string brand, int numberOfDoors = 4)
    {
        this->model = model;
        this->brand = brand;
        isEngineOn = false;
        currentSpeed = 0;
        window = true;
        wiper = true;
        doors = std::vector<bool>(numberOfDoors, true);
    }

    void startEngine()
    {
        isEngineOn = true;
        std::cout << "Engin started..." << std::endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        std::cout << "Engine stopped..." << std::endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            std::cout << "Cannot accelerate! Engine is off" << std::endl;
            return;
        }
        currentSpeed += 20;
    }

    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        std::cout << "Braking! Current speed is " << currentSpeed << std::endl;
    }

    void openCloseWindow()
    {
        if (window)
            window = false;
        else
            window = true;
    }

    void closeOpenDoors(int doorNumber)
    {
        if (doors[doorNumber])
        {
            doors[doorNumber] = false;
            std::cout << "Door " << doorNumber << " is " << (doors[doorNumber] ? "closed" : "open") << std::endl;
        }
    }

    void closeAllDoors()
    {
        for (auto it : doors)
        {
            it = true;
        }
    }

    void controllWiper()
    {
        if (wiper)
        {
            wiper = false;
        }
        else
        {
            wiper = true;
        }
        std::cout << "Wiper is " << (wiper ? "closed" : "open") << std::endl;
    }

    void opernWiperForOneMin()
    {
        wiper = false; // on
        std::cout << "Wiper turned ON. \n";

        std::thread([this]()
                    {
                        std::this_thread::sleep_for(std::chrono::seconds(5));
                        wiper = true; // closed.
                        std::cout<<"Wiper is turned OF. \n"; })
            .detach();
    }

    void display()
    {
        std::cout << "Car: " << brand << " " << model << "\n";
        std::cout << "Speed: " << currentSpeed << " km/h\n";
        std::cout << "Engine: " << (isEngineOn ? "On" : "Off") << std::endl;
        std::cout << "Window is " << (window ? "closed" : "open") << std::endl;
        for (int i = 0; i < doors.size(); i++)
        {
            std::cout << "door " << i + 1 << " is" << (doors[i] ? "closed" : "open") << std::endl;
        }
    }

    virtual ~Car() {};
};

class ManualCar : public Car
{
private:
    int currentGear;

public:
    ManualCar(std::string model, std::string brand) : Car(model, brand)
    {
        currentGear = 0;
    }

    void changeGear(int gear)
    {
        if (!isEngineOn)
        {
            std::cout << "cannot shift gear! Engine is off" << std::endl;
            return;
        }
        currentGear = gear;
        std::cout << "Gear changet to " << currentGear << std::endl;
    }
    void displayGear()
    {
        std::cout << "current gear is " << currentGear << std::endl;
    }
};

// Electric car.
class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(std::string model, std::string brand) : Car(model, brand)
    {
        batteryLevel = 0;
    }

    void chargeBattery()
    {
        batteryLevel = 100;
    }

    void displayBatterLevel()
    {
        std::cout << "battery percentage is " << batteryLevel << "%" << std::endl;
    }
};

int main()
{

    ElectricCar *electricCar = new ElectricCar("Tesla", "h2");
    // electricCar->startEngine();
    // electricCar->accelerate();
    // electricCar->accelerate();
    // electricCar->chargeBattery();
    // electricCar->brake();
    // electricCar->displayBatterLevel();
    electricCar->display();

    std::cout << "******************************************" << std::endl;

    ManualCar *manumalCar = new ManualCar("BMW", "32");

    // manumalCar->startEngine();
    // manumalCar->openCloseWindow();
    // manumalCar->changeGear(3);
    // manumalCar->accelerate();
    // manumalCar->displayGear();
    // manumalCar->closeOpenDoors(2);
    // manumalCar->closeOpenDoors(3);
    // manumalCar->closeAllDoors();
    // manumalCar->controllWiper();
    // manumalCar->controllWiper();
    // manumalCar->display();
    manumalCar->opernWiperForOneMin();
    return 0;
}