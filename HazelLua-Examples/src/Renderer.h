#pragma once

#include <iostream>
#include "Texture.h"

namespace Hazel {

	class Renderer
	{
	public:
		static void PrintTextureDetailsBase(const std::shared_ptr<Texture>& texture)
		{
			std::cout << "Renderer::PrintTextureDetailsBase" << std::endl;
			std::cout << "  Width: " << texture->GetWidth() << std::endl;
			std::cout << "  Height: " << texture->GetHeight() << std::endl;
		}

		static void PrintTextureDetailsBase(const std::shared_ptr<Texture2D>& texture)
		{
			PrintTextureDetailsBase(std::dynamic_pointer_cast<Texture>(texture));
		}

		static void PrintTextureDetails(const std::shared_ptr<Texture2D>& texture)
		{
			std::cout << "Renderer::PrintTextureDetails" << std::endl;
			std::cout << "  Path: " << texture->GetFilePath() << std::endl;
		}
	};

}