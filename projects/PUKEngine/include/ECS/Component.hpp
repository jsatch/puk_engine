#pragma once

#ifdef PUK_WIN
#include "SDL.h"
#endif // PUK_WIN

#ifdef PUK_OSX
#include "SDL2/SDL.h"
#endif // PUK_OSX

#include <iostream>
#include <memory>
#include <map>

namespace ECS
{
    using ComponentTypeId = size_t;
    using ComponentId = size_t;

    inline ComponentTypeId get_unique_component_id()
    {
        static ComponentTypeId last_id{0};
        return last_id++;
    }

    template<typename T>
    inline ComponentTypeId get_component_type_id()
    {
        static ComponentTypeId type_id{get_unique_component_id()};
        return type_id;
    }

    struct Component
    {
    protected:
        ComponentId id;
    public:
        Component();
        ~Component();
        ComponentId get_id();
    };

    struct TransformComponent : public Component
    {
    private:
    public:
        float posX, posY;
        TransformComponent(float x, float y);
        ~TransformComponent();
    };

    struct SpriteComponent : public Component
    {
    private:
		std::string filename = "";
		SDL_Texture* texture;
    public:
        int w, h;
        float scale = 0.0f;
        SpriteComponent(int w, int h, std::string filename);
        SpriteComponent(int w, int h, float scale, std::string filename);
        ~SpriteComponent();
		std::string get_filename(){ return filename; }
		void set_texture(SDL_Texture* tex){ texture = tex; }
		SDL_Texture* get_texture() { return texture; }
    };
}
