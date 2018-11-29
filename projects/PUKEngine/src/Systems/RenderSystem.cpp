#include "Systems/RenderSystem.hpp"

namespace RenderSystem
{
    RenderSystem::RenderSystem(GameProperties& properties)
    {        
        this->properties = properties;
    }
    RenderSystem::~RenderSystem()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
    }
    void RenderSystem::init()
    {
        PUK_INIT();
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {
            PUK_CORE_ERROR("Error SDL_Init: {}", SDL_GetError());
        }
        win = SDL_CreateWindow(
            properties.game_title, 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            properties.width, 
            properties.height, 
            properties.window_mode);
        
        if (win == nullptr)
        {
            PUK_CORE_ERROR("Error SDL_CreateWindow: {}", SDL_GetError());
            SDL_Quit();
        }

        renderer = SDL_CreateRenderer(
            win, -1, 
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (renderer == nullptr)
        {
            PUK_CORE_ERROR("Error SDL_CreateRenderer: {}", SDL_GetError());
            SDL_DestroyWindow(win);
            SDL_Quit();
        }
    }
    void RenderSystem::draw(ECS::Entity& entity)
    {
        
    }
}