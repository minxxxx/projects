#include <scene.hpp>

bool Scene::newGame(MainGame *game, std::string mapName)
{
	std::vector<std::string>    *map = game->getMap(mapName);
	if (map == nullptr)
		return false;
	_mapName = mapName;
	_game = game;
	for (std:: string& line : *map)
	{
		std::vector<std::string> strSplits = MainGame::stringSplit(line, ' ');
		if (strSplits[0] == std::string("FloorType"))
			_floorType = strSplits[1];
		else if (strSplits[0] == std::string("WallType"))
			_wallType = strSplits[1];
		else if (strSplits[0] == std::string("BreakType"))
			_breakableBlockType = strSplits[1];
		else if (strSplits[0] == std::string("UnbreakType"))
			_unbreakableBlockType = strSplits[1];
		else if (strSplits[0] == std::string("BgType"))
			_backgroundType = strSplits[1];
		else if (line[0] == 'R')
			_loadNewGameLine(line);
	}
	_addBackground();
	/// adding scene update to render loop functions
	std::vector<void *> params;
	params.push_back(this);
	MainGame::functions.insert(std::pair<const char *, Func>("sceneUpdate", {Scene::sceneUpdate, params}));
	return true;
}

void Scene::_loadNewGameLine(std::string &line)
{
	float x = GRID_START_X;
	int   gridX = 0;
	for (char c : line)
	{
		if (c == 'R')
			_addWall(x, z, gridX, gridY);
		else if (c == 'G')
			_addBreakableBlock(x, z, gridX, gridY);
		else if (c == 'L')
			_addUnbreakableBlock(x, z, gridX, gridY);
		else if (c == '@')
			_addPlayer(x, z);
		else if (c == 'E')
			_addEnemy(x, z);
		_addFloor(x, z);
		x += GRID_BLOCK_SIZE;
		gridX++;
	}
	z -= GRID_BLOCK_SIZE;
	gridY++;
}

bool Scene::loadGame(MainGame *game, std::string fileName)
{
	std::ifstream   save;
	std::string     line;

	_game = game;
	save.open(std::string("save/") + fileName, std::ios::in);
	if (!save.is_open())
		return false;
	while (std::getline(save, line))
	{
		std::vector<std::string> strSplits = MainGame::stringSplit(line, ' ');
		if (strSplits[0] == std::string("MapWidth"))
			_mapWidth = (size_t)atoi(strSplits[1].c_str());
		else if (strSplits[0] == std::string("MapHeight"))
			_mapLength = (size_t)atoi(strSplits[1].c_str());
		else if (strSplits[0] == std::string("MapName"))
			_mapName = strSplits[1];
		else if (strSplits[0] == std::string("BreakableBlockType"))
			_breakableBlockType = strSplits[1];
		else if (strSplits[0] == std::string("@"))
			_addPlayer((float)atof(strSplits[1].c_str()), (float)atof(strSplits[3].c_str()));
		else if (strSplits[0] == std::string("E"))
			_addEnemy((float)atof(strSplits[2].c_str()), (float)atof(strSplits[4].c_str()));
		else if (strSplits[0] == std::string("G"))
			_addBreakableBlock((float) atoi(strSplits[1].c_str()), (float) atoi(strSplits[3].c_str()),
			                   atoi(strSplits[5].c_str()), atoi(strSplits[4].c_str()));
	}
	if (_mapName.empty())
		return false;
	std::vector<std::string>    *map = game->getMap(_mapName);
	for (std:: string& line : *map)
	{
		std::vector<std::string> strSplits = MainGame::stringSplit(line, ' ');
		if (strSplits[0] == std::string("FloorType"))
			_floorType = strSplits[1];
		else if (strSplits[0] == std::string("WallType"))
			_wallType = strSplits[1];
		else if (strSplits[0] == std::string("UnbreakType"))
			_unbreakableBlockType = strSplits[1];
		else if (strSplits[0] == std::string("BgType"))
			_backgroundType = strSplits[1];
		else if (line[0] == 'R')
			_loadLoadGameLine(line);
	}
	_addBackground();
	/// adding scene update to render loop functions
	std::vector<void *> params;
	params.push_back(this);
	MainGame::functions.insert(std::pair<const char *, Func>("sceneUpdate", {Scene::sceneUpdate, params}));
	return true;
}

void Scene::_loadLoadGameLine(std::string &line)
{
	float x = GRID_START_X;
	int   gridX = 0;
	for (char c : line)
	{
		if (c == 'R')
			_addWall(x, z, gridX, gridY);
		else if (c == 'L')
			_addUnbreakableBlock(x, z, gridX, gridY);
		_addFloor(x, z);
		x += GRID_BLOCK_SIZE;
		gridX++;
	}
	z -= GRID_BLOCK_SIZE;
	gridY++;
}


bool Scene::saveGame(std::string fileName)
{
	std::ofstream   save;
	glm::vec3       pos;

	save.open(std::string("save/") + fileName, std::ios::out);
	if (!save.is_open())
		return false;
	save << "MapWidth " << _mapWidth << std::endl;
	save << "MapHeight " << _mapLength << std::endl;
	save << "MapName " << _mapName << std::endl;
	save << "BreakableBlockType " << _breakableBlockType << std::endl;
	pos = _player->getPosition();
	save << "@ " << pos.x << " " << pos.y << " " << pos.z << std::endl;
	for (std::pair<int, std::map<int, Block *>> pair : _blocks)
	{
		for (std::pair<int, Block *> block : pair.second)
		{
			if (block.second == nullptr)
				continue;
			if (!block.second->isBreakable())
				continue;
			pos = block.second->getPosition();
			save << "G " << pos.x << " " << pos.y << " " << pos.z << " " << pair.first << " " << block.first << std::endl;
		}
	}
	for (Player *enemy : _enemies)
	{
		pos = enemy->getPosition();
		save << "E " << enemy->modelType << " " << pos.x << " " << pos.y << " " << pos.z << std::endl;
	}
	save.close();
	return true;
}