#pragma once

#include "PUK/Application.hpp"

namespace PUK {
    Application::Application()
    {
		world_manager = new Worlds::WorldManager();
	}
    Application::~Application()
    {
		if (world_manager != nullptr) { delete world_manager; }
	}
    void Application::run() 
    {


        while(true) {
            //std::cout << "Corriendo..." << std::endl;
			//world_manager->top<Worlds::World>()->update();
			world_manager->top<Worlds::World>()->render();

        }
    }
}