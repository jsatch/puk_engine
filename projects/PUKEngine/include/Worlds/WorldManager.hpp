#pragma once

#include <memory>
#include <vector>
#include <stack>
#include "ECS/Entity.hpp"
#include "ECS/System.hpp"
#include "Systems/EventSystem.hpp"
#include "PUK/Application.hpp"
#include "PUK/Log.hpp"

namespace PUK {
	class Application;
}

namespace Worlds
{
    using milisecs = unsigned int;
    class World
    {
    protected:
        std::vector<std::shared_ptr<ECS::Entity>> entities;
        std::vector<std::shared_ptr<ECS::System>> systems;
		std::shared_ptr<PUK::Application> app;
    public:
		World()
		{}
		virtual ~World()
		{}

		void set_application(std::shared_ptr<PUK::Application> application)
		{
			app = std::move(application);
		}
		std::shared_ptr<PUK::Application> get_application()
		{
			return app;
		}

		void register_system(std::shared_ptr<ECS::System> system)
		{
			systems.push_back(system);
		}

		void add_entity(std::shared_ptr<ECS::Entity> &entity)
		{
			entities.push_back(entity);
		}

		/*void add_entity(ECS::Entity& entity)
		{
			ECS::Entity* en = new ECS::Entity(std::move(entity));
			entities.push_back(std::unique_ptr<ECS::Entity>(en));
		}*/

		virtual void handle_input() = 0;
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
        void push(World* world, PUK::Application* app)
        {
			
			std::unique_ptr<World> uPtr{world};
			std::shared_ptr<PUK::Application> sPtr{ app };
			(*uPtr).set_application(sPtr);
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