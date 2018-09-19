#include <renderable.hpp>
#include <zion.h>

namespace Zion
{
	Renderer::Renderer(const Renderer &rhs)
	{
		*this = rhs;
	}

	Renderer& Renderer::operator=(const Renderer &rhs)
	{
		return *this;
	}

	Renderer::~Renderer()
	{
		_objects.clear();
	}

	void Renderer::addToRender(std::string type, int id, Renderable *model, glm::mat4 mat)
	{
		_objects[type].push_back({id, 0.0f, 0, false, model, mat});
	}

	void Renderer::render()
	{
		for (std::pair<std::string, std::vector<RendererObj>> pair : _objects)
		{
            if (!pair.first.compare("endLevel"))
                _renderStatic(pair.second);
			if (!pair.first.compare("star"))
                _renderStatic(pair.second);
			if (!pair.first.compare("lemon"))
				_renderStatic(pair.second);
			if (!pair.first.compare("present"))
				_renderStatic(pair.second);
			if (!pair.first.compare("wall"))
				_renderStatic(pair.second);
			if (!pair.first.compare("unbreakBlock"))
				_renderStatic(pair.second);
			if (!pair.first.compare("background"))
				_renderStatic(pair.second);
			if (!pair.first.compare("floors"))
				_renderStatic(pair.second);
            if (!pair.first.compare("explosion"))
                _renderStatic(pair.second);
			if (!pair.first.compare("explosion1"))
				_renderStatic(pair.second);
			if (!pair.first.compare("explosion2"))
				_renderStatic(pair.second);
			if (!pair.first.compare("explosion3"))
				_renderStatic(pair.second);
			if (!pair.first.compare("explosion4"))
				_renderStatic(pair.second);
			if (!pair.first.compare("player"))
				_renderStatic(pair.second);
			if (!pair.first.compare("bomb"))
				_renderStatic(pair.second);
			if (!pair.first.compare("breakBlock"))
				_renderStatic(pair.second);
			if (!pair.first.compare("enemy1"))
				_renderAnime(pair.second, pair.first);
		}
	}

	void Renderer::_renderStatic(std::vector<RendererObj> &objects)
	{
		if (objects.empty())
			return;
		auto *model = (Zion::Gltf *)objects[0].model;
		model->enableShader();
		model->loadMaterialToShader();
		/// rendering
		for (RendererObj& obj : objects)
			obj.model->simpleRender(obj.matrix);
		model->unloadMaterialFromShader();
		model->disableShader();
	}

	void Renderer::_renderAnime(std::vector<RendererObj> &objects, std::string type)
	{
		if (objects.empty())
			return;
		auto *model = (Zion::Gltf *)objects[0].model;
		model->enableShader();
		model->loadMaterialToShader();
		model->enableAnimeInShader();
		/// rendering
		for (RendererObj& obj : objects)
		{
			model->loadAnimationMatrix(obj.animeType, obj.animeTime);
			obj.model->simpleRender(obj.matrix);
			increaseAnimeTime(type, obj.id, 0.008f);
		}
		model->unloadMaterialFromShader();
		model->disableShader();
	}

	void Renderer::removeFromRender(std::string type, int id)
	{
		int     pos = 0;
		try {
			std::vector<RendererObj>& objects = _objects[type];
			for (RendererObj obj : objects)
			{
				if (obj.id == id)
				{
					objects.erase(objects.begin() + pos);
					return;
				}
				pos++;
			}
		} catch (const std::out_of_range& oor) {
			return;
		}
	}

	void Renderer::removeGroup(std::string type)
	{
		std::map<std::string, std::vector<RendererObj>>::iterator it;

		it = _objects.find(type);
		if (it != _objects.end())
			_objects.erase(it);
	}

	void Renderer::removeAll()
	{
		for (std::pair<std::string, std::vector<RendererObj>> pair : _objects)
			pair.second.clear();
		_objects.clear();
	}

	void Renderer::applyTransformationToRenderable(std::string type, int id, glm::mat4 mat)
	{
		try {
			std::vector<RendererObj>& objects = _objects[type];
			for (RendererObj& obj : objects)
			{
				if (obj.id == id)
				{
					obj.matrix = mat;
					return;
				}
			}
		} catch (const std::out_of_range& oor) {
			return;
		}
	}

	void Renderer::increaseAnimeTime(std::string& type, int id, float val)
	{
		try {
			std::vector<RendererObj>& objects = _objects[type];
			for (RendererObj& obj : objects)
			{
				if (obj.id == id)
				{
					obj.animeTime += val;
					return;
				}
			}
		}catch (const std::out_of_range& oor) {
			return;
		}
	}
}