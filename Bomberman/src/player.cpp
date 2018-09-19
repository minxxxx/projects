#include <player.hpp>

Player::Player(int id, std::string type) : NonStatic(id, type){
  	_direction = 'U';
	_powerBombExplosion = 0;
	_powerBombNumber = 0;
	_powerSpeed = 0;
}

void Player::incBombExplosion() {
	_powerBombExplosion++;
}

void Player::incBombNbr(){
	_powerBombNumber++;
}

void Player::incBombSpeed(){
	_powerSpeed += 0.005f;
}

void Player::setPosition(glm::vec3 pos)
{
	_pos = pos;
	translate(_pos);
}

void Player::changePosX(float val)
{
	_pos.x += val;
	translate(_pos);
}
void Player::changePosY(float val)
{
	_pos.y += val;
	translate(_pos);
}
void Player::changePosZ(float val)
{
	_pos.z += val;
	translate(_pos);
}

void Player::reset() {
    _pos = playerStart;
    translate(playerStart);
}

char Player::setDirection(char c) {
    _direction = c;
	return c;
}

char Player::getDirection() {
    return  _direction;
}

int			Player::getPowerExplosion() {
	return _powerBombExplosion;
}
int			Player::getPowerBombNbr() {
	return _powerBombNumber;
}
float			Player::getPowerSpeed() {
	return _powerSpeed;
}
