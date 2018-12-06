#pragma once

#include <memory>
#include <vector>
#include <stack>
#include "ECS/Entity.hpp"
#include "ECS/System.hpp"
#include "PUK/Log.hpp"

namespace Worlds
{
    using milisecs = unsigned int;
    class World
    {
    private:
        std::vector<std::unique_ptr<ECS::Entity>> entities;
        std::vector<std::shared_ptr<ECS::System>> systems;
    public:
		void register_system(std::shared_ptr<ECS::System> system)
		{
			systems.push_back(system);
		}
		void add_entity(ECS::Entity& entity)
		{
			ECS::Entity* en = new ECS::Entity(std::move(entity));
			entities.push_back(std::unique_ptr<ECS::Entity>(en));
		}
		virtual void update(milisecs delta) {};
		virtual void render() 
		{
			for (auto& sp_system: systems)
			{
				for (auto& up_entity : entities)
				{
					if ((*sp_system).has_match(*up_entity))
					{
						(*sp_system).draw(*up_entity);
					}
				}
			}
		};
    };

    class WorldManager
    {
    private:
        std::stack<std::unique_ptr<World>> worlds_stack;
    public:
        void push(World* world)
        {
			std::unique_ptr<World> uPtr{world};
            worlds_stack.push(std::move(uPtr));
        }
        void pop()
        {
            worlds_stack.pop();
        }
		template <typename T>
        T* top()
        {
			return (T*)worlds_stack.top().get();
        }
    };
}