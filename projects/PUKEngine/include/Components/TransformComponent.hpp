#pragma once

#include "ECS/Component.hpp"
#include "Systems/PhysicsSystem.hpp"

namespace Components
{
	struct TransformComponent : public ECS::Component
	{
	private:
	public:
		float posX, posY;
		Systems::Physics::Vector2D acceleration;
		TransformComponent(float x, float y) : ECS::Component()
		{
			posX = x;
			posY = y;
		}
		TransformComponent(float x, float y, const Systems::Physics::Vector2D &acceleration) : ECS::Component()
		{
			posX = x;
			posY = y;
			this->acceleration = acceleration;
		}
		~TransformComponent()
		{}
	};
}

