workspace "PUK"
  architecture "x64"
  configurations {"Debug", "Release"}
  location "generated"
  startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PUKEngine"
  location "projects/PUKEngine"
  kind "StaticLib"
  language "C++"
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "projects/%{prj.name}/include/**.hpp",
    "projects/%{prj.name}/src/**.cpp"
  }

  cppdialect "C++17"

  filter "system:windows"
    systemversion "latest"
    staticruntime "On"
    includedirs
    {
      "vendor/spdlog/include",
      "projects/%{prj.name}/include",
      "../../cpp_libs/SDL2-devel-2.0.8-VC/SDL2/include",
      "../../cpp_libs/SDL2_image-devel-2.0.3-VC/SDL2_image/include"
    }

    defines {"PUK_WIN"}

    links
    {
      "../../cpp_libs/SDL2-devel-2.0.8-VC/SDL2/lib/x64/*.dll",
      "../../cpp_libs/SDL2_image-devel-2.0.3-VC/SDL2_image/lib/x64/*.dll",
      "../../cpp_libs/SDL2_image-devel-2.0.3-VC/SDL2_image/lib/x64/*.lib"
    }

  filter "system:macosx"
    systemversion "latest"
    staticruntime "On"
    includedirs
    {
      "vendor/spdlog/include",
      "projects/%{prj.name}/include"
    }

    defines { "PUK_OSX" }

    frameworkdirs
    {
      "/Library/Frameworks/"
    }
    links
    {
      "SDL2.framework",
      "SDL2_image.framework"
    }


  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

project "Sandbox"
  location "projects/sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "projects/%{prj.name}/include/**.hpp",
    "projects/%{prj.name}/src/**.cpp"
  }

  cppdialect "C++17"

  filter "system:windows"
    systemversion "latest"
    staticruntime "On"

    includedirs
    {
      "vendor/spdlog/include",
      "projects/PUKEngine/include",
      "../../cpp_libs/SDL2-devel-2.0.8-VC/SDL2/include",
      "../../cpp_libs/SDL2_image-devel-2.0.3-VC/SDL2_image/include"
    }


    defines {"PUK_WIN"}

    links
    {
      "../../cpp_libs/SDL2-devel-2.0.8-VC/SDL2/lib/x64/SDL2.lib",
      "../../cpp_libs/SDL2-devel-2.0.8-VC/SDL2/lib/x64/SDL2main.lib",
      "../../cpp_libs/SDL2_image-devel-2.0.3-VC/SDL2_image/lib/x64/*.lib",
      "../../cpp_libs/SDL2-devel-2.0.8-VC/SDL2/lib/x64/*.dll",
      "../../cpp_libs/SDL2_image-devel-2.0.3-VC/SDL2_image/lib/x64/*.dll",
      "PUKEngine"
    }


  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"



