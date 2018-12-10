#pragma once

#include <memory>
#include "Worlds/WorldManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/EventSystem.hpp"
#include "PUK/Log.hpp"

namespace Worlds
{
	struct MenuWorld : public World
	{
	private:
		std::unique_ptr<Systems::EventSystem> event_system;
	public:
		MenuWorld(std::unique_ptr<Systems::EventSystem>&& es)
		{
			event_system = std::move(es); // forcing a move semantic
			
			(*event_system).add_listener(Systems::on_key_pressed, [&](Systems::EventData* data) -> void {
				PUK_CLIENT_INFO("on_key_presed");
                Systems::OnClickEventData* onclick_data = (Systems::OnClickEventData*)data;
                Systems::KeyCode code = onclick_data->get_key_code();
				if (code == SDLK_ESCAPE)
				{
					PUK_CLIENT_INFO("Quiting app...");
					(*get_application()).stop();
				}
				
			});
			
			(*event_system).add_listener(Systems::on_exit, [&](Systems::EventData* data) -> void {
				PUK_CLIENT_INFO("Quiting app...");
				(*get_application()).stop();
			});
			
			// Creating the RenderSystem
			ECS::GameProperties gp{ "Sandbox", SDL_WINDOW_SHOWN, 800, 600};
			std::shared_ptr<ECS::RenderSystem> render_system = std::make_shared<ECS::RenderSystem>(gp);

			// Creating entities and adding components
			ECS::Entity scott_entity{};
			scott_entity.add_component<ECS::SpriteComponent>({ 309 , 60,"assets/scott_standing.png" });
			scott_entity.add_component<ECS::TransformComponent>({ 10.0f, 30.0f });

			// Registering components for this system
			(*render_system).register_component<ECS::SpriteComponent>();
			(*render_system).register_component<ECS::TransformComponent>();

			// Initializing system
			(*render_system).init();

			// Loading sprite
			(*render_system).loading_sprite(scott_entity);

			// Registering the systems and the entities to the world
			register_system(render_system);
			add_entity(scott_entity);
			
			PUK_CLIENT_INFO("Se creo MenuWorld");
		}
		~MenuWorld()
		{}
		virtual void update(milisecs delta) override
		{}

		virtual void handle_input() override
		{
			(*event_system).handle_input();
		}
	};
}
