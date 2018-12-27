#pragma once

#include "PUK/Log.hpp"
#include "ECS/Entity.hpp"
#include "Systems/PhysicsSystem.hpp"

namespace Entities
{
	class Ball : public ECS::Entity
	{
	public:
		Ball(float startx, float starty)
		{
			PUK_CLIENT_INFO("Se creo Ball"); 
			add_component<Components::TransformComponent>(
				Components::TransformComponent{ Systems::Physics::Vector2D{startx, starty} });
			add_component<Components::PhysicsComponent>(
				Components::PhysicsComponent{ 
					Systems::Physics::Vector2D{0.0f, 2.0f}, false });
			add_component<Components::SpriteComponent>(
				Components::SpriteComponent{5, 5, 2.0f, "assets/ball.png"});

			auto&& pc = get_component_by_type_id<Components::PhysicsComponent>();
			auto&& tc = get_component_by_type_id<Components::TransformComponent>();
		}
	};

}