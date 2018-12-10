#include "Systems/EventSystem.hpp"

namespace Systems
{
	void SDLEventSystem::handle_input()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (listeners[on_key_pressed] != nullptr)
				{
					OnKeyPressedEventData* ed = new OnKeyPressedEventData(event.key.keysym.sym);
					listeners[on_key_pressed](ed);
                    delete ed;
				}
			break;
			case SDL_QUIT:
				if (listeners[on_exit] != nullptr)
				{
					listeners[on_exit](nullptr);
				}
			break;
			}
		}
	}
}
