workspace "HazelLua-Examples"
	architecture "x86_64"
    startproject "HazelLua-Examples"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "."
include "HazelLua-Examples"