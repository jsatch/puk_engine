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
    
    class World
    {
    protected:
        std::vector<std::shared_ptr<ECS::Entity>> entities;
        std::vector<std::shared_ptr<ECS::System>> systems;
		std::shared_ptr<PUK::Application> app;
    public:
        World();
        virtual ~World();

        void set_application(std::shared_ptr<PUK::Application> application);
        std::shared_ptr<PUK::Application> get_application();

        void register_system(const std::shared_ptr<ECS::System> &system);

        void add_entity(const std::shared_ptr<ECS::Entity> &entity);

		virtual void handle_input() = 0;

		virtual void render()
		{
			for (auto& sp_system: systems)
			{
				(*sp_system).start();
				for (auto& up_entity : entities)
				{
					if ((*sp_system).has_match(*up_entity))
					{
						(*sp_system).update(1000, *up_entity); // TODO delta time should be passed instead;
						(*sp_system).draw(*up_entity);
					}
				}
				(*sp_system).end();
			}
		};
    };

    class WorldManager
    {
    private:
        std::stack<std::unique_ptr<World>> worlds_stack;
    public:
        void push(World* world, PUK::Application* app);
        void pop();
		template <typename T>
        T* top()
        {
            return (T*)worlds_stack.top().get();
        }
    };
}
