#include "OpenGLTexture.h"

#include <iostream>

namespace Hazel {

	OpenGLTexture2D::OpenGLTexture2D(const std::string& filename)
		: m_FilePath(filename)
	{
		m_Width = 1024;
		m_Height = 512;
		m_Format = 8;
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		std::cout << "OpenGLTexture2D destroyed!\n";
	}

}