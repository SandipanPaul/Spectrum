#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Spectrum_core/LayerStack.h"
#include "Spectrum_core/Events/ApplicationEvent.h"
#include "Spectrum_core/ImGui/ImGuiLayer.h"


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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	
	//To be defined in client
	Application* CreateApplication();
}
