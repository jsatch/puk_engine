#include "Systems/EventSystem.hpp"

namespace Systems
{
    void EventSystem::draw(ECS::Entity &entity)
    {
		auto im = entity.get_component_by_type_id<Components::InputMapComponent>();
		(*im).reset();

		(*im).set_map(map_input_controls);
		
		for (auto i = 0; i < (int)Components::InputControls::_COUNT ; i++)
		{
			if ((*im).get_bit(i))
			{
				auto handler_component = entity.get_component_by_type_id<Components::InputHandlerComponent>();
				auto f = (*handler_component).dispatch(i);
				if (f != nullptr) f();
			}
			
		}
    }
    
	void SDLEventSystem::handle_input()
	{
		//map_input_controls.reset();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (global_listeners[on_key_pressed] != nullptr)
				{
					OnKeyPressedEventData* ed = new OnKeyPressedEventData(event.key.keysym.sym);
					global_listeners[on_key_pressed](ed);
                    delete ed;
				}
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						if (map_input_controls[(int)Components::InputControls::UP_KEY] == false)
						{
							map_input_controls[(int)Components::InputControls::UP_KEY] = true;
						}
						break;
					case SDLK_DOWN:
						if (map_input_controls[(int)Components::InputControls::DOWN_KEY] == false)
						{
							map_input_controls[(int)Components::InputControls::DOWN_KEY] = true;
						}
						break;
					case SDLK_LEFT:
						if (map_input_controls[(int)Components::InputControls::LEFT_KEY] == false)
						{
							map_input_controls[(int)Components::InputControls::LEFT_KEY] = true;
						}
						break;
					case SDLK_RIGHT:
						if (map_input_controls[(int)Components::InputControls::RIGHT_KEY] == false)
						{
							map_input_controls[(int)Components::InputControls::RIGHT_KEY] = true;
						}
						break;
					case SDLK_SPACE:
						if (map_input_controls[(int)Components::InputControls::SPACE_KEY] == false)
						{
							map_input_controls[(int)Components::InputControls::SPACE_KEY] = true;
						}
						break;
				}
			break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					if (map_input_controls[(int)Components::InputControls::UP_KEY] == true)
					{
						map_input_controls[(int)Components::InputControls::UP_KEY] = false;
					}
					break;
				case SDLK_DOWN:
					if (map_input_controls[(int)Components::InputControls::DOWN_KEY] == true)
					{
						map_input_controls[(int)Components::InputControls::DOWN_KEY] = false;
					}
					break;
				case SDLK_LEFT:
					if (map_input_controls[(int)Components::InputControls::LEFT_KEY] == true)
					{
						map_input_controls[(int)Components::InputControls::LEFT_KEY] = false;
					}
					break;
				case SDLK_RIGHT:
					if (map_input_controls[(int)Components::InputControls::RIGHT_KEY] == true)
					{
						map_input_controls[(int)Components::InputControls::RIGHT_KEY] = false;
					}
					break;
				case SDLK_SPACE:
					if (map_input_controls[(int)Components::InputControls::SPACE_KEY] == true)
					{
						map_input_controls[(int)Components::InputControls::SPACE_KEY] = false;
					}
					break;
				}
			break;
			case SDL_QUIT:
				if (global_listeners[on_exit] != nullptr)
				{
					global_listeners[on_exit](nullptr);
				}
			break;
			}
		}
	}
}
