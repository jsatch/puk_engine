#include <memory>
#include "ECS/Component.hpp"
#include "ECS/Entity.hpp"
#include "ECS/System.hpp"
#include "PUK/Log.hpp"
#include "PUK.hpp"

class SandBox : public PUK::Application
{
public:
    SandBox()
    {}
    ~SandBox()
    {}
};

PUK::Application* PUK::create_application(){
    PUK_INIT();

    ECS::ComponentTypeId id1 = ECS::get_component_type_id<ECS::TransformComponent>();
    PUK_CLIENT_INFO("TransformComponent: {}", id1);

    ECS::ComponentTypeId id2 = ECS::get_component_type_id<ECS::SpriteComponent>();
    PUK_CLIENT_INFO("SpriteComponent: {}", id2);

    ECS::Entity e1;

	ECS::TransformComponent comp{ 10.0f, 10.0f };
	ECS::SpriteComponent comp2{ 100, 100 };
	//e1.get_component_by_type_id<ECS::TransformComponent>();
	e1.add_component<ECS::SpriteComponent>(ECS::SpriteComponent(100, 100));
	e1.add_component<ECS::TransformComponent>(ECS::TransformComponent(10.0f, 10.0f));
	
	
	ECS::RenderSystem renderSystem{};
	renderSystem.register_component<ECS::SpriteComponent>();
	renderSystem.register_component<ECS::TransformComponent>();
	PUK_CLIENT_INFO("Entity 1 has match with RenderSystem: {}", renderSystem.has_match(e1));


    return new SandBox();
}

/*int main(int argc, char const *argv[])
{

    PUK_INIT();
    PUK_CLIENT_INFO("Inicia");
    ECS::TransformComponent tc {100.0f , 100.0f};
    ECS::Entity e1;
    e1.add_component(std::make_shared<ECS::TransformComponent>(tc));
    ECS::System s1{};
    s1.register_component(tc.get_component_type_id());
    PUK_CLIENT_INFO("Hay Match?: {}", s1.has_match(e1));
    return 0;
}*/
