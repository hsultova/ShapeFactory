#pragma once

#include <string>
#include <map>
#include <memory>

namespace ShapeNamespace
{
    class IShape;
    class ShapeFactory
    {        
    public:
        typedef std::unique_ptr<IShape> (*CreateCallback) ();

        static void RegisterShape(const std::string& _type, CreateCallback _callback);
        static void UnregisterShape(const std::string& _type);
        static std::unique_ptr<IShape> CreateShape(const std::string& _type);

    private:
        typedef std::map<std::string, CreateCallback> CallbackMap;
        static CallbackMap m_shapes;
    };
}

