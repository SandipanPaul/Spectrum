#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Spectrum_core/LayerStack.h"
#include "Spectrum_core/Events/ApplicationEvent.h"


namespace Spectrum {
	class SPECTRUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	
	//To be defined in client
	Application* CreateApplication();
}
