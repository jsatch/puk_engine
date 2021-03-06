#pragma once

#include "SDL2/SDL.h"
#include "ECS/System.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Component.hpp"
#include "PUK/Log.hpp"

namespace RenderSystem {
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
        RenderSystem(GameProperties& properties);
        ~RenderSystem();
        void init();
        void draw(ECS::Entity &);
    };
}