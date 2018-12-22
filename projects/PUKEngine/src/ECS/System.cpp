#include "ECS/System.hpp"
namespace ECS 
{
    bool System::has_match(Entity& entity)
    {
		bool found = false;
		for (int i=0 ; i < MAX_COMPONENTS; i++)
		{
			if (requires[i] == true)
			{
				found = entity.has_component(i);
				if (found == false) break;
			}
		}
		return found;
    }

}
