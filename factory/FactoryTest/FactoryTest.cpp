// FactoryTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Simple test of the factory method pattern hybrid of defined types and possibility to register/unregister other types.

#include "pch.h"
#include <iostream>

#include "ShapeFactory.h"
#include "Shape.h"

using namespace ShapeNamespace;

class CircleShape : public IShape
{
public:
    void draw() { std::cout << "Draw Circle.\n"; }
    static std::unique_ptr<IShape> Create() { return std::make_unique<CircleShape>(); }
};

int main()
{
    ShapeFactory::RegisterShape("Circle", CircleShape::Create);

    std::unique_ptr<IShape> square = ShapeFactory::CreateShape("Square");
    if(square)
        square->draw();

    std::unique_ptr<IShape> circle = ShapeFactory::CreateShape("Circle");
    if(circle)
        circle->draw();

    ShapeFactory::UnregisterShape("Circle");
    std::unique_ptr<IShape> circle2 = ShapeFactory::CreateShape("Circle");
    if (circle2)
        circle2->draw();

    std::unique_ptr<IShape> unknown = ShapeFactory::CreateShape("Unknown");
    if (unknown)
        unknown->draw();
    else
        std::cout << "An object is not created. Try to register it.";
}