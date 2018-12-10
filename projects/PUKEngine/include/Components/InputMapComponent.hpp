#pragma once

#include <bitset>
#include "Systems/EventSystem.hpp"


namespace Components {
    //constexpr int MAX_INPUT_EVENTS = 3; // Max number of components and entity can has
    
    using InputBitSet = std::bitset<Systems::MAX_EVENTS>;
    
    struct InputMapComponent : public ECS::Component
    {
    private:
        InputBitSet map;
    public:
        void turn_on(Systems::
        {
            
        }
    };
}

