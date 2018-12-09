#pragma once

#include <iostream>
#include <memory>
#include "Worlds/WorldManager.hpp"

namespace PUK {

    class Application
    {
	protected:
		std::shared_ptr<Worlds::WorldManager> world_manager;
		bool running = false;
    public:
        Application();
        virtual ~Application();
        void run();
		void set_initial_world(Worlds::World* world)
		{
			(*world_manager).push(world, this);
		}
		void stop();
    };
    Application* create_application();
}