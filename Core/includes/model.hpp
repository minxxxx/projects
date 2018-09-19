#pragma once

#include <map>
#include <stdexcept>
#include <material.hpp>
#include <renderable.hpp>

namespace Zion
{
	struct  Model : public Renderable
	{
	protected:
		GLuint      _vao;
		GLuint      _ibo;
		std::vector<GLuint>     _vbos;
		std::vector<GLushort>   _indices;
		std::vector<float>      _vertex;
		std::vector<float>      _matIndexs;
		std::vector<float>      _normals;
		std::vector<float>      _uvs;
		std::map<int, Material> _materials;
		bool                    _loaded = false;
		bool                    _hasJoint = false;
		glm::mat4               _locMat;
		GLushort                _indicesCount;
		std::map<int, glm::mat4>   _animeMatrice;
	public:
		template <typename T>
		static  void    loadOneManyToVector(std::vector<T>& list, T val, int count)
		{
			for (int i = 0; i < count; i++)
				list.push_back(val);
		}
	public:
		virtual bool    loadFromFile(Shader& shader, const char *path) = 0;
		virtual void    render(glm::mat4 matrix) = 0;
		virtual void    simpleRender(glm::mat4 matrix) = 0;

		void            setLocalMatrix(glm::mat4 mat) { _locMat = mat; }

		void            loadMaterialToShader()
		{
			for (std::pair<int, Material> material : _materials)
				Material::sendMaterialToShader(_shader, material.second, material.first);
		}

		void            unloadMaterialFromShader()
		{
			for (std::pair<int, Material> material : _materials)
				material.second.texure.unbindTexture();
		}

		void            addMaterial(int index, Material material)
		{
			_materials.insert(std::make_pair(index, material));
		}

		void            addTextureToMaterial(int index, Texture texture)
		{
			try {
				_materials.at(index).texure = texture;
			}catch (const std::out_of_range& oor) {
				std::cerr << "Invalid index in add texture in model : " << index << std::endl;
			}

		}

		void            addBaseColorToMaterial(int index, glm::vec4 color)
		{
			try {
				_materials.at(index).base_color = color;
			}catch (const std::out_of_range& oor) {
				std::cerr << "Invalid index in add base color in model : " << index << std::endl;
			}

		}

		void            loadTextureToMaterial(int index, const char *path)
		{
			try {
				_materials.at(index).texure.loadTextureFromPath(path);
			}catch (const std::out_of_range& oor) {
				std::cerr << "Invalid index in load texture in model : " << index << std::endl;
			}

		}
	};
}