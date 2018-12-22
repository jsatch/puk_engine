#include "Systems/RenderSystem.hpp"

namespace ECS
{
    RenderSystem::RenderSystem(GameProperties &properties)
    {        
        this->properties = std::make_unique<GameProperties>(std::move(properties));
    }

    RenderSystem::~RenderSystem()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    void RenderSystem::init()
    {
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {
            PUK_CORE_ERROR("Error SDL_Init: {}", SDL_GetError());
        }
        win = SDL_CreateWindow(
            (*properties).game_title,
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            (*properties).width,
            (*properties).height,
            (*properties).window_mode);
        
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

	void RenderSystem::update(milisecs dt, ECS::Entity &entity) {}

	void RenderSystem::loading_sprite(ECS::Entity & entity)
	{
		assert(entity.has_component<ECS::SpriteComponent>());

		auto& sc = entity.get_component_by_type_id<ECS::SpriteComponent>();
		SDL_Texture* tex = Util::TextureManager::load_texture(sc.get_filename(), renderer);
		sc.set_texture(tex);
	}
    void RenderSystem::draw(ECS::Entity& entity)
    {
		auto&& tc = entity.get_component_by_type_id<ECS::TransformComponent>();
		auto&& sc = entity.get_component_by_type_id<ECS::SpriteComponent>();
		SDL_Rect destRect{};
		destRect.x = static_cast<int>(tc.posX);
		destRect.y = static_cast<int>(tc.posY);
        if (sc.scale <= 0.0f)
        {
            destRect.w = sc.w;
            destRect.h = sc.h;
        }else{
            destRect.w = sc.w * sc.scale;
            destRect.h = sc.h * sc.scale;
        }
		
		SDL_RenderCopy(renderer, sc.get_texture(), NULL, &destRect);		
    }

	void RenderSystem::start()
	{
		SDL_RenderClear(renderer);
	}

	void RenderSystem::end()
	{
		SDL_RenderPresent(renderer);
	}
}
