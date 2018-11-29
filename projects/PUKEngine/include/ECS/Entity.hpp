#pragma once

#include <map>
#include <memory>
#include <iostream>
#include "Component.hpp"

namespace ECS
{
    struct Entity
    {
    private:
        std::map<ComponentTypeId, std::unique_ptr<Component> > components;
    public:
		template <typename T>
		void add_component(T&& comp)
		{
			components[get_component_type_id<T>()] = std::make_unique<T>(std::move(comp));
		}
		template <typename T>
		T* get_component_by_type_id()
		{
			return (T*)components[get_component_type_id<T>()].get();
		}
        std::unique_ptr<Component>& get_component_by_type_id(ComponentTypeId id);
    };
}