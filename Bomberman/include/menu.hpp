#pragma once

#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>
#include <nanogui/label.h>
#include <nanogui/textbox.h>
#include <nanogui/vscrollpanel.h>
#include <nanogui/checkbox.h>
#include <MainGame.hpp>
#include <scene.hpp>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

class   Menu
{
private:
	nanogui::Screen     *_screen;
	nanogui::Window     *_startMenu;
	nanogui::Window     *_newGameMenu;
	nanogui::Window     *_loadGameMenu;
	nanogui::Window     *_pauseGameMenu;
	nanogui::Window     *_exitWindow;
	nanogui::TextBox    *_newGameTextBox;
	nanogui::Window     *_gameSaved;
	MainGame            *_mainGame;
	Zion::SquareSprite  *_menuBg;
	Zion::SquareSprite  *_menuTitle;
	Scene               *_scene = nullptr;
	std::string         _saveFileName;
private:
	void    _createStartMenu(float width, float height);
	void    _createNewGameMenu(float width, float height);
	void    _createLoadGameMenu(float width, float height);
	void    _createPauseGameMenu(float width, float height);
	void    _createBackground(float width, float height);
	void    _createExitWindow(float width, float height);


public:
	Menu() = default;
	Menu(float width, float height, MainGame *mainGame, bool fullScreen = false, bool resizable = false);
	Menu(const Menu & rhs);
	Menu&   operator=(const Menu & rhs);
	~Menu() = default;

	bool    initMenu(float width, float height, MainGame *mainGame, bool fullScreen = false, bool resizable = false);
	bool    startMenu();
	bool    startGameMenu();
	bool    buildMenuWindows(float width, float height);

	GLFWwindow  *getGlfwWindow();
public:
	static Menu    *activeMenu;
	static void    updateMenu(MainGame *game, std::vector<void *> params);
	static void    exitButtonCallBack();
	/// creating callbacks for menu
	static bool     mouseCallback(int button, int action, int mod);
	static bool     cursorPositionCallback(int xpos, int ypos);
	static bool     keyCallback(int key, int scancode, int action, int mods);
};