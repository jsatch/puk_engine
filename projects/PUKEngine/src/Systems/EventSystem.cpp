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
		map_input_controls.reset();

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
						map_input_controls[(int)Components::InputControls::UP_KEY].flip();
						break;
					case SDLK_DOWN:
						map_input_controls[(int)Components::InputControls::DOWN_KEY].flip();
						break;
					case SDLK_LEFT:
						map_input_controls[(int)Components::InputControls::LEFT_KEY].flip();
						break;
					case SDLK_RIGHT:
						map_input_controls[(int)Components::InputControls::RIGHT_KEY].flip();
						break;
					case SDLK_SPACE:
						map_input_controls[(int)Components::InputControls::SPACE_KEY].flip();
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
