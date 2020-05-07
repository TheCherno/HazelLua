#pragma once

#include <string>

namespace Hazel {

	class Entity
	{
	public:
		Entity(const std::string& name, const std::string& scriptPath);
		~Entity();

		void OnCreate();
		void OnDestroy();
		void OnUpdate(float ts);

		const std::string& GetName() const { return m_Name; }
	private:
		std::string m_Name;
		std::string m_ScriptPath;
	};

}