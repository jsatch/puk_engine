#include "Systems/PhysicsSystem.hpp"

namespace Systems
{
	namespace Physics
	{
		// Vector2D
		Vector2D::Vector2D()
		{}

		Vector2D::Vector2D(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2D::Vector2D(Vector2D &&v)
		{
			this->x = v.x;
			this->y = v.y;
		}

		inline Vector2D& Vector2D::operator= (const Vector2D &v)
		{
			x = v.x; y = v.y;
			return *this;
		}
		inline Vector2D& Vector2D::operator+ (const Vector2D &v)
		{
			x = x + v.x;
			y = y + v.y;
			return *this;
		}
		inline Vector2D& Vector2D::operator- (const Vector2D &v)
		{
			x = x - v.x;
			y = y - v.y;
			return *this;
		}
		inline Vector2D& Vector2D::operator* (const float f)
		{
			x = x * f;
			y = y * f;
			return *this;
		}

		// PhysicsSystem

		PhysicsSystem::PhysicsSystem()
		{
			//this system allows default initialization of components
			register_component<Components::PhysicsComponent>();
			register_component<Components::TransformComponent>();
		}

		PhysicsSystem::~PhysicsSystem()
		{}

		void PhysicsSystem::draw(ECS::Entity &)
		{}

		void PhysicsSystem::update(ECS::milisecs dt, ECS::Entity &entity)
		{
			auto&& pc = entity.get_component_by_type_id<Components::PhysicsComponent>();
			auto&& tc = entity.get_component_by_type_id<Components::TransformComponent>();

			if (pc.stationary == false)
			{
				*(tc.position) = *(tc.position) + *(pc.movement);
			}
		}
		void PhysicsSystem::start()
		{}
		void PhysicsSystem::end()
		{}
	}
}