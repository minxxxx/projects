#include <iostream>
#include <MainGame.hpp>
#include <menu.hpp>

void    checkKeys(MainGame *game, std::vector<void *> params)
{
	if (game->getGameWindow().isKeyPressed(GLFW_KEY_UP))
		game->getGameCamera().changeCameraYPos(2.5);
	if (game->getGameWindow().isKeyPressed(GLFW_KEY_DOWN))
		game->getGameCamera().changeCameraYPos(-2.5f);
	if (game->getGameWindow().isKeyPressed(GLFW_KEY_LEFT))
		game->getGameCamera().changeCameraXPos(-2.5f);
	if (game->getGameWindow().isKeyPressed(GLFW_KEY_RIGHT))
		game->getGameCamera().changeCameraXPos(2.5f);
	if (game->getGameWindow().isKeyPressed(GLFW_KEY_PAGE_UP))
		game->getGameCamera().changeCameraZPos(-2.5f);
	if (game->getGameWindow().isKeyPressed(GLFW_KEY_PAGE_DOWN))
		game->getGameCamera().changeCameraZPos(2.5f);
}

int     main(int ac, char **av)
{
	MainGame    game;
	Menu        menu;

	nanogui::init();
	menu.initMenu(1280.0f, 760.0f, &game, false);
	game.initGame(menu.getGlfwWindow(), 1280.0f, 760.0f, 70.0f);
	menu.buildMenuWindows(1280.0f, 760.0f);
	srand(time(NULL));

	MainGame::functions.insert(std::pair<const char *, Func>("checkKeys", {checkKeys, std::vector<void *>()}));
	game.gameLoop();
	nanogui::shutdown();
	return 0;
}