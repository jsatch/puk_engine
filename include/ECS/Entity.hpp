#pragma once

#include <map>
#include <memory>
#include <iostream>
#include "Component.hpp"

namespace ECS
{
    struct Entity
    {
    private:
        std::map<ComponentTypeId, std::unique_ptr<Component> > components;
    public:
        template <typename T>
        void add_component(std::unique_ptr<T>& comp);
        template <typename T>
        std::unique_ptr<T> get_component_by_type_id();
        std::unique_ptr<Component>& get_component_by_type_id(ComponentTypeId id);
    };
}