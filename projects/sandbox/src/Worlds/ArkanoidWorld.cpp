#include "Worlds/ArkanoidWorld.hpp"

namespace Worlds {
	ArkanoidWorld::ArkanoidWorld(std::unique_ptr<Systems::EventSystem>&& es)
	{
		event_system = std::move(es); // forcing a move semantic

		define_global_handlers();
		create_systems();
        
		register_systems();
        
		create_paddles_entities();
		create_ball_entity();
        
        init();
	}

	ArkanoidWorld::~ArkanoidWorld()
	{

	}

	void ArkanoidWorld::handle_input()
	{
		(*event_system).handle_input();
	}

	// private

	void ArkanoidWorld::create_systems()
	{
		// Render System
		auto gp = ECS::GameProperties{ "Sandbox", SDL_WINDOW_SHOWN, 800, 600 };
		render_system = std::make_shared<ECS::RenderSystem>(gp);

		(*render_system).register_component<Components::SpriteComponent>();
		(*render_system).register_component<Components::TransformComponent>();

		//Event system
		(*event_system).register_component<Components::InputMapComponent>();
		(*event_system).register_component<Components::InputHandlerComponent>();

		//PhysicsSystem
		physics_system = std::make_shared<Systems::Physics::PhysicsSystem>();

	}

	void ArkanoidWorld::define_global_handlers()
	{
		// Quiting app
		(*event_system).add_listener(Systems::on_exit, [&](Systems::EventData* data) -> void {
			PUK_CLIENT_INFO("Quiting app...");
			(*get_application()).stop();
		});
	}

	void ArkanoidWorld::register_systems()
	{
		register_system(render_system);
		register_system(event_system);
		register_system(physics_system);
	}
    
    void ArkanoidWorld::init()
    {
        (*render_system).init();
        
        // Loading sprite
        (*render_system).loading_sprite(*paddle_entity1);
		(*render_system).loading_sprite(*paddle_entity2);
		(*render_system).loading_sprite(*ball_entity);
    }

	void ArkanoidWorld::create_paddles_entities()
	{
        paddle_entity1 = std::make_shared<Entities::Paddle>(10.0f, 10.0f, true);
        add_entity(paddle_entity1);
		paddle_entity2 = std::make_shared<Entities::Paddle>(10.0f, 500.0f, false);
		add_entity(paddle_entity2);
	}

	void ArkanoidWorld::create_ball_entity()
	{
		ball_entity = std::make_shared<Entities::Ball>(400.0f, 300.0f);
		add_entity(ball_entity);
	}

	void ArkanoidWorld::create_brick_entity()
	{

	}
}
