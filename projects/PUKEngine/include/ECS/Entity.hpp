#pragma once

#include <map>
#include <array>
#include <bitset>
#include <memory>
#include <iostream>
#include "Component.hpp"

namespace ECS
{
	constexpr int MAX_COMPONENTS = 40; // Max number of components and entity can has

	using ComponentBitSet = std::bitset<MAX_COMPONENTS>;

    struct Entity
    {
    private:
        std::map<ComponentTypeId, std::unique_ptr<Component> > components;
		ComponentBitSet components_bitset;
    public:
		template <typename T>
		void add_component(T&& comp) 
		{
			components[get_component_type_id<T>()] = std::make_unique<T>(std::move(comp));
			components_bitset[get_component_type_id<T>()] = true;
		}
		
		// Analizar mejor por que esta funcion no puede ser const
		template <typename T>
		T* get_component_by_type_id()
		{
			return (T*)components[get_component_type_id<T>()].get();
		}

		template <typename T>
		bool has_component() const
		{
			return components_bitset[get_component_type_id<T>()];
		}

		bool has_component(ComponentTypeId typeId) const
		{
			return components_bitset[typeId];
		}
    };
}