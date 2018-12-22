#pragma once

#include "ECS/System.hpp"

namespace Systems
{
	namespace Physics
	{
		struct Vector2D
		{
			float x, y;
			inline Vector2D& operator= (const Vector2D &v)
			{
				x = v.x; y = v.y;
				return *this;
			}
			inline Vector2D& operator+ (const Vector2D &v)
			{
				x = x + v.x;
				y = y + v.y;
				return *this;
			}
			inline Vector2D& operator- (const Vector2D &v)
			{
				x = x - v.x;
				y = y - v.y;
				return *this;
			}
			inline Vector2D& operator8 (const float f)
			{
				x = x*f;
				y = y*f;
				return *this;
			}
		};
		class PhysicsSystem : ECS::System
		{
		private:
		public:
		};
	}
	
}
