#pragma once

#ifdef PUK_WIN
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif // PUK_WIN


#include "ECS/System.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Component.hpp"
#include "PUK/Log.hpp"
#include "PUK/TextureManager.hpp" 

namespace ECS {
    using Window_SDL_Mode = Uint32;
    struct GameProperties
    {
        const char*  game_title;
        Window_SDL_Mode window_mode;
        int width, height;
    };
    class RenderSystem : public ECS::System
    {
    private:
        GameProperties properties;
        SDL_Window* win;
        SDL_Renderer* renderer;
    public:
        RenderSystem(GameProperties properties);
        ~RenderSystem();
        void init();
		void loading_sprite(ECS::Entity &);
        void draw(ECS::Entity &) override;
    };
}
