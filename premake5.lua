-- Solution: Kara
workspace "Kara"
    architecture "x64"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Project: Kara
project "Kara"
    location "Kara"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.hpp"
    pchsource "%{prj.name}/src/pch.cpp"

    files { "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.cpp" }

    includedirs { "%{prj.name}/vendor/spdlog/include", "%{prj.name}/src" }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines { "KARA_PLATFORM_WINDOWS", "KARA_BUILD_DLL" }

        postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") }

        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "KARA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KARA_RELEASE"
        optimize "On"

-- Project: Sandbox
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.cpp" }

    includedirs { "Kara/vendor/spdlog/include", "Kara/src" }

    links { "Kara" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines "KARA_PLATFORM_WINDOWS"

        buildoptions { "/utf-8" }
    
    filter "configurations:Debug"
        defines "KARA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KARA_RELEASE"
        optimize "On"