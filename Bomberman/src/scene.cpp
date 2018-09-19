#include <scene.hpp>
#include <random>

Scene::Scene(const Scene &rhs)
{}

Scene& Scene::operator=(const Scene &rhs) { return *this; }

Scene::~Scene()
{
	for (int i = 0; i < _blocks.size(); i++)
	{
		for (int j = 0; j < _blocks[i].size(); j++)
			if (_blocks[i][j] != nullptr)
				delete _blocks[i][j];
	}
}

void Scene::_addBackground()
{
	glm::mat4 tmp = glm::translate(glm::mat4(), {0, -1.3, -5});
	tmp = glm::scale(tmp, {50, 50, 50});
	MainGame::renderer.addToRender("background", 0, _game->getModel(_backgroundType), tmp);
}

void Scene::_addWall(float x, float z, int xx, int yy)
{
	static int i = 0;

	glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(x, 0, z));
	Zion::Renderable *model = _game->getModel(_wallType);
	if (model != nullptr)
	{
		Block *block = new Block(i, "wall", false);
		_blocks[yy][xx] = block;
		_blocks[yy][xx]->setPosition(x, 0, z);
		MainGame::renderer.addToRender("wall", i, model, mat);
		i++;
	}
}


void Scene::_addPowerUps(float x, float z, int xx, int yy) {
    char powerUp[6] = {'F', 'G', 'B', 'O', 'O', 'O' };              // F - fire range B - Multiple bombs S - player speed increase
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 2);
    int randNbr = uniform_dist(e1);
    glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(x, 0, z));

    if (randNbr == 0 && !_endLevel) {
        Zion::Renderable *endLevel = _game->getModel("floor2");
        _endLevel = true;
        _blocks[yy][xx]->setEndMap(true);
        if (endLevel != nullptr)
        {
            glm::mat4 mat1 = glm::translate(glm::mat4(), glm::vec3(x, -1, z));
            MainGame::renderer.addToRender("endLevel", 0, endLevel, mat1);
        }
    }

    if (powerUp[randNbr] == 'F' && !_blocks[yy][xx]->getEndMap()) {
        _blocks[yy][xx]->setPowerName("PowerBombNbrInc");
        _blocks[yy][xx]->setPowerUp(true);
        glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.3f,0.3f,0.3f));
        mat = mat * scale;
        Zion::Renderable *present = _game->getModel("present");
        if (present != nullptr)
        {
            MainGame::renderer.addToRender("present", _blocks[yy][xx]->getId() , present, mat);
        }
    }

    if (powerUp[randNbr] == 'G' && !_blocks[yy][xx]->getEndMap()) {
        _blocks[yy][xx]->setPowerName("PowerBombExplosionInc");
        _blocks[yy][xx]->setPowerUp(true);
        Zion::Renderable *present = _game->getModel("lemon");
        if (present != nullptr)
        {
            MainGame::renderer.addToRender("lemon", _blocks[yy][xx]->getId() , present, mat);
        }
    }
	if (powerUp[randNbr] == 'B' && !_blocks[yy][xx]->getEndMap()) {
		_blocks[yy][xx]->setPowerName("PowerSpeed");
		_blocks[yy][xx]->setPowerUp(true);
		Zion::Renderable *present = _game->getModel("star");
		if (present != nullptr)
		{
			MainGame::renderer.addToRender("star", _blocks[yy][xx]->getId() , present, mat);
		}
	}


}
void Scene::_addBreakableBlock(float x, float z, int xx, int yy)
{
	static int i = 0;
    Block *block = new Block(i, "breakBlock", true);
    _blocks[yy][xx] = block;
    _blocks[yy][xx]->setPosition(x, 0, z);
    _addPowerUps(x, z, xx, yy);
    glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(x, 0, z));
    Zion::Renderable *breakableBlock = _game->getModel(_breakableBlockType);
	if (breakableBlock != nullptr)
	{
		MainGame::renderer.addToRender("breakBlock", i, breakableBlock, mat);
		i++;
	}
}

void Scene::_addUnbreakableBlock(float x, float z, int xx, int yy)
{
	static int i = 0;

	glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(x, 0, z));
	Zion::Renderable *model = _game->getModel(_unbreakableBlockType);
	if (model != nullptr)
	{
		Block *block = new Block(i, "unbreakBlock", false);
		_blocks[yy][xx] = block;
		_blocks[yy][xx]->setPosition(x, 0, z);
		MainGame::renderer.addToRender("unbreakBlock", i, model, mat);
		i++;
	}
}

