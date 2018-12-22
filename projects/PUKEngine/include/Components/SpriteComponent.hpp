#pragma once

#include "ECS/Component.hpp"

namespace Components
{
	struct SpriteComponent : public ECS::Component
	{
	private:
		std::string filename = "";
		SDL_Texture* texture;
	public:
		int w, h;
		float scale = 0.0f;

		SpriteComponent(int w, int h, std::string filename) : ECS::Component()
		{
			this->w = w;
			this->h = h;
			this->filename = filename;
		}

		SpriteComponent(int w, int h, float scale, std::string filename) : ECS::Component()
		{
			this->w = w;
			this->h = h;
			this->scale = scale;
			this->filename = filename;
		}

		~SpriteComponent()
		{
			if (texture == nullptr)
			{
				SDL_DestroyTexture(texture);
			}
		}

		std::string get_filename() { return filename; }
		void set_texture(SDL_Texture* tex) { texture = tex; }
		SDL_Texture* get_texture() { return texture; }
	};
}

