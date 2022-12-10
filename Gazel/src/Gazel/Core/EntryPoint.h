#pragma once


#ifdef GZ_PLATFORM_WINDOWS

extern Gazel::Application* Gazel::CreateApplication();


int main(int argc, char** argv)
{
	Gazel::Log::Init();
	GZ_CORE_WARN("This is initlzation spdlog!");
	int a = 5;
	GZ_INFO("Hello!", a);

	auto app = Gazel::CreateApplication();
	app->Run();
	delete app;
}

#endif 
