#pragma once

#include "Spectrum_core/Layer.h"

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
		float m_Time;
	};

}