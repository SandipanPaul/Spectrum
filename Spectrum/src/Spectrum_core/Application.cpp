#include "Application.h"
#include "Spectrum_core/Events/ApplicationEvent.h"
#include "Log.h"
namespace Spectrum {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		WinddowResizeEvent e(1280, 720);
		SP_TRACE(e);
		while (true);
	}
}