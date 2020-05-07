//
// This is an example to show how to bind a game-engine-like
// asset type to Lua. Used as investigation for Hazel.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "ScriptEngine.h"
#include "Entity.h"

int main()
{
	Hazel::ScriptEngine::Init();
	
	std::vector<std::shared_ptr<Hazel::Entity>> entities;
	entities.push_back(std::make_shared<Hazel::Entity>("Player", "assets/Player.lua"));
	entities.push_back(std::make_shared<Hazel::Entity>("Enemy", "assets/Enemy.lua"));

	// Game loop
	uint32_t iterations = 5;
	while (iterations--)
	{
		for (auto entity : entities)
		{
			entity->OnUpdate(0.5f);
		}

		std::cout << std::endl;

		using namespace std::literals::chrono_literals;
		std::this_thread::sleep_for(500ms);
	}

	entities.clear();

	// Run Script.lua (Texture2D test)
	std::cout << "-----------------------------------------------\n";
	Hazel::ScriptEngine::ExecuteScript("assets/Script.lua");
	std::cout << "-----------------------------------------------\n";

	Hazel::ScriptEngine::Shutdown();

	std::cin.get();
}
