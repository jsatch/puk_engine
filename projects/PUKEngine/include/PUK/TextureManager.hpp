#pragma once

#ifdef PUK_WIN
#include "SDL.h"
#include "SDL_image.h"
#else
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#endif // PUK_WIN

#include "iostream"
#include "PUK/Log.hpp"

namespace Util 
{
	class TextureManager
	{
	public:
		static SDL_Texture* load_texture(std::string filename, SDL_Renderer* ren);
	};
}



