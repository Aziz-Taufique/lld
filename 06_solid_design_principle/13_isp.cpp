#include <iostream>

// Interface segregation principle.
// Many client specific interface are better than one general purpose interface.
// Client should not be forced to implement methods they don't need.

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape
{
    double side;

public:
    Square(double side) : side(side) {}

    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        throw std::logic_error("Volume not applicable for square.");
    }
};

class Rectangel : public Shape
{
    double length;
    double breadth;

public:
    Rectangel(double length, double breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    double area() override
    {
        return length * breadth;
    }

    double volume() override
    {
        throw std::logic_error("Valume not applicable for rectangle.");
    }
};

class Cube : public Shape
{

    double side;

public:
    Cube(double side) : side(side) {}

    double area() override
    {
        return 6 * side * side;
    }

    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    Shape *square = new Square(4);
    Shape *rectangel = new Rectangel(4, 5);
    Shape *cube = new Cube(5);

    std::cout << "Area of square : " << square->area() << std::endl;
    std::cout << "Area of rectangle : " << rectangel->area() << std::endl;
    std::cout << "Area of cube : " << cube->area() << std::endl;
    std::cout << "volume of cube : " << cube->volume() << std::endl;

    try
    {

        std::cout << "volume of square : " << square->volume() << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
    return 0;
}