#pragma once

#include   <renderable.hpp>
#include <material.hpp>

namespace Zion
{
	class   StaticSprite : public Renderable
	{
	protected:
		GLuint      _vao;
		GLuint      _vbo;
		GLuint      _ibo;
		Material    _material;
	protected:
		virtual void _addVertexAttrib(GLsizei stride) = 0;
		void    _loadDataToGpu(GLfloat *vertex, GLsizei vertCount, GLushort *indices,
		                       GLsizei indCount, GLsizei stride)
		{
			glGenVertexArrays(1, &_vao);
			glBindVertexArray(_vao);
			glGenBuffers(1, &_vbo);
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(GLfloat), vertex, GL_STATIC_DRAW);
			Window::getError((char *)"square vertex buffer");
			_addVertexAttrib(stride);
			glGenBuffers(1, &_ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indCount * sizeof(GLushort), indices, GL_STATIC_DRAW);
			glBindVertexArray(0);
			Window::getError((char *)"square index array buffer");
		}
	public:
		virtual void    render(glm::mat4 matrix) = 0;
		void            simpleRender(glm::mat4 matrix){}
		void            addTextureFromFile(const char *path)
		{
			_material.texure.loadTextureFromPath(path);
		}
		void            addTextureFromData(unsigned char *data, size_t len)
		{
			_material.texure.loadTextureFromData(data, len);
		}
		void            addBaseColor(glm::vec4 color)
		{
			_material.base_color = color;
		}
	};

	///struct of a square sprite
	struct   SquareSprite : public StaticSprite
	{
	private:
		void    _addVertexAttrib(GLsizei stride);
	public:
		SquareSprite(Shader& shader, float posx, float posy, float width, float height);
		~SquareSprite();

		void    render(glm::mat4 matrix);
	};

	///struct of a cube sprite
	struct  CubeSprite : public StaticSprite
	{
	private:
		GLuint      _uvVbo;
		void        _addVertexAttrib(GLsizei stride);
		glm::mat4   _cubeMat;
	public:
		CubeSprite(Shader& shader, float posx, float posy, float posz, float breadth, float length, float height);
		~CubeSprite();

		void    render(glm::mat4 matrix);
	};
}