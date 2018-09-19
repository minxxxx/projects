#pragma once

#include <zion.h>
#include <fstream>
#include <unistd.h>

enum GAMESTATE
{
	MENU,
	PAUSE,
	GAME
};

class   MainGame;

struct  Func
{
	void    (*func)(MainGame*, std::vector<void *>);
	std::vector<void *> params;
};

class   MainGame
{
private:
	float           _width;
	float           _height;
	float           _fov;
	Zion::Window    _window;
	Zion::Camera    *_camera;
	GAMESTATE      _state = GAMESTATE::MENU;
	std::map<std::string, Zion::Shader *>      _shaders;
	std::map<std::string, Zion::Renderable *>  _models;
	std::map<std::string, Zion::Material *>    _materials;
	std::map<std::string, std::vector<std::string> *> _levelMaps;
public:
	static Zion::Renderer  renderer;
	static std::map<const char *, Func>   functions;
	static std::string          getNameFromPath(const char *path);
	static std::vector<std::string>     stringSplit(const std::string& s, const char c);
public:
	MainGame() = default;
	MainGame(float width, float height, float fov);
	MainGame(const MainGame & rhs);
	MainGame&  operator=(const MainGame & rhs);
	~MainGame() = default;

	bool    initGame(float width, float height, float fov);
	bool    initGame(GLFWwindow *window, float width, float height, float fov);
	void    setupGameCamera();
	void    setupGameCamera(glm::vec3 pos, float pitch, float yaw);
	bool    addShader(const char *name, const char *vertPath, const char *fragPath);
	bool    addModel(const char *name, Zion::Shader& shader, const char *path);
	bool    addMaterial(const char *name, const char *path);
	bool    addMap(const char *name, const char *path);
	void    loadResources();
	void    gameLoop();

	Zion::Window&               getGameWindow();
	Zion::Camera&               getGameCamera();
	Zion::Shader                *getShader(const std::string shaderName) const;
	Zion::Renderable            *getModel(const std::string modelName) const;
	Zion::Material              *getMaterial(const std::string materialName);
	std::vector<std::string>    *getMap(const std::string mapName);
	GAMESTATE                   getGameState();
	void                        setGameState(GAMESTATE state);
};

