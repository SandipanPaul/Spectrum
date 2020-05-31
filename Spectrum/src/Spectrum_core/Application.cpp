#include "sppch.h"
#include "Application.h"
#include "Spectrum_core/Events/ApplicationEvent.h"
#include "Log.h"
namespace Spectrum {

	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		
		while (m_Running) {
			m_window->OnUpdate();
		}
	}
}