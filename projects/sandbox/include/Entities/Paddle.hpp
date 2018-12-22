#pragma once

#include "ECS/Entity.hpp"
#include "Components/InputMapComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "PUK/Log.hpp"

namespace Entities
{
	class Paddle : public ECS::Entity
	{
    public:
		Paddle(float startX, float startY, bool player1)
		{
            PUK_CLIENT_INFO("Se creo Paddle");
			if (player1)
			{
				add_component<Components::SpriteComponent>({ 36, 12, 2.0f	 ,"assets/paddle1.png" });
			}
			else
			{
				add_component<Components::SpriteComponent>({ 36, 12, 2.0f	 ,"assets/paddle2.png" });
			}
			add_component<Components::TransformComponent>({ startX, startY });
			add_component<Components::InputMapComponent>({});

			// Adding input handlers to the entity
			auto handlers_component = Components::InputHandlerComponent{};

			if (player1)
			{
				handlers_component.addHandler(Components::InputControls::LEFT_KEY, [&]() -> void {
					auto& tc = get_component_by_type_id<Components::TransformComponent>();
					tc.posX -= 10;
				});
				handlers_component.addHandler(Components::InputControls::RIGHT_KEY, [&]() -> void {
					auto& tc = get_component_by_type_id<Components::TransformComponent>();
					tc.posX += 10;
				});	
			}else
			{
				handlers_component.addHandler(Components::InputControls::A_KEY, [&]() -> void {
					auto& tc = get_component_by_type_id<Components::TransformComponent>();
					tc.posX -= 10;
				});
				handlers_component.addHandler(Components::InputControls::D_KEY, [&]() -> void {
					auto& tc = get_component_by_type_id<Components::TransformComponent>();
					tc.posX += 10;
				});
			}
			add_component<Components::InputHandlerComponent>(std::move(handlers_component));
			
		}
	};
}
