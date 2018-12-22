#pragma once

#include <bitset>
#include <utility>
#include "Component.hpp"
#include "Entity.hpp"

namespace ECS
{
	using milisecs = unsigned int;

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
		virtual void update(milisecs dt, ECS::Entity &entity) = 0;
		virtual void draw(ECS::Entity &) = 0;
		virtual void start() = 0; // Start cycle
		virtual void end() = 0; // End cycle
    };
}
