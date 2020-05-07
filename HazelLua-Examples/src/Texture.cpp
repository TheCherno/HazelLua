#include "Texture.h"

#include "OpenGLTexture.h"

namespace Hazel {

	std::shared_ptr<Texture2D> Texture2D::Texture2D::Create(const std::string& filename)
	{
		return std::make_shared<OpenGLTexture2D>(filename);
	}

}