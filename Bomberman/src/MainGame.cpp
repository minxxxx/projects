#include <MainGame.hpp>

Zion::Renderer  MainGame::renderer;
std::map<const char *, Func>    MainGame::functions;

std::string MainGame::getNameFromPath(const char *path)
{
	std::string str = std::string(path);
	std::size_t found = str.find_last_of((char *)"/");
	if (found == std::string::npos)
		return str;
	return str.substr(found+1);
}

MainGame::MainGame(float width, float height, float fov)
{
	initGame(width, height, fov);
}

MainGame::MainGame(const MainGame &rhs) { *this = rhs; }

MainGame& MainGame::operator=(const MainGame &rhs)
{
	return *this;
}

bool MainGame::initGame(GLFWwindow *window, float width, float height, float fov)
{
	glm::mat4       projectionMatrix;

	_window.initWindow(window, "Bomberman", (int)width, (int)height);
	/// Calculating perspective
	projectionMatrix = glm::perspective(glm::radians(fov), width / height, 0.1f, 1000.0f);
	/// Loading Shaders
	if (addShader("basic", "shaders/basic.vert", "shaders/basic.frag"))
		getShader("basic")->setUniformMat4((GLchar *)"proj_matrix", projectionMatrix);
	if (addShader("gui", "shaders/gui.vert", "shaders/basic.frag"))
		getShader("gui")->setUniformMat4((GLchar *)"proj_matrix", projectionMatrix);
	if (addShader("anime", "shaders/anime.vert", "shaders/basic.frag"))
		getShader("anime")->setUniformMat4((GLchar *)"proj_matrix", projectionMatrix);
	/// setup default camera
	setupGameCamera();
	/// load resources
	loadResources();
	return true;
}

bool MainGame::initGame(float width, float height, float fov)
{
	glm::mat4       projectionMatrix;

	srand(time(NULL));
	/// Creating glfw window
	_width = width;
	_height = height;
	_fov = fov;
	_window.initWindow("Bomberman", (int)width, (int)height);
	/// Calculating perspective
	projectionMatrix = glm::perspective(glm::radians(fov), width / height, 0.1f, 1000.0f);
	/// Loading Shaders
	if (addShader("basic", "shaders/basic.vert", "shaders/basic.frag"))
		getShader("basic")->setUniformMat4((GLchar *)"proj_matrix", projectionMatrix);
	if (addShader("gui", "shaders/gui.vert", "shaders/basic.frag"))
		getShader("gui")->setUniformMat4((GLchar *)"proj_matrix", projectionMatrix);
	if (addShader("anime", "shaders/anime.vert", "shaders/basic.frag"))
		getShader("anime")->setUniformMat4((GLchar *)"proj_matrix", projectionMatrix);
	/// setup default camera
	setupGameCamera();
	/// load resources
	loadResources();
	return true;
}

void MainGame::setupGameCamera()
{
	_camera = new Zion::Camera(glm::vec3(0, 0, 3));
}

void MainGame::setupGameCamera(glm::vec3 pos, float pitch, float yaw)
{
	_camera = new Zion::Camera(pos, pitch, yaw);
}

bool MainGame::addShader(const char *name, const char *vertPath, const char *fragPath)
{
	auto *shader = new Zion::Shader(vertPath, fragPath);
	_shaders.insert(std::pair<std::string, Zion::Shader *>(std::string(name), shader));
	return true;
}

bool MainGame::addModel(const char *name, Zion::Shader& shader, const char *path)
{
	auto *model = new Zion::Gltf(shader, path);
	_models.insert(std::pair<std::string, Zion::Renderable *>(std::string(name), model));
	return true;
}

bool MainGame::addMaterial(const char *name, const char *path)
{
	auto *material = new Zion::Material();
	material->texure.loadTextureFromPath(path);
	_materials.insert(std::pair<std::string, Zion::Material *>(std::string(name), material));
	return true;
}

bool MainGame::addMap(const char *name, const char *path)
{
	std::ifstream   file;
	std::string     line;

	file.open(path);
	if (file.fail())
	{
		std::cout << "Failed to load map : " << name << std::endl;
		return false;
	}
	auto *map = new std::vector<std::string>();
	while (std::getline(file, line))
		map->push_back(line);
	_levelMaps.insert(std::pair<std::string, std::vector<std::string> *>(std::string(name), map));
	return true;
}

