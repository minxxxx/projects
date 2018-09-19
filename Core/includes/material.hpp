#pragma once

#include <stb_image.h>
#include <iostream>
#include <window.hpp>
#include <glm/glm.hpp>
#include <shader.hpp>
#include <vector>

namespace Zion
{
	class   Texture
	{
	private:
		GLuint  _textId = 0;
		bool    _loaded = false;
		int     _width;
		int     _height;
		int     _channel;
	private:
		bool    _loadImageToGPU(unsigned char *data);
	public:
		static std::vector<GLuint>  textureIDs;
	public:
		Texture() = default;
		Texture(const char *path);
		Texture(const Texture & rhs);
		Texture&    operator=(const Texture & rhs);
		~Texture();

		bool    loadTextureFromPath(const char *path);
		bool    loadTextureFromData(unsigned char *data, size_t len);
		bool    isLoaded() const;
		void    bindTexture(int index = 0);
		void    unbindTexture();
		GLuint  getTextureId() const;
	};

	struct      Material
	{
		Texture     texure;
		glm::vec4   base_color = glm::vec4(1.0, 1.0, 1.0, 1.0);
		glm::vec4   spec_color;

		Material() = default;
		~Material() = default;
		static  void    sendMaterialToShader(Shader& shader, Material& mat, int index);
	};
}