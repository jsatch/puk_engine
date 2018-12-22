#pragma once

#ifdef PUK_WIN
#include "SDL.h"
#endif // PUK_WIN

#ifdef PUK_OSX
#include "SDL2/SDL.h"
#endif // PUK_OSX

#include <array>
#include <functional>
#include "ECS/System.hpp"
#include "Components/InputMapComponent.hpp"
#include "PUK/Log.hpp"

namespace Components
{
	struct InputMapComponent;
}

namespace Systems
{
	enum EventType { on_click, on_key_pressed, on_exit};

    
    using KeyCode = uint32_t;
    
	struct EventData
	{};
    
    struct OnKeyPressedEventData : public EventData
    {
    private:
        KeyCode data;
    public:
        OnKeyPressedEventData(KeyCode data)
        {
            this->data = data;
        }
        
        KeyCode get_key_code()
        {
            return data;
        }
    };

	constexpr int MAX_EVENTS = 3;
	constexpr int MAX_INPUT_CONTROLS = (int)Components::InputControls::_COUNT;

    class EventSystem : public ECS::System
	{
	protected:
		std::array<std::function<void(EventData*)>, MAX_EVENTS > global_listeners;
		std::bitset<MAX_INPUT_CONTROLS> map_input_controls;
	public:
        EventSystem(){}
        virtual ~EventSystem(){}
		void add_listener(EventType type, std::function<void(EventData*)>&& f)
		{
			global_listeners[type] = f;
		}
        virtual void draw(ECS::Entity &) override;
		virtual void update(ECS::milisecs dt, ECS::Entity &entity) override;
		virtual void handle_input() = 0;
		virtual void start() = 0;
		virtual void end() = 0;
	};
    
	class SDLEventSystem : public EventSystem
    {
    public:
        SDLEventSystem(){}
        ~SDLEventSystem(){}
		virtual void handle_input() override;
		virtual void start() override;
		virtual void end() override;
	};
}
