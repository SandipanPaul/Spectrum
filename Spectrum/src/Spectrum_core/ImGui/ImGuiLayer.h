#pragma once

#include "Spectrum_core/Layer.h"
#include "Spectrum_core/Events/KeyEvent.h"
#include "Spectrum_core/Events/MouseEvent.h"
#include "Spectrum_core/Events/ApplicationEvent.h"

namespace Spectrum {
	class SPECTRUM_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
	private:
		float m_Time;
	};

}