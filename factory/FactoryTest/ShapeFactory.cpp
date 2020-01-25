#include "pch.h"
#include "ShapeFactory.h"

#include <memory>

#include "ShapeTypes.h"
#include "RectangleShape.h"
#include "SquareShape.h"

namespace ShapeNamespace
{
    ShapeFactory::CallbackMap ShapeFactory::m_shapes;

    void ShapeFactory::RegisterShape(const std::string& _type, CreateCallback _callback)
    {
        m_shapes[_type] = _callback;
    }

    void ShapeFactory::UnregisterShape(const std::string& _type)
    {
        m_shapes.erase(_type);
    }

    std::unique_ptr<IShape> ShapeFactory::CreateShape(const std::string& _type)
    {
        EnumParser<ShapeTypes> parser;
        ShapeTypes type = parser.ParseEnum(_type);

        if (type == ShapeTypes::Rectangle)
            return std::make_unique<RectangleShape>();

        if (type == ShapeTypes::Square)
            return std::make_unique<SquareShape>();

        CallbackMap::iterator it = m_shapes.find(_type);
        if (it != m_shapes.end())
        {
            return (it->second)();
        }
        return nullptr;
    }
}