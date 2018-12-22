#pragma once

#include <memory>
#include "Worlds/WorldManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/EventSystem.hpp"
#include "Components/InputMapComponent.hpp"
#include "PUK/Log.hpp"
#include "Entities/Paddle.hpp"

namespace Worlds {
	class ArkanoidWorld : public World
	{
	private:
		std::shared_ptr<Systems::EventSystem> event_system;
		std::shared_ptr<ECS::RenderSystem> render_system;
		std::shared_ptr<ECS::Entity> paddle_entity1;
		std::shared_ptr<ECS::Entity> paddle_entity2;
	public:
		ArkanoidWorld(std::unique_ptr<Systems::EventSystem>&& es);
		~ArkanoidWorld();
		virtual void handle_input() override;
	private:
		void create_systems();
		void define_global_handlers();
		void create_paddles_entities();
		void create_ball_entity();
		void create_brick_entity();
		void register_systems();
        void init();
	};
}
