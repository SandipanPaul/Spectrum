#pragma once

#include "Spectrum_core/Input.h"

namespace Spectrum {
	class WindowsInput : public Input
	{
	protected:
		virtual bool isKeyPressedImpl(int kyecode) override;
		virtual bool isMouseButtonPressedImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
	};
}