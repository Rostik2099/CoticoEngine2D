project "Game"
	kind "ConsoleApp"
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
		"%{wks.location}/CoticoEngine/Source",
		"%{wks.location}/CoticoEngine/ThirdParty/include",
		"%{wks.location}/Game/Source",
		"ThirdParty/include/",
	}

	libdirs
	{
		"ThirdParty/lib",
	}

	defines
	{
	}

	links
	{
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/MD"

	filter "configurations:Shipping"
		defines "SHIPPING"
		
