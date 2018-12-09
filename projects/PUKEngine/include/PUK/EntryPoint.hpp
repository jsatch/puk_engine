#pragma once

extern PUK::Application* PUK::create_application();

int main(int argc, char** argv)
{
    auto app = PUK::create_application();
    app->run();
	return 0;
}