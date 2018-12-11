#pragma once

#include <bitset>
#include "Systems/EventSystem.hpp"

namespace Systems
{
	enum EventType;
}

namespace Components {
	constexpr int MAX_EVENTS = 3;

    using InputBitSet = std::bitset<MAX_EVENTS>;
    
    struct InputMapComponent : public ECS::Component
    {
    private:
        InputBitSet map;
    public:
        void turn_on(Systems::EventType type)
        {
			map[type].flip();
        }
		void reset()
		{
			map.reset();
		}
    };
}

