#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spectrum::Application* Spectrum::CreateApplication();
 
int main(int argc, char** argv) {

	Spectrum::Log::Init();
	SP_CORE_WARN("Initialized Log!");
	SP_INFO("Hello!");
	
	auto app = Spectrum::CreateApplication();
	app->Run();
	delete app;
}

#endif // SP_PLATFORM_WINDOWS
