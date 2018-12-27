#pragma once

#include "ECS/System.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/TransformComponent.hpp"

namespace Components
{
	struct PhysicsComponent;
}

namespace Systems
{
	namespace Physics
	{
		struct Vector2D
		{
			float x, y;
			Vector2D();
			Vector2D(float x, float y);
			Vector2D(Vector2D &&v);
			Vector2D& operator= (const Vector2D &v);
			Vector2D& operator+ (const Vector2D &v);
			Vector2D& operator- (const Vector2D &v);
			Vector2D& operator* (const float f);
		};

		class PhysicsSystem : public ECS::System
		{
		public:
			PhysicsSystem();
			~PhysicsSystem();
			virtual void draw(ECS::Entity &) override;
			virtual void update(ECS::milisecs dt, ECS::Entity &entity) override;
			virtual void start() override;
			virtual void end() override;
		};
	}
	
}
