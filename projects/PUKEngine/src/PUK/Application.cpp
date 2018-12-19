#include "PUK/Application.hpp"

namespace PUK {
    Application::Application()
    {
		world_manager = std::make_shared<Worlds::WorldManager>();
	}
    Application::~Application()
    {}
    void Application::set_initial_world(Worlds::World* world)
    {
        (*world_manager).push(world, this);
    }
    void Application::run() 
    {
		running = true;
        while(running) 
		{
			(*world_manager).top<Worlds::World>()->handle_input();
			//world_manager->top<Worlds::World>()->update();
			(*world_manager).top<Worlds::World>()->render();
        }
    }
	void Application::stop()
	{
		running = false;
	}
}