void MainGame::loadResources()
{
	addModel("block1", *getShader("basic"), "resource/models/blocks/block1.gltf");
	addModel("explosion", *getShader("basic"), "resource/models/blocks/block1.gltf");
	addModel("block2", *getShader("basic"), "resource/models/blocks/block2.gltf");
	addModel("block3", *getShader("basic"), "resource/models/blocks/block3.gltf");
	addModel("bomb", *getShader("basic"), "resource/models/blocks/bomb.gltf");
	addModel("floor1", *getShader("basic"), "resource/models/blocks/floor1.gltf");
	addModel("floor2", *getShader("basic"), "resource/models/blocks/ManHole.gltf");
	addModel("bomberman", *getShader("basic"), "resource/models/bomberman/bomberman.gltf");
	addModel("onile", *getShader("anime"), "resource/models/bomberman/Onile.glb");
    addModel("lavaBackground", *getShader("basic"), "resource/models/bomberman/lavaBackground.gltf");
	addMap("map1", "resource/maps/map1");
	addMap("map2", "resource/maps/map2");

    addModel("present", *getShader("basic"), "resource/models/blocks/present.gltf");
    addModel("lemon", *getShader("basic"), "resource/models/blocks/lemon.gltf");
    addModel("star", *getShader("basic"), "resource/models/blocks/star.gltf");

    addMap("map1", "resource/maps/map1");
	addModel("enemy1", *getShader("basic"), "resource/models/enemies/enemy2.gltf");
	auto *mat = new Zion::Material();
	mat->texure.loadTextureFromPath("resource/models/bomberman/OnileDiffuseColor.png");
	auto *onileModel = (Zion::Model *)getModel("onile");
	onileModel->addMaterial(0, *mat);
}

void MainGame::gameLoop()
{
	glm::mat4   viewMatrix;
	glm::vec3   viewPos;

	Zion::Renderable::startTime = (float)glfwGetTime();
	Zion::Renderable::runTime = Zion::Renderable::startTime;
	while (!_window.shouldClose())
	{
		auto currentTime = (float)glfwGetTime();
		Zion::Renderable::deltaTime = currentTime - Zion::Renderable::runTime;
		Zion::Renderable::runTime = currentTime;

		_window.clearWindow(0.3f, 0.3f, 0.3f, 1.0f);
		/// calling all functions for loop
		for (std::pair<const char *, Func> func : functions)
		{
			if (!(bool)std::strcmp(func.first, "sceneUpdate"))
				func.second.func(this, func.second.params);
		}
		viewMatrix = _camera->getViewMatrix();
		viewPos = _camera->getCameraPosition();
		for (std::pair<std::string, Zion::Shader *> shader : _shaders)
		{
			if (!shader.first.compare("gui"))
				continue;
			shader.second->setUniformMat4((GLchar *)"view_matrix", viewMatrix);
			shader.second->setUniform3f((GLchar *)"viewPos", viewPos);
		}
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		MainGame::renderer.render();
		/// render and update nanogui menu
		functions["menuUpdate"].func(this, functions["menuUpdate"].params);
		_window.updateWindow();
		Zion::Input::updateKeys();
	}
}

Zion::Window& MainGame::getGameWindow() { return _window; }

Zion::Camera& MainGame::getGameCamera() { return *_camera; }

Zion::Shader* MainGame::getShader(const std::string shaderName) const
{
	Zion::Shader *shader;
	try {
		shader = _shaders.at(shaderName);
	}catch (const std::out_of_range& oor){
		return nullptr;
	}
	return shader;
}

Zion::Renderable* MainGame::getModel(const std::string modelName) const
{
	Zion::Renderable *model;
	try {
		model = _models.at(modelName);
	}catch (const std::out_of_range& oor){
		return nullptr;
	}
	return model;
}

Zion::Material* MainGame::getMaterial(const std::string materialName)
{
	Zion::Material *material;
	try {
		material = _materials.at(materialName);
	}catch (const std::out_of_range& oor){
		return nullptr;
	}
	return material;
}

std::vector<std::string>* MainGame::getMap(const std::string mapName)
{
	std::vector<std::string>    *map;
	try {
		map = _levelMaps.at(mapName);
	}catch (const std::out_of_range& oor){
		return nullptr;
	}
	return map;

}

GAMESTATE MainGame::getGameState()
{
	return _state;
}

void MainGame::setGameState(GAMESTATE state)
{
	_state = state;
}

std::vector<std::string> MainGame::stringSplit(const std::string &s, const char c)
{
	std::string buff{""};
	std::vector<std::string> v;

	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);

	return v;
}