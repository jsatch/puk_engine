#pragma once

#include <memory>
#include <vector>
#include <stack>
#include "ECS/Entity.hpp"
#include "ECS/System.hpp"

namespace Worlds
{
    using milisecs = unsigned int;
    class World
    {
    private:
        std::vector<std::shared_ptr<ECS::Entity>> entities;
        std::vector<std::shared_ptr<ECS::System>> systems;
        void add_system(ECS::System& system) const 
        {
            systems.push_back(std::make_shared<ECS::System>(system));
        }
        void add_entity(ECS::Entity& entity) const
        {
            entities.push_back(std::make_shared<ECS::Entity>(entity));
        }
    public:
        virtual void update(milisecs delta) = 0;
        virtual void render() = 0;
    };

    class WorldManager
    {
    private:
        std::stack<std::shared_ptr<World>> worlds_stack;
    public:
        void push(World& world) const
        {
            worlds_stack.push(std::make_shared<World>(world));
        }
        void pop() const
        {
            worlds_stack.pop();
        }
        std::shared_ptr<World> top() const
        {
            return worlds_stack.top()
        }
    };
}