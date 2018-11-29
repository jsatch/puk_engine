#pragma once

#include <iostream>
#include <memory>
#include <map>

#define MAX_COMPONENTS 100

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

    struct TransformComponent : public Component
    {
    private:
    public:
        float posX, posY;
        TransformComponent(float x, float y);
        ~TransformComponent();
    };

    struct SpriteComponent : public Component
    {
    private:
    public:
        int w, h;
        SpriteComponent(int w, int h);
        ~SpriteComponent();
    };
}
