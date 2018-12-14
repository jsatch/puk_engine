#pragma once

#include <memory>
#include "Worlds/WorldManager.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/EventSystem.hpp"
#include "Components/InputMapComponent.hpp"
#include "PUK/Log.hpp"

namespace Worlds {
	class ArkanoidWorld : public World
	{
	private:
		std::shared_ptr<Systems::EventSystem> event_system;
		std::shared_ptr<ECS::RenderSystem> render_system;
		std::shared_ptr<ECS::Entity> scott_entity;
	public:
		ArkanoidWorld(std::unique_ptr<Systems::EventSystem>&& es);
		~ArkanoidWorld();
		virtual void update(milisecs delta) override;
		virtual void handle_input() override;
	private:
		void create_systems();
		void define_global_handlers();
		void create_paddle_entity();
		void create_ball_entity();
		void create_brick_entity();
		void register_systems();
	};
}