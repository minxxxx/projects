#include <menu.hpp>

Menu*   Menu::activeMenu = nullptr;

Menu::Menu(float width, float height, MainGame *mainGame, bool fullScreen, bool resizable)
{
	initMenu(width, height, mainGame, fullScreen, resizable);
}

Menu::Menu(const Menu &rhs)
{
	*this = rhs;
}

Menu& Menu::operator=(const Menu &rhs)
{
	if (this != &rhs)
	{
		_screen = rhs._screen;
		_newGameMenu = rhs._newGameMenu;
		_startMenu = rhs._startMenu;
		_pauseGameMenu = rhs._pauseGameMenu;
		_mainGame = rhs._mainGame;
	}
	return *this;
}

bool Menu::initMenu(float width, float height, MainGame *mainGame, bool fullScreen, bool resizable)
{
	_mainGame = mainGame;
	Menu::activeMenu = this;
	_screen = new nanogui::Screen({width, height}, "Bomberman", resizable, fullScreen,
		8, 8, 24, 8, 4, 4, 1);
	_screen->setVisible(true);
	Zion::Input::mouseCallback2 = Menu::mouseCallback;
	Zion::Input::cursorPositionCallback2 = Menu::cursorPositionCallback;
	Zion::Input::keyCallback2 = Menu::keyCallback;
	std::vector<void *> params;
	params.push_back(this);
	MainGame::functions.insert(std::pair<const char *, Func>("menuUpdate", {Menu::updateMenu, params}));
	return true;
}

bool Menu::buildMenuWindows(float width, float height)
{
	_createStartMenu(width, height);
	_createNewGameMenu(width, height);
	_createPauseGameMenu(width, height);
	_createBackground(width, height);
	_createExitWindow(width, height);
	_createLoadGameMenu(width, height);
	//_screen->performLayout();
	return true;
}

void Menu::_createStartMenu(float width, float height)
{
	_startMenu = new nanogui::Window(_screen, "Menu");
	_startMenu->setLayout(new nanogui::GroupLayout());
	_startMenu->setWidth(250);
	_startMenu->setHeight(320);
	_startMenu->setVisible(true);
	_startMenu->center();
	/// new game button
	nanogui::Button *startButton = new nanogui::Button(_startMenu, "New Game");
	startButton->setPosition({50, 40});
	startButton->setSize({150, 50});
	startButton->setCallback([]{
		activeMenu->_startMenu->setVisible(false);
		activeMenu->_newGameMenu->setVisible(true);
	});
	/// load game button
	nanogui::Button *loadButton = new nanogui::Button(_startMenu, "Load Game");
	loadButton->setPosition({50, 110});
	loadButton->setSize({150, 50});
	loadButton->setCallback([]{
		activeMenu->_startMenu->setVisible(false);
		activeMenu->_loadGameMenu->setVisible(true);
	});
	/// options button
	nanogui::Button *optionsButton = new nanogui::Button(_startMenu, "Options");
	optionsButton->setPosition({50, 180});
	optionsButton->setSize({150, 50});
	/// exit button
	nanogui::Button *exitButton = new nanogui::Button(_startMenu, "Exit");
	exitButton->setPosition({50, 250});
	exitButton->setSize({150, 50});
	exitButton->setCallback([]{ Menu::exitButtonCallBack();});
}

void Menu::_createNewGameMenu(float width, float height)
{
	_newGameMenu = new nanogui::Window(_screen, "New Game");
	_newGameMenu->setLayout(new nanogui::GroupLayout());
	_newGameMenu->setWidth(250);
	_newGameMenu->setHeight(250);
	_newGameMenu->setVisible(false);
	_newGameMenu->center();
	/// label
	nanogui::Label *label = new nanogui::Label(_newGameMenu, "Enter Profile Name", "sans-bold", 20);
	label->setPosition({60, 40});
	label->setSize({200, 30});
	label->setColor({0.0f, 0.7f, 0.0f, 1.0f});
	/// textbox
	_newGameTextBox = new nanogui::TextBox(_newGameMenu, "");
	_newGameTextBox->setPosition({50, 80});
	_newGameTextBox->setSize({150, 50});
	_newGameTextBox->setEditable(true);
	/// start button
	nanogui::Button *start = new nanogui::Button(_newGameMenu, "Start");
	start->setPosition({50, 150});
	start->setSize({150, 30});
	start->setCallback([]{
		if ((activeMenu->_saveFileName = activeMenu->_newGameTextBox->value()) == std::string(""))
			return;
		activeMenu->_mainGame->setGameState(GAMESTATE::GAME);
		activeMenu->_newGameMenu->setVisible(false);
		activeMenu->_pauseGameMenu->setVisible(true);
		activeMenu->_scene = new Scene();
		activeMenu->_scene->newGame(activeMenu->_mainGame, "map2");
		activeMenu->_scene->saveGame(activeMenu->_saveFileName);
	});
	/// cancel button
	nanogui::Button *cancel = new nanogui::Button(_newGameMenu, "Cancel");
	cancel->setPosition({50, 200});
	cancel->setSize({150, 30});
	cancel->setBackgroundColor({0.8f, 0.0f, 0.0f, 1.0f});
	cancel->setCallback([]{
		activeMenu->_newGameMenu->setVisible(false);
		activeMenu->_startMenu->setVisible(true);
	});
}

