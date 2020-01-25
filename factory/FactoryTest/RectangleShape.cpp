#include "pch.h"
#include "RectangleShape.h"

#include <iostream>

namespace ShapeNamespace
{
    RectangleShape::~RectangleShape()
    {
    }

    void RectangleShape::draw()
    {
        std::cout << "Draw Rectangle.\n";
    }
}
