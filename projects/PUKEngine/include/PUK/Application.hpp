#pragma once

#include <iostream>
#include <memory>
#include "Worlds/WorldManager.hpp"

namespace Worlds {
    class World;
    class WorldManager;
}

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
        void set_initial_world(Worlds::World* world);
		void stop();
    };
    Application* create_application();
}
