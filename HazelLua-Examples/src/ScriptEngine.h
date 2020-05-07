#pragma once

#include <string>

#include "Entity.h"

namespace Hazel {

	class ScriptEngine
	{
	public:
		static void Init();
		static void Shutdown();

		static void ExecuteScript(const std::string& file);
		static void LoadEntityScript(const std::string& file);

		// Lua functions to call from C++
		static void OnCreate(const Entity* entity);
		static void OnDestroyed(const Entity* entity);
		static void OnUpdate(const Entity* entity, float ts);

		static void LoadScript(const std::string& file);
	};


}
