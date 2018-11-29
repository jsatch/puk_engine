#include "ECS/Entity.hpp"

namespace ECS
{
    std::unique_ptr<Component>& Entity::get_component_by_type_id(ComponentTypeId id)
    {
        return components[id];
    }
}