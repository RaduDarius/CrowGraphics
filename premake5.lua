-- Solution: Kara
workspace "Kara"
    architecture "x64"
    configurations { "Debug", "Release" }

    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include other submodules 
include "Kara/vendor/GLFW"
include "Kara/vendor/GLAD"
include "Kara/vendor/imgui"

-- Project: Kara
project "Kara"
    location "Kara"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.hpp"
    pchsource "%{prj.name}/src/pch.cpp"

    files { "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.cpp" }

    includedirs { 
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/GLFW/include", 
        "%{prj.name}/vendor/GLAD/include", 
        "%{prj.name}/vendor/imgui", 
        "%{prj.name}/vendor/glm", 
        "%{prj.name}/src" 
    }
    
    links { 
        "GLFW", 
        "GLAD", 
        "imgui",
        "opengl32.lib" 
     }

    filter "system:windows"
        systemversion "latest"

        defines { "KARA_PLATFORM_WINDOWS", "KARA_BUILD_DLL", "GLFW_INCLUDE_NONE", "_CRT_SECURE_NO_WARNINGS" }

        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines {"KARA_DEBUG", "KARA_ENABLE_ASSERTS"}
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "KARA_RELEASE"
        runtime "Release"
        optimize "On"

-- Project: Sandbox
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.cpp" }

    includedirs { 
        "Kara/vendor/spdlog/include", 
        "Kara/src", 
        "Kara/vendor/glm" 
    }

    links { "Kara" }

    filter "system:windows"
        systemversion "latest"

        defines { "KARA_PLATFORM_WINDOWS", "_CRT_SECURE_NO_WARNINGS" }

        buildoptions { "/utf-8" }
    
    filter "configurations:Debug"
        defines "KARA_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "KARA_RELEASE"
        runtime "Release"
        optimize "On"