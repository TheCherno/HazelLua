#include "ScriptEngine.h"

#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

#include "lstate.h"
#include "setjmp.h"

#include "ScriptEngineRegistry.h"

namespace Hazel {

	struct ScriptEngineData
	{
		sol::state* LuaState = nullptr;
	};
	static ScriptEngineData s_Data;

	namespace Scripting {
		sol::state* GetState() { return s_Data.LuaState; }
	}

	static jmp_buf s_LuaPanicJump;

	static int Lua_AtPanicHandler(lua_State* lua)
	{
		longjmp(s_LuaPanicJump, 1);
		return 0; // Will never return
	}

	static void OnInternalLuaError()
	{
		std::cout << "[ScriptEngine] Internal Lua error!\n";
	}

	void ScriptEngine::Init()
	{
		std::cout << "[ScriptEngine] Initializing.\n";

		s_Data.LuaState = new sol::state();
		s_Data.LuaState->open_libraries(sol::lib::base, sol::lib::math);

		lua_State* L = s_Data.LuaState->lua_state();
		L->l_G->panic = [](lua_State* L)
		{
			std::cout << "[ScriptEngine] PANIC!!! We should never reach this line!\n";
			return 0;
		};

		lua_atpanic(L, &Lua_AtPanicHandler);
		 
		ScriptEngineRegistry::RegisterAllTypes();
	}

	void ScriptEngine::Shutdown()
	{
		std::cout << "[ScriptEngine] Shutting down.\n";

		delete s_Data.LuaState;
		s_Data.LuaState = nullptr;
	}

#define LUA_CALL(Namespace, Function, ...) \
	if (setjmp(s_LuaPanicJump) == 0)\
	{\
		lua[Namespace][Function](__VA_ARGS__);\
	}\
	else\
	{\
		OnInternalLuaError();\
	}

	void ScriptEngine::ExecuteScript(const std::string& file)
	{
		std::cout << "[ScriptEngine] Running " << file << "...\n";

		auto result = s_Data.LuaState->script_file(file, [](lua_State*, sol::protected_function_result result)
		{
			std::cout << "[ScriptEngine] Lua error!\n";
			return result;
		});
	}

	void ScriptEngine::LoadEntityScript(const std::string& file)
	{
		std::cout << "[ScriptEngine] Running " << file << "...\n";

		sol::load_result loadResult = s_Data.LuaState->load_file(file);
		if (!loadResult.valid())
		{
			sol::error error = loadResult;
			std::cout << "[ScriptEngine] Lua error!\n";
			std::cout << "  " << error.what() << std::endl;
		}
		else
		{
			sol::protected_function_result functionResult = loadResult();
			if (!functionResult.valid())
			{
				sol::error error = functionResult;
				std::cout << "[ScriptEngine] Lua error!\n";
				std::cout << "  " << error.what() << std::endl;
			}
		}
	}

	void ScriptEngine::OnCreate(const Entity* entity)
	{
		auto& lua = *s_Data.LuaState;
		LUA_CALL(entity->GetName(), "OnCreate");
	}

	void ScriptEngine::OnDestroyed(const Entity* entity)
	{
		auto& lua = *s_Data.LuaState;
		LUA_CALL(entity->GetName(), "OnDestroy");
	}

	void ScriptEngine::OnUpdate(const Entity* entity, float ts)
	{
		auto& lua = *s_Data.LuaState;
		LUA_CALL(entity->GetName(), "OnUpdate", ts);
	}
}