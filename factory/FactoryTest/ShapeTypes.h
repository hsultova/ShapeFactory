#pragma once

#include <map>
#include <string>

namespace ShapeNamespace
{

    //All build in shape types
    enum ShapeTypes
    {
        None,
        Rectangle,
        Square
    };

    template <typename T>
    class EnumParser
    {
        std::map <std::string, T> enumMap;
    public:
        EnumParser() {};

        T ParseEnum(const std::string &value)
        {
            typename  std::map < std::string, T>::const_iterator iValue = enumMap.find(value);
            if (iValue != enumMap.end())
                return iValue->second;

            return None;
        }
    };

    EnumParser<ShapeTypes>::EnumParser()
    {
        enumMap["Rectangle"] = ShapeTypes::Rectangle;
        enumMap["Square"] = ShapeTypes::Square;
    }
}