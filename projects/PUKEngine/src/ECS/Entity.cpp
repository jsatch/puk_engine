#include "ECS/Entity.hpp"

namespace ECS
{
    template <typename T>
    void Entity::add_component(T& comp)
    {
        components[get_component_type_id<T>()] = std::make_unique<T>(comp);
    }
    template <typename T>
    std::unique_ptr<T> Entity::get_component_by_type_id()
    {
        return std::move(components[get_component_type_id<T>()]);
    }
    std::unique_ptr<Component>& Entity::get_component_by_type_id(ComponentTypeId id)
    {
        return components[id];
    }
}