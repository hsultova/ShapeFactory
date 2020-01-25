#pragma once
#include "Shape.h"

namespace ShapeNamespace
{
    class SquareShape : public IShape
    {
    public:
        ~SquareShape();

        void draw();
    };
}


