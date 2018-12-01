#include "PUK/TextureManager.hpp"

namespace Util
{
	SDL_Texture* TextureManager::load_texture(std::string filename, SDL_Renderer * ren)
	{
		SDL_Surface *surface = IMG_Load(filename.c_str());

		if (surface == nullptr)
		{
			PUK_CLIENT_ERROR("Cannot load the image {}", filename);
		}

		SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
		SDL_FreeSurface(surface);

		if (texture == nullptr)
		{
			PUK_CLIENT_ERROR("Cannot create a texture from {}", filename);
		}

		return texture;
	}
}
