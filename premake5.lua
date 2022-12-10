workspace "Gazel"
	startproject "Sandbox"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include dirs relative to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "Gazel/vendor/GLFW/include"
IncludeDir["Glad"] = "Gazel/vendor/Glad/include"
IncludeDir["glm"] = "Gazel/vendor/glm"
IncludeDir["ImGui"] = "Gazel/vendor/imgui"
IncludeDir["stb_image"] = "Gazel/vendor/stb_image"

group "Dependencies"
	include "Gazel/vendor/GLFW"
	include "Gazel/vendor/Glad"
	include "Gazel/vendor/imgui"
group ""

project "Gazel"
	location "Gazel"
	kind "StaticLib"
	cppdialect "C++17"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "gzpch.h"
	pchsource "Gazel/src/gzpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARINGS"
	}
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.stb_image}"
	}
	
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"GZ_PLATFORM_WINDOWS",
			"GZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
	filter "configurations:Debug"
		defines "GZ_DEBUG"
		buildoptions"/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "GZ_RELEASE"
		buildoptions"/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "GZ_DIST"
		buildoptions"/MD"
		optimize "on" 

project"Sandbox"
	location"Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime"on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		
	}

	includedirs{
		"Gazel/vendor/spdlog/include",
		"Gazel/src",
		"Gazel/vendor",
		"%{IncludeDir.glm}"
	}

	links{
		"Gazel"
	}

	filter "system:windows"
	
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GZ_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "GZ_DEBUG"
		buildoptions"/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "GZ_RELEASE"
		buildoptions"/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "GZ_DIST"
		buildoptions"/MD"
		optimize "on"
