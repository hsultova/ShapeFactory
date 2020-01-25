#pragma once

namespace ShapeNamespace
{
    class IShape
    {
    public:
        virtual ~IShape() {}
        virtual void draw() = 0;
    };
}
