#include "ECS/System.hpp"
namespace ECS 
{
    void System::register_component(ComponentTypeId type_id)
    {
        requires[type_id] = true;
    }
    
    bool System::has_match(Entity& entity)
    {
        for (std::pair<ComponentTypeId, bool> c : requires)
        {
            if (entity.get_component_by_type_id(c.first))
            {
                return true;
            }
        }
        return false;
    }

}
