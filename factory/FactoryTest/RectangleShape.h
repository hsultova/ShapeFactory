#pragma once
#include "Shape.h"

namespace ShapeNamespace
{
    class RectangleShape : public IShape
    {
    public:
        ~RectangleShape();

        void draw();
    };

}

