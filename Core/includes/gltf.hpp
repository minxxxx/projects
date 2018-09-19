#pragma once

#include <animation.hpp>
#include <model.hpp>
#include <glm/glm.hpp>
#include <glm/common.hpp>

namespace Zion
{
	struct Joint
	{
		int         id;
		int         index;
		std::string name;
		glm::mat4   invMatrix;
		std::vector<Joint *> children;
	};

	class   Gltf : public Model
	{
	private:
		tinygltf::Model     _model;
		std::vector<int>    _nodes;
		std::string         _path;
		std::vector<GLfloat>  _joints;
		std::vector<GLfloat>      _weights;
		std::vector<Joint *>    _bones;
		std::vector<Animation *>    _animations;
		int                     _boneCount = 0;
	private:
		bool    _processModel();
		void    _processModelMesh(tinygltf::Mesh& mesh, int node);
		void    _processNode(int index);
		void    _processSkin(tinygltf::Skin& skin);
		Joint   *_processSkinJoints(int id, std::vector<glm::mat4> mats, int start, int skeleton);
		void    _loadDataToGpu();
		void    _loadMaterials();
		void    _clearVectors();
		bool    _calcAnimation(tinygltf::Animation& anime, float time);
		glm::mat4   _processChanel(std::string& type, tinygltf::AnimationSampler& samp, float time);
		void    _loadMatrices(Joint *bone, glm::mat4 parentTransform);
	public:
		Gltf() = default;
		Gltf(Shader& shader, const char *path);
		Gltf(const Gltf & rhs);
		Gltf&   operator=(const Gltf & rhs);
		~Gltf();

		bool        loadFromFile(Shader& shader, const char *path);
		void        render(glm::mat4 matrix);
		void        simpleRender(glm::mat4 matrix);
		bool        loadAnimationMatrix(int animeType, float time);
	};
}