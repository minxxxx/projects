#include <block.hpp>

Block::Block(int id, std::string type, bool breakable) : NonStatic(id, type), _breakable(breakable)
{
    _id = id;
    _powerup = false;
    _endMap = false;
    _powerName = "";
    _collision = true;
}

void Block::setPosition(float x, float y, float z)
{
	translate(glm::vec3(x, y, z));
}

bool        Block::isBreakable()
{
    return _breakable;
}

int         Block::getId()
{
    return  _id;
}

void        Block::setPowerName(std::string name) {
    _powerName = name;
}
std::string Block::getPowerName() {
    return _powerName;
}
void        Block::setPowerUp(bool bol) {
    _powerup = bol;
}
void        Block::setEndMap(bool bol) {
    _endMap = bol;
}

bool 		Block::getEndMap() {
    return _endMap;
}

bool        Block::getPowerUp() {
    return _powerup;
}

bool        Block::getCollision() {
    return _collision;
}
void        Block::setCollision(bool collision) {
    _collision = collision;
}