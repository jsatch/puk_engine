#pragma once

#include <memory>
#include <map>
#include <utility>
#include "Component.hpp"
#include "Entity.hpp"

namespace ECS
{
    class System
    {
    private:
        std::map<ComponentTypeId, bool> requires;
    public:
        void register_component(ComponentTypeId type_id);
        bool has_match(Entity& entity);
    };

    class RenderSystem : public System
    {   
    public:
        virtual void init() = 0;
        virtual void draw() = 0;
    };
}
