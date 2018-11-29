#include "ECS/Component.hpp"

ECS::Component::Component() {}
ECS::Component::~Component()
{
}
ECS::ComponentId ECS::Component::get_id()
{
   return id;
}

ECS::TransformComponent::TransformComponent(float x, float y) : ECS::TransformComponent::Component()
{
   posX = x;
   posY = y;
}
ECS::TransformComponent::~TransformComponent()
{}

ECS::SpriteComponent::SpriteComponent(int w, int h) : ECS::TransformComponent::Component()
{
   this->w = w;
   this->h = h;
}
ECS::SpriteComponent::~SpriteComponent()
{}