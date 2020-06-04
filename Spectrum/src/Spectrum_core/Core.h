#pragma once

#ifdef SP_PLATFORM_WINDOWS
#if	SP_DYNAMIC_LINK
	#ifdef SP_BUILD_DLL
		#define SPECTRUM_API __declspec(dllexport)
	#else
		#define SPECTRUM_API __declspec(dllimport)
	#endif
#else
	#define SPECTRUM_API
#endif
#else
#error Windows support for now!
#endif

#ifdef SP_DEBUG
	#define SP_ENABLE_ASSERTS
#endif

#ifdef SP_ENABLE_ASSERTS
	#define SP_ASSERT(x, ...){if(!(x)){ SP_ERROR("Assertion failed: {0}",__VA_ARGS__);__debugbreak();}}
	#define SP_CORE_ASSERT(x, ...){if(!(x)){ SP_CORE_ERROR("Assertion failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
	#define SP_ASSERT(x,...)
	#define SP_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1<<x)
#define SP_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1) 