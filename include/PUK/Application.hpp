#pragma once

#include <iostream>

namespace PUK {

    class Application
    {
    public:
        Application();
        virtual ~Application();
        void run();
    };
    Application* create_application();
}