#pragma once

#include <memory>
#include "Worlds/WorldManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "PUK/Log.hpp"

namespace Worlds
{
	struct MenuWorld : public World
	{
	private:
		std::shared_ptr<ECS::RenderSystem> render_system;
		std::shared_ptr<ECS::Entity> scott_entity;
	public:
		MenuWorld()
		{

			ECS::GameProperties gp{ "Sandbox", SDL_WINDOW_SHOWN, 800, 600};
			render_system = std::make_shared<ECS::RenderSystem>(gp);
			scott_entity = std::make_shared<ECS::Entity>();
			(*scott_entity).add_component<ECS::SpriteComponent>({ 309 , 60,"assets/scott_standing.png" });
			(*scott_entity).add_component<ECS::TransformComponent>({ 10.0f, 30.0f });

			(*render_system).register_component<ECS::SpriteComponent>();
			(*render_system).register_component<ECS::TransformComponent>();

			(*render_system).init();

			(*render_system).init_sprite(*scott_entity);
			
			PUK_CLIENT_INFO("Se creo MenuWorld");
		}
		~MenuWorld()
		{}
		virtual void update(milisecs delta) override
		{}
		virtual void render() override
		{
			if ((*render_system).has_match(*scott_entity))
			{
				(*render_system).draw(*scott_entity);
			}
		}
	};
}