void Menu::_createLoadGameMenu(float width, float height)
{
	_loadGameMenu = new nanogui::Window(_screen, "Load Game");
	_loadGameMenu->setLayout(new nanogui::GroupLayout());
	_loadGameMenu->setSize({width / 3, height / 3});
	_loadGameMenu->setVisible(false);
	_loadGameMenu->center();
	auto *panel = new nanogui::VScrollPanel(_loadGameMenu);
	panel->setSize({(width / 3) - 10, (height / 3) - 90});
	panel->setPosition({10, 35});
	auto *panelView = new nanogui::Window(panel, "");
	panelView->setLayout(new nanogui::BoxLayout(nanogui::Orientation::Vertical, nanogui::Alignment::Fill, 20, 5));
	panelView->setSize({(width / 3) - 10, (height / 3) - 90});
	panelView->setPosition({10, 35});

	DIR     *dir = opendir("save");
	struct dirent *file;
	if (dir)
	{
		int i = 0;
		while ((file = readdir(dir)))
		{
			if (file->d_name[0] == '.')
				continue;
			nanogui::Button *lab = new nanogui::Button(panelView, file->d_name);
			lab->setSize({(width / 3) - 30, 30});
			lab->setPosition({5, i * 33 + 3});
			lab->setCallback([lab]{
				std::cout << "load : " << lab->caption() << std::endl;
				activeMenu->_mainGame->setGameState(GAMESTATE::GAME);
				activeMenu->_loadGameMenu->setVisible(false);
				activeMenu->_pauseGameMenu->setVisible(true);
				activeMenu->_saveFileName = lab->caption();
				activeMenu->_scene = new Scene();
				activeMenu->_scene->loadGame(activeMenu->_mainGame, activeMenu->_saveFileName);
			});
			i++;
		}
	}else{
		perror("directory error");
	}
	closedir(dir);
	nanogui::Button *back = new nanogui::Button(_loadGameMenu, "back");
	back->setPosition({(width / 3) - 100, (height / 3) - 50});
	back->setSize({70, 30});
	back->setCallback([]{
		activeMenu->_loadGameMenu->setVisible(false);
		activeMenu->_startMenu->setVisible(true);
	});
}

void Menu::_createPauseGameMenu(float width, float height)
{
	_pauseGameMenu = new nanogui::Window(_screen, "Pause");
	_pauseGameMenu->setLayout(new nanogui::GroupLayout());
	_pauseGameMenu->setSize({250, 250});
	_pauseGameMenu->setVisible(false);
	_pauseGameMenu->center();
	/// game saved Window
	_gameSaved = new nanogui::Window(_screen, "");
	_gameSaved->setSize({250, 40});
	_gameSaved->setVisible(false);
	_gameSaved->setPosition({(width / 2) - 125, height - 100});
	nanogui::Label *saveLabel = new nanogui::Label(_gameSaved, "Game Saved", "sans", 25);
	saveLabel->setPosition({70, 5});
	saveLabel->setSize({150, 30});
	saveLabel->setColor({0.0f, 0.7f, 0.0f, 1.0f});
	/// resume game button
	nanogui::Button *resume = new nanogui::Button(_pauseGameMenu, "Resume");
	resume->setPosition({50, 50});
	resume->setSize({150, 50});
	resume->setCallback([]{
		activeMenu->_mainGame->setGameState(GAMESTATE::GAME);
		activeMenu->_gameSaved->setVisible(false);
	});
	/// save game button
	nanogui::Button *save = new nanogui::Button(_pauseGameMenu, "Save");
	save->setPosition({50, 120});
	save->setSize({150, 50});
	save->setCallback([]{
		activeMenu->_scene->saveGame(activeMenu->_saveFileName);
		activeMenu->_gameSaved->setVisible(true);
	});
	/// quit game button
	nanogui::Button *quit = new nanogui::Button(_pauseGameMenu, "Quit");
	quit->setPosition({50, 190});
	quit->setSize({150, 50});
	quit->setCallback([]{
		if (activeMenu->_scene != nullptr)
		{
			delete activeMenu->_scene;
			activeMenu->_screen->removeChild(activeMenu->_loadGameMenu);
			activeMenu->_screen->removeChild(activeMenu->_newGameMenu);
			//delete activeMenu->_loadGameMenu;
			activeMenu->_createNewGameMenu(activeMenu->_mainGame->getGameWindow().getWidth(),
			                               activeMenu->_mainGame->getGameWindow().getHeight());
			activeMenu->_createLoadGameMenu(activeMenu->_mainGame->getGameWindow().getWidth(),
			                                activeMenu->_mainGame->getGameWindow().getHeight());
			std::cout << "scene deleted" << std::endl;
			std::map<const char *, Func>::iterator it;
			it = MainGame::functions.find("sceneUpdate");
			MainGame::functions.erase(it);
			MainGame::renderer.removeAll();
			activeMenu->_gameSaved->setVisible(false);
		}
		activeMenu->_mainGame->setGameState(GAMESTATE::MENU);
		activeMenu->_pauseGameMenu->setVisible(false);
		activeMenu->_startMenu->setVisible(true);
		std::cout << "game quit" << std::endl;
	});
}

