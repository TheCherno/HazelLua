#include "Entity.h"

#include "ScriptEngine.h"

namespace Hazel {

	Entity::Entity(const std::string& name, const std::string& scriptPath)
		: m_Name(name), m_ScriptPath(scriptPath)
	{
		Hazel::ScriptEngine::LoadEntityScript(scriptPath);

		OnCreate();
	}

	Entity::~Entity()
	{
		OnDestroy();
	}

	void Entity::OnCreate()
	{
		Hazel::ScriptEngine::OnCreate(this);
	}

	void Entity::OnDestroy()
	{
		Hazel::ScriptEngine::OnCreate(this);
	}

	void Entity::OnUpdate(float ts)
	{
		Hazel::ScriptEngine::OnUpdate(this, ts);
	}

}