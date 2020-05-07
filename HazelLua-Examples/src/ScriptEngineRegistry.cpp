#include "ScriptEngineRegistry.h"

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "Texture.h"
#include "Renderer.h"

namespace Hazel {

	namespace Scripting {
		extern sol::state* GetState();
	}

	static void RegisterTexture2D()
	{
		auto lua = Scripting::GetState();

		auto texture2D = lua->new_usertype<Texture2D>("Texture2D", sol::no_constructor);
		texture2D["Create"] = &Texture2D::Create;
		texture2D["GetWidth"] = &Texture2D::GetWidth;
		texture2D["GetHeight"] = &Texture2D::GetHeight;
		texture2D["GetFormat"] = &Texture2D::GetFormat;
		texture2D["GetFilePath"] = &Texture2D::GetFilePath;
	}

	static void RegisterRenderer()
	{
		auto lua = Scripting::GetState();

		auto renderer = lua->new_usertype<Renderer>("Renderer", sol::no_constructor);
		renderer["PrintTextureDetailsBase"] = static_cast<void(*)(const std::shared_ptr<Texture2D>&)>(&Renderer::PrintTextureDetailsBase);
		renderer["PrintTextureDetails"] = &Renderer::PrintTextureDetails;

	}

	void ScriptEngineRegistry::RegisterAllTypes()
	{
		RegisterTexture2D();
		RegisterRenderer();
	}

}

