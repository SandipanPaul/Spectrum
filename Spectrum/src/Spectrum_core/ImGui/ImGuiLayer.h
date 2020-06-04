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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time;
	};

}