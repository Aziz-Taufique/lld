#include <iostream>

class TwoDimensionalShape
{
public:
    virtual double area() = 0;
};

class ThreeDimensionalShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDimensionalShape
{
    double side;

public:
    Square(double side) : side(side) {}

    double area() override
    {
        return side * side;
    }
};

class Rectangel : public TwoDimensionalShape
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
};

class Cube : public ThreeDimensionalShape
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
    TwoDimensionalShape *square = new Square(4);
    TwoDimensionalShape *rectangle = new Rectangel(4, 5);

    std::cout << "Area of square : " << square->area() << std::endl;
    std::cout << "Area of rectangle : " << rectangle->area() << std::endl;

    ThreeDimensionalShape *cube = new Cube(3);
    std::cout << "Area of cube : " << cube->area() << std::endl;
    std::cout << "volume of cube : " << cube->volume() << std::endl;
}