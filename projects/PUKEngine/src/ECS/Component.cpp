#include "ECS/Component.hpp"

ECS::Component::Component() {}
ECS::Component::~Component()
{
}
ECS::ComponentId ECS::Component::get_id()
{
   return id;
}
