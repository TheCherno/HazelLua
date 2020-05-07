#pragma once

#include "Texture.h"

namespace Hazel {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& filename);
		virtual ~OpenGLTexture2D();

		virtual uint32_t GetWidth() override { return m_Width; }
		virtual uint32_t GetHeight() override { return m_Height; }
		virtual uint32_t GetFormat() override { return m_Format; }
		virtual const std::string& GetFilePath() const override { return m_FilePath; }
	private:
		std::string m_FilePath;
		uint32_t m_Width, m_Height, m_Format;
	};

}