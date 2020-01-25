#include "pch.h"
#include "SquareShape.h"

#include <iostream>

namespace ShapeNamespace
{
    SquareShape::~SquareShape()
    {
    }

    void SquareShape::draw()
    {
        std::cout << "Draw Square.\n";
    }
}