void Menu::_createExitWindow(float width, float height)
{
	_exitWindow = new nanogui::Window(_screen, "");
	_exitWindow->setLayout(new nanogui::GroupLayout());
	_exitWindow->setWidth(400);
	_exitWindow->setHeight(150);
	_exitWindow->setVisible(false);
	_exitWindow->center();
	/// text label
	nanogui::Label *label = new nanogui::Label(_exitWindow, "Do you want to exit game?", "sans", 30);
	label->setPosition({70, 20});
	label->setSize({300, 30});
	/// yes button
	nanogui::Button *yes = new nanogui::Button(_exitWindow, "Yes");
	yes->setSize({70, 30});
	yes->setPosition({80, 90});
	yes->setCallback([]{
		glfwSetWindowShouldClose(activeMenu->_screen->glfwWindow(), (int)true);
	});
	/// no button
	nanogui::Button *no = new nanogui::Button(_exitWindow, "No");
	no->setSize({70, 30});
	no->setPosition({250, 90});
	no->setCallback([]{
		activeMenu->_startMenu->setVisible(true);
		activeMenu->_exitWindow->setVisible(false);
	});
}

void Menu::_createBackground(float width, float height)
{
	glm::mat4 viewMatrix = _mainGame->getGameCamera().getViewMatrix();
	_mainGame->getShader("gui")->setUniformMat4((GLchar *)"view_matrix", viewMatrix);
	_menuBg = new Zion::SquareSprite(*_mainGame->getShader("gui"), 0, 0, 10, 6);
	_menuBg->addTextureFromFile("resource/images/menu_bg.jpg");
	_menuTitle = new Zion::SquareSprite(*_mainGame->getShader("gui"), 0, 0, 3, 1.5);
	_menuTitle->addTextureFromFile("resource/images/title1.png");
}

GLFWwindow* Menu::getGlfwWindow()
{
	return _screen->glfwWindow();
}

void Menu::updateMenu(MainGame *game, std::vector<void *> params)
{
	auto *menu = (Menu*)params[0];

	GAMESTATE state = menu->_mainGame->getGameState();

	if (state == GAMESTATE::MENU)
	{
		menu->_menuBg->render(glm::translate(glm::mat4(), {0, 0, -1}));
		menu->_menuTitle->render(glm::translate(glm::mat4(), {0, 1.4, 0}));
		menu->_screen->drawWidgets();
	}
	else if (state == GAMESTATE::PAUSE)
	{
		menu->_screen->drawWidgets();
	}
}

bool Menu::mouseCallback(int button, int action, int mod)
{
	if (activeMenu != nullptr)
		activeMenu->_screen->mouseButtonCallbackEvent(button, action, mod);
	return true;
}

bool Menu::cursorPositionCallback(int xpos, int ypos)
{
	if (activeMenu != nullptr)
		activeMenu->_screen->cursorPosCallbackEvent(xpos, ypos);
	return true;
}

bool Menu::keyCallback(int key, int scancode, int action, int mods)
{
	if (activeMenu != nullptr)
		activeMenu->_screen->keyCallbackEvent(key, scancode, action, mods);
	return true;
}

void Menu::exitButtonCallBack()
{
	activeMenu->_startMenu->setVisible(false);
	activeMenu->_exitWindow->setVisible(true);
}