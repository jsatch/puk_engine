#pragma once

#include "PUK/Log.hpp"
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
	struct TransformComponent : public ECS::Component
	{
	public:
		std::unique_ptr<Systems::Physics::Vector2D> position;

		TransformComponent() : ECS::Component()
		{}

		TransformComponent(Systems::Physics::Vector2D &&pos) : ECS::Component()
		{
			position = std::make_unique<Systems::Physics::Vector2D>(std::move(pos));
		}

		TransformComponent(const TransformComponent &tc)
		{
			PUK_CORE_INFO("Copy semantics for TransformComponent");
			position = std::make_unique<Systems::Physics::Vector2D>(std::move(*(tc.position)));
		}

		TransformComponent(TransformComponent &&tc)
		{
			position = std::make_unique<Systems::Physics::Vector2D>(std::move(*(tc.position)));
		}
		
		~TransformComponent()
		{}
	};
}

