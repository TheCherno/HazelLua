#pragma once

#include <string>
#include <memory>

namespace Hazel {

	class Texture
	{
	public:
		virtual ~Texture() {}

		virtual uint32_t GetWidth() = 0;
		virtual uint32_t GetHeight() = 0;
	};

	class Texture2D : public Texture
	{
	public:
		virtual ~Texture2D() {}

		virtual uint32_t GetFormat() = 0;
		virtual const std::string& GetFilePath() const = 0;

		static std::shared_ptr<Texture2D> Create(const std::string& filename);
	};

}

// Do we need this?
// SOL_BASE_CLASSES(Texture2D, Texture);
// SOL_BASE_CLASSES(OpenGLTexture2D, Texture2D);
// SOL_DERIVED_CLASSES(Texture, Texture2D);
// SOL_DERIVED_CLASSES(Texture2D, OpenGLTexture2D);