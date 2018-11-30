#pragma once

#include <bitset>
#include <utility>
#include "Component.hpp"
#include "Entity.hpp"

namespace ECS
{
    class System
    {
    private:
        std::bitset<MAX_COMPONENTS> requires;
    public:
		template<typename T>
		void register_component()
		{
			requires[get_component_type_id<T>()] = true;
		}
        bool has_match(Entity& entity);
    };

    class RenderSystem : public System
    {   
    public:
		virtual void init() {};
		virtual void draw() {};
    };
}
