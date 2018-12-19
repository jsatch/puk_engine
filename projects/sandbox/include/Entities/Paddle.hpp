#pragma once

#include "ECS/Entity.hpp"
#include "Components/InputMapComponent.hpp"
#include "PUK/Log.hpp"

namespace Entities
{
	class Paddle : public ECS::Entity
	{
    public:
		Paddle()
		{
            PUK_CLIENT_INFO("Se creo Paddle");
			add_component<ECS::SpriteComponent>({ 36, 12, 2.0f	 ,"assets/paddle1.png" });
			add_component<ECS::TransformComponent>({ 10.0f, 10.0f });
			add_component<Components::InputMapComponent>({});

			// Adding input handlers to the entity
			auto handlers_component = Components::InputHandlerComponent{};

			handlers_component.addHandler(Components::InputControls::LEFT_KEY, [&]() -> void {
				auto& tc = get_component_by_type_id<ECS::TransformComponent>();
				tc.posX -= 0.5;
                PUK_CLIENT_INFO("LEFT: {}", tc.posX);
			});
			handlers_component.addHandler(Components::InputControls::RIGHT_KEY, [&]() -> void {
				auto& tc = get_component_by_type_id<ECS::TransformComponent>();
				tc.posX += 0.5;
                PUK_CLIENT_INFO("RIGHT: {}", tc.posX);
			});
			/*handlers_component.addHandler(Components::InputControls::UP_KEY, [&]() -> void {
                PUK_CLIENT_INFO("UP");
				auto& tc = get_component_by_type_id<ECS::TransformComponent>();
				tc.posY -= 0.1;
			});
			handlers_component.addHandler(Components::InputControls::DOWN_KEY, [&]() -> void {
                PUK_CLIENT_INFO("DOWN");
				auto& tc = get_component_by_type_id<ECS::TransformComponent>();
				tc.posY += 0.1;
			});*/
            add_component<Components::InputHandlerComponent>(std::move(handlers_component));
		}
	};
}
