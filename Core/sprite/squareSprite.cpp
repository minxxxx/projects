#include <staticSprite.hpp>

namespace Zion
{
	float   Renderable::startTime;
	float   Renderable::runTime;
	float   Renderable::deltaTime;
	float   Renderable::secondsPassed;

	SquareSprite::SquareSprite(Shader &shader, float posx, float posy, float width, float height)
	{
		GLushort indices[] = {0, 1, 2, 2, 3, 0};
		GLfloat vertices[] =
		{
			-(width / 2) + posx, (height / 2) + posy, 0, 0, 0, 0,
			(width / 2) + posx, (height / 2) + posy, 0, 1, 0, 0,
			(width / 2) + posx, -(height / 2) + posy, 0, 1, 1, 0,
			-(width / 2) + posx, -(height / 2) + posy, 0, 0, 1, 0
		};
		_shader = shader;
		_loadDataToGpu(vertices, 6 * 4, indices, 6, sizeof(GLfloat) * 6);
	}

	SquareSprite::~SquareSprite()
	{
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ibo);
		glDeleteVertexArrays(1, &_vao);
	}

	void SquareSprite::_addVertexAttrib(GLsizei stride)
	{
		GLint position = _shader.getAttribLocation((char *)"position");
		GLint matIndex = _shader.getAttribLocation((char *)"matIndex");
		GLint uv = _shader.getAttribLocation((char *)"uv");

		if (position != -1)
		{
			glEnableVertexAttribArray((GLuint)position);
			glVertexAttribPointer((GLuint)position, 3, GL_FLOAT, GL_FALSE, stride, (void *)nullptr);
		}
		if (matIndex != -1)
		{
			glEnableVertexAttribArray((GLuint)matIndex);
			glVertexAttribPointer((GLuint)matIndex, 1, GL_FLOAT, GL_FALSE, stride, (void *)(sizeof(GLfloat) * 5));
		}
		if (uv != -1)
		{
			glEnableVertexAttribArray((GLuint)uv);
			glVertexAttribPointer((GLuint)uv, 2, GL_FLOAT, GL_FALSE, stride, (void *)(sizeof(GLfloat) * 3));
		}
		Window::getError((char *)"square add vertex attrib");
	}

	void SquareSprite::render(glm::mat4 matrix)
	{
		_shader.enable();
		_material.texure.bindTexture(0);
		_shader.setUniformMat4((GLchar *)"model_matrix", matrix);
		_shader.setUniform1i((GLchar *)"textures[0]", 0);
		_shader.setUniform1i((GLchar *)"isTexture[0]", (int)_material.texure.isLoaded());
		_shader.setUniform4f((GLchar *)"texColor[0]", _material.base_color);
		glBindVertexArray(_vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (const GLvoid *)nullptr);
		glBindVertexArray(0);
		_material.texure.unbindTexture();
		_shader.disable();
	}
}