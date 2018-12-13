#pragma once

#include <bitset>
#include <functional>
#include "Systems/EventSystem.hpp"

namespace Systems
{
	enum EventType;
}

namespace Components {

	enum class InputControls
	{
		LEFT_KEY, RIGHT_KEY, UP_KEY, DOWN_KEY, 
		SPACE_KEY,
		_COUNT
	};

	constexpr int MAX_INPUT_CONTROLS = (int)InputControls::_COUNT;

    using InputBitSet = std::bitset<MAX_INPUT_CONTROLS>;
	using EventFunction = std::function<void()>;
	using InputHandlerSet = std::array<EventFunction, MAX_INPUT_CONTROLS>;
    
    struct InputMapComponent : public ECS::Component
    {
    private:
        InputBitSet map;
    public:
		void set_map(InputBitSet &map_controls)
		{
			map |= map_controls;
		}
		InputBitSet& get_map()
		{
			return map;
		}
		void reset()
		{
			map.reset();
		}
		bool get_bit(int pos)
		{
			return map[pos];
		}
    };

	struct InputHandlerComponent : ECS::Component
	{
	private:
		InputHandlerSet handlers;
	public:
		void addHandler(InputControls &&type, EventFunction&& f)
		{
			handlers[(int)type] = f;
		}
		EventFunction& dispatch(InputControls &&type)
		{
			return handlers[(int)type];
		}

		EventFunction& dispatch(int pos)
		{
			return handlers[pos];
		}
	};
}

