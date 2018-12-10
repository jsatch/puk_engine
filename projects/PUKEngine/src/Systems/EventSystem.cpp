#include "Systems/EventSystem.hpp"

namespace Systems
{
    void EventSystem::draw(ECS::Entity &entity)
    {
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
                    
                    auto im = entity.get_component_by_type_id<ECS::Components::InputMapComponent>();
                    
                    // Lets put data in InputBitSetComponent
                    
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
    
	void SDLEventSystem::handle_input()
	{
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
