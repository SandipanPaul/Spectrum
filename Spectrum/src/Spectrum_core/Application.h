#pragma once

#include "Core.h"

namespace Spectrum {
	class SPECTRUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	//To be defined in client
	Application* CreateApplication();
}
