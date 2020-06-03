workspace "Spectrum"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-x64"

-- Include directories relative to root folder (solution directory)
IncludeDir ={}
IncludeDir["GLFW"]="Spectrum/vendor/GLFW/include"
IncludeDir["Glad"]="Spectrum/vendor/Glad/include"
IncludeDir["ImGui"]="Spectrum/vendor/imgui"
IncludeDir["glm"]="Spectrum/vendor/glm"

include "Spectrum/vendor/GLFW"
include "Spectrum/vendor/Glad"
include "Spectrum/vendor/imgui"


project "Spectrum"
	location "Spectrum"
	kind "SharedLib"
	cppdialect "C++17"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sppch.h"
	pchsource "Spectrum/src/sppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "10.0.18362.0"

		defines
		{
			"SP_PLATFORM_WINDOWS",
			"SP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" ..outputdir .."/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "SP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SP_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Spectrum/vendor/spdlog/include",
		"Spectrum/src",
		"Spectrum/vendor",
		"%{IncludeDir.glm}"
	}
	
	defines
	{
		"SP_PLATFORM_WINDOWS"
	}

	links
	{
		"Spectrum"
	}

	filter "system:windows"
		systemversion "10.0.18362.0"
		
	filter "configurations:Debug"
		defines "SP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SP_DIST"
		runtime "Release"
		optimize "on"