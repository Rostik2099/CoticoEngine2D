project "CoticoEngine"
	kind "StaticLib"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Source/**.h",
		"Source/**.cpp",
	}

	includedirs 
	{
		"ThirdParty/include",
		"ThirdParty/include/ImGUI",
		"ThirdParty/include/SFML",
		"Source",
	}

	libdirs
	{
		"ThirdParty/lib",
		"ThirdParty/lib/SFML",
	}

	defines
	{
		"SFML_STATIC",
	}

	links
	{
		"opengl32.lib",
		"openal32.lib",
		"freetype.lib",
		"winmm.lib",
		"gdi32.lib",
		"flac.lib",
		"vorbisenc.lib",
		"vorbisfile.lib",
		"vorbis.lib",
		"ogg.lib",
		"sfml-graphics-s.lib",	
		"sfml-window-s.lib",
		"sfml-system-s.lib",	
		"sfml-audio-s.lib",
		"sfml-network-s.lib",			
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter { "system:windows"}
		buildoptions "/MD"