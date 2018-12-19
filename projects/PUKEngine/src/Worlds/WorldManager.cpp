#include "Worlds/WorldManager.hpp"

namespace Worlds {
    World::World()
    {}
    World::~World()
    {}
    
    void World::set_application(std::shared_ptr<PUK::Application> application)
    {
        app = std::move(application);
    }
    std::shared_ptr<PUK::Application> World::get_application()
    {
        return app;
    }
    
    void World::register_system(const std::shared_ptr<ECS::System> &system)
    {
        systems.push_back(system);
    }
    
    void World::add_entity(const std::shared_ptr<ECS::Entity> &entity)
    {
        entities.push_back(entity);
    }
    
    // WorldManager
    
    void WorldManager::push(World* world, PUK::Application* app)
    {
        
        std::unique_ptr<World> uPtr{world};
        std::shared_ptr<PUK::Application> sPtr{ app };
        (*uPtr).set_application(sPtr);
        worlds_stack.push(std::move(uPtr));
    }
    void WorldManager::pop()
    {
        worlds_stack.pop();
    }
}
