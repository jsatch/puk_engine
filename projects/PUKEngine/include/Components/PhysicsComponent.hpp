#pragma once

#include <memory>
#include "ECS/Component.hpp"
#include "Systems/PhysicsSystem.hpp"

namespace Systems	
{
	namespace Physics
	{
		struct Vector2D;
	}	
}

namespace Components
{
	struct PhysicsComponent : public ECS::Component
	{
		bool stationary;
		std::unique_ptr<Systems::Physics::Vector2D> movement;

		PhysicsComponent() : ECS::Component()
		{
			stationary = true;
		}

		PhysicsComponent(const PhysicsComponent &pc) : ECS::Component()
		{
			stationary = pc.stationary;
			movement = std::make_unique<Systems::Physics::Vector2D>(std::move(*pc.movement));
		}

		PhysicsComponent(Systems::Physics::Vector2D &&v2d, bool stationary) : ECS::Component()
		{
			this->stationary = stationary;
			movement = std::make_unique<Systems::Physics::Vector2D>(std::move(v2d));
		}
	};
}