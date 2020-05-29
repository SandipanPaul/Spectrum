#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SPECTRUM_API __declspec(dllexport)
	#else
		#define SPECTRUM_API __declspec(dllimport)
	#endif
#else
#error Windows support for now!
#endif