#pragma once

#ifdef PUK_WIN
#include "SDL.h"
#endif // PUK_WIN

#ifdef PUK_OSX
#include "SDL2/SDL.h"
#endif // PUK_OSX

#include <iostream>
#include <memory>
#include <map>

namespace ECS
{
    using ComponentTypeId = size_t;
    using ComponentId = size_t;

    inline ComponentTypeId get_unique_component_id()
    {
        static ComponentTypeId last_id{0};
        return last_id++;
    }

    template<typename T>
    inline ComponentTypeId get_component_type_id()
    {
        static ComponentTypeId type_id{get_unique_component_id()};
        return type_id;
    }

    struct Component
    {
    protected:
        ComponentId id;
    public:
        Component();
        ~Component();
        ComponentId get_id();
    };
}
