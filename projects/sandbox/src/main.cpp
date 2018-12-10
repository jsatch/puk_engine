#include <memory>
#include "ECS/Component.hpp"
#include "ECS/Entity.hpp"
#include "ECS/System.hpp"
#include "PUK/Log.hpp"
#include "PUK.hpp"
#include "Worlds/MenuWorld.hpp"
#include "Systems/EventSystem.hpp"

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

	PUK::Application* app = new SandBox();
	//auto event_system = std::make_unique<Systems::SDLEventSystem>();
	app->set_initial_world(new Worlds::MenuWorld(std::make_unique<Systems::SDLEventSystem>()));

    return app;
}