void Scene::_addFloor(float x, float z)
{
	static int i = 0;
	Zion::Renderable *model;

	glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(x, -1, z));
	model = _game->getModel(_floorType);
	if (model != nullptr)
	{
		MainGame::renderer.addToRender("floors", i, model, mat);
		i++;
	}
}

void Scene::_addPlayer(float x, float z)
{
	Zion::Renderable *model;

	model = _game->getModel("bomberman");
	if (model != nullptr)
	{
		_player = new Player(0, "player");
		_player->setPosition(glm::vec3{x, 0, z});
		_player->scale(glm::vec3(0.3, 0.3, 0.3));
		_player->playerStart = glm::vec3(x, 0, z);
		MainGame::renderer.addToRender(_player->getType(), _player->getId(), model, _player->getTransformation());
	}

	glm::vec3 pos = _player->getPosition();
	_game->getGameCamera().setCameraPosition(glm::vec3(pos.x + 0, pos.y + 10, pos.z + 6));
	_game->getGameCamera().setCameraTarget(_player->getPosition());
	_game->getGameCamera().setCameraUp(glm::vec3(0, 1, 0));
}

void Scene::_addEnemy(float x, float z)
{
	Zion::Renderable *model;
	static int i = 0;

	model = _game->getModel("onile");
	if (model != nullptr)
	{
		std::string s = "enemy1";
		Player *enemy = new Player(i, s);
		enemy->modelType = "onile";
		_enemies.push_back(enemy);
		// _enemies.back()->setPosition(getGridx(x), 0, getGridy(z));
		_enemies.back()->setPosition(glm::vec3{getGridx(x), 0, getGridy(z)});
		// _enemies.back()->scale(glm::vec3(0.3, 0.3, 0.3));
		_enemies.back()->playerStart = glm::vec3(getGridx(x), 0, getGridy(z));
		MainGame::renderer.addToRender(_enemies.back()->getType(), _enemies.back()->getId(), model, _enemies.back()->getTransformation());
		i++;
	}
}

void Scene::_addBomb(float x, float z)
{
	static int i = 0;

	int newx = getWorldx(x);
	int newy = getWorldy(z);

	x = getGridx(x);
	z = getGridy(z);

	if (_blocks[newy][newx] != nullptr && _blocks[newy][newx]->getType() == "bomb") {
		return;
	}
	glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(x, 0, z));
	Zion::Renderable *model = _game->getModel("bomb");

	if (model != nullptr)
	{
		Block *block = new Block(i, "bomb", false);
		_blocks[newy][newx] = block;
		_blocks[newy][newx]->setPosition(x, 0, z);
		_bomb.emplace_back(_player->getPosition(), i);
		MainGame::renderer.addToRender("bomb", i, model, mat);
		i++;
	}
}

int Scene::getWorldx(float x) {
	return 	 std::abs(static_cast<int>(std::round((x - GRID_START_X) / (float)GRID_BLOCK_SIZE)));

}
int Scene::getWorldy(float y) {
	return  std::abs((int)std::round((y - GRID_START_Z) / (float)GRID_BLOCK_SIZE));
}


float Scene::getGridx(float x) {
	x = static_cast<float>(std::round(x / GRID_BLOCK_SIZE));
	return (x * (float)GRID_BLOCK_SIZE);
}
float Scene::getGridy(float z) {
	z = static_cast<float>(std::round(z / GRID_BLOCK_SIZE));
	return (z * (float)GRID_BLOCK_SIZE);
}

void Scene::sceneUpdate(MainGame *game, std::vector<void *> params)
{
	auto *scene = (Scene *)params[0];

	if (game->getGameState() == GAMESTATE::GAME)
	{
		if (Zion::Input::getKeyPressOnce(GLFW_KEY_ESCAPE))
		{
			std::cout << "paused" << std::endl;
			game->setGameState(GAMESTATE::PAUSE);
			return;
		}
		updateBomb(game, scene);
		updateEnemy(game, scene);
		updatePlayer(game, scene);
	}
}

bool Scene::enemyPlayerCollision(glm::vec3 pos, Scene *scene){
	int enemyX = scene->getWorldx(pos.x);
	int enemyY = scene->getWorldy(pos.z);

	int playerx = scene->getWorldx(scene->_player->getPosition().x);
	int playery = scene->getWorldy(scene->_player->getPosition().z);

	if (playery == enemyY && playerx == enemyX)
	{
		return true;
	}
	return false;
}

