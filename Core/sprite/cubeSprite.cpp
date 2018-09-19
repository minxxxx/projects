#include <staticSprite.hpp>

namespace Zion
{
	CubeSprite::CubeSprite(Shader &shader, float posx, float posy, float posz, float breadth, float length, float height)
	{
		_shader = shader;
		GLfloat vertices [] = {
				-0.5f,0.5f,-0.5f,0, -0.5f,-0.5f,-0.5f,0, 0.5f,-0.5f,-0.5f,0, 0.5f,0.5f,-0.5f,0,
				-0.5f,0.5f,0.5f,0, -0.5f,-0.5f,0.5f,0, 0.5f,-0.5f,0.5f,0, 0.5f,0.5f,0.5f,0,
				0.5f,0.5f,-0.5f,0, 0.5f,-0.5f,-0.5f,0, 0.5f,-0.5f,0.5f,0, 0.5f,0.5f,0.5f,0,
				-0.5f,0.5f,-0.5f,0, -0.5f,-0.5f,-0.5f,0, -0.5f,-0.5f,0.5f,0, -0.5f,0.5f,0.5f,0,
				-0.5f,0.5f,0.5f,0, -0.5f,0.5f,-0.5f,0, 0.5f,0.5f,-0.5f,0, 0.5f,0.5f,0.5f,0,
				-0.5f,-0.5f,0.5f,0, -0.5f,-0.5f,-0.5f,0, 0.5f,-0.5f,-0.5f,0, 0.5f,-0.5f,0.5f,0

		};
		GLfloat uvs [] = {
				0,0, 0,1, 1,1, 1,0, 0,0, 0,1, 1,1, 1,0,
				0,0, 0,1, 1,1, 1,0, 0,0, 0,1, 1,1, 1,0,
				0,0, 0,1, 1,1, 1,0, 0,0, 0,1, 1,1, 1,0
		};
		GLushort indices[] = {
				0,1,3, 3,1,2, 4,5,7, 7,5,6, 8,9,11, 11,9,10, 12,13,15,
				15,13,14, 16,17,19, 19,17,18, 20,21,23, 23,21,22
		};

		_loadDataToGpu(vertices, 24 * 4, indices, 36,  sizeof(GLfloat) * 4);
		/// Adding uv coords to vao
		glBindVertexArray(_vao);
		glGenBuffers(1, &_uvVbo);
		glBindBuffer(GL_ARRAY_BUFFER, _uvVbo);
		glBufferData(GL_ARRAY_BUFFER, 48 * sizeof(GLfloat), uvs, GL_STATIC_DRAW);
		GLint uv = _shader.getAttribLocation((char *)"uv");
		if (uv != -1)
		{
			glEnableVertexAttribArray((GLuint)uv);
			glVertexAttribPointer((GLuint)uv, 2, GL_FLOAT, GL_FALSE, 0, (void *)nullptr);
		}
		glBindVertexArray(0);
		_cubeMat = glm::translate(glm::mat4(), glm::vec3(posx, posy, posz)) *
		           glm::scale(glm::mat4(), glm::vec3(length, height, breadth));
	}

	CubeSprite::~CubeSprite()
	{
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ibo);
		glDeleteVertexArrays(1, &_vao);
	}

	void CubeSprite::_addVertexAttrib(GLsizei stride)
	{
		GLint position = _shader.getAttribLocation((char *)"position");
		GLint matIndex = _shader.getAttribLocation((char *)"matIndex");

		if (position != -1)
		{
			glEnableVertexAttribArray((GLuint)position);
			glVertexAttribPointer((GLuint)position, 3, GL_FLOAT, GL_FALSE, stride, (void *)nullptr);
		}
		if (matIndex != -1)
		{
			glEnableVertexAttribArray((GLuint)matIndex);
			glVertexAttribPointer((GLuint)matIndex, 1, GL_FLOAT, GL_FALSE, stride, (void *)(sizeof(GLfloat) * 3));
		}
		Window::getError((char *)"square add vertex attrib");
	}

	void CubeSprite::render(glm::mat4 matrix)
	{
		_shader.enable();
		_material.texure.bindTexture(0);
		_shader.setUniformMat4((GLchar *)"model_matrix", matrix * _cubeMat);
		_shader.setUniform1i((GLchar *)"textures[0]", 0);
		_shader.setUniform1i((GLchar *)"isTexture[0]", (int)_material.texure.isLoaded());
		_shader.setUniform4f((GLchar *)"texColor[0]", _material.base_color);
		glBindVertexArray(_vao);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, (const GLvoid *)nullptr);
		glBindVertexArray(0);
		_material.texure.unbindTexture();
		_shader.disable();
	}
}