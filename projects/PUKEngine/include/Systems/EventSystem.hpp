#pragma once

#include <array>
#include <functional>

namespace Systems
{
	enum EventType { on_click, on_key_pressed};
	struct EventData
	{

	};
	class EventSystem
	{
		std::array<std::function<void(EventData)>, 2 > listeners;

	public:
		void add_listener(EventType type, std::function<void(EventData)> f)
		{
			listeners[type] = f;
		}
	};
}