#pragma once

#include <iostream>
#include "Worlds/WorldManager.hpp"

namespace PUK {

    class Application
    {
	protected:
		Worlds::WorldManager* world_manager;
    public:
        Application();
        virtual ~Application();
        void run();
		void set_initial_world(Worlds::World* world)
		{
			(*world_manager).push(world);
		}
    };
    Application* create_application();
}