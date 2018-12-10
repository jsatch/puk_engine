#pragma once

#ifdef PUK_WIN
#include "SDL.h"
#endif // PUK_WIN

#ifdef PUK_OSX
#include "SDL2/SDL.h"
#endif // PUK_OSX

#include <array>
#include <functional>

namespace Systems
{
	enum EventType { on_click, on_key_pressed, on_exit};

    
    using KeyCode = uint32_t;
    
	struct EventData
	{};
    
    struct OnClickEventData : public EventData
    {
    private:
        KeyCode data;
    public:
        OnClickEventData(KeyCode data)
        {
            this->data = data;
        }
        
        KeyCode get_key_code()
        {
            return data;
        }
    };

	constexpr int MAX_EVENTS = 3;

	// TODO: It should inherit from ECS::System
	class EventSystem
	{
	protected:
		std::array<std::function<void(EventData*)>, MAX_EVENTS > listeners;

	public:
        EventSystem(){}
        virtual ~EventSystem(){}
		void add_listener(EventType type, std::function<void(EventData*)>&& f)
		{
			listeners[type] = f;
		}
		virtual void handle_input() = 0;
	};
    
	class SDLEventSystem : public EventSystem
    {
    public:
        SDLEventSystem(){}
        ~SDLEventSystem(){}
		virtual void handle_input() override;
	};
}
