#pragma once

#include <memory>
#include "Worlds/WorldManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/EventSystem.hpp"
#include "Components/InputMapComponent.hpp"
#include "PUK/Log.hpp"

namespace Worlds
{
	struct MenuWorld : public World
	{
	private:
		std::shared_ptr<Systems::EventSystem> event_system;
		std::shared_ptr<ECS::Entity> scott_entity;
	public:
		MenuWorld(std::unique_ptr<Systems::EventSystem>&& es)
		{
			event_system = std::move(es); // forcing a move semantic
			
			(*event_system).add_listener(Systems::on_key_pressed, [&](Systems::EventData* data) -> void {
				PUK_CLIENT_INFO("on_key_presed");
                auto onclick_data = (Systems::OnKeyPressedEventData*)data;
                auto code = onclick_data->get_key_code();
                
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
			scott_entity = std::make_shared<ECS::Entity>();
			(*scott_entity).add_component<ECS::SpriteComponent>({ 309 , 60,"assets/scott_standing.png" });
			(*scott_entity).add_component<ECS::TransformComponent>({ 10.0f, 30.0f });
			(*scott_entity).add_component<Components::InputMapComponent>({});

			// Adding input handlers to the entity
			Components::InputHandlerComponent handlers_component{};
			handlers_component.addHandler(Components::InputControls::LEFT_KEY, [&]() -> void {
				auto tc = (*scott_entity).get_component_by_type_id<ECS::TransformComponent>();
				(*tc).posX -= 10;
			});
			handlers_component.addHandler(Components::InputControls::RIGHT_KEY, [&]() -> void {
				auto tc = (*scott_entity).get_component_by_type_id<ECS::TransformComponent>();
				(*tc).posX += 10;
			});
			handlers_component.addHandler(Components::InputControls::UP_KEY, [&]() -> void {
				auto tc = (*scott_entity).get_component_by_type_id<ECS::TransformComponent>();
				(*tc).posY -= 10;
			});
			handlers_component.addHandler(Components::InputControls::DOWN_KEY, [&]() -> void {
				auto tc = (*scott_entity).get_component_by_type_id<ECS::TransformComponent>();
				(*tc).posY += 10;
			});
			(*scott_entity).add_component<Components::InputHandlerComponent>(std::move(handlers_component));

			// Registering components for the render system
			(*render_system).register_component<ECS::SpriteComponent>();
			(*render_system).register_component<ECS::TransformComponent>();

			// Registering components for the event system
			(*event_system).register_component<Components::InputMapComponent>();

			// Initializing system
			(*render_system).init();

			// Loading sprite
			(*render_system).loading_sprite(*scott_entity);

			

			// Registering the systems and the entities to the world
			register_system(render_system);
			register_system(event_system);

			// Adding entity to the world
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
