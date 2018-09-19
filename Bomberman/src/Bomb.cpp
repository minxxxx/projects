//
// Created by Tony MACK on 2017/08/29.
//


#include <Bomb.hpp>

Bomb::Bomb(glm::vec3 position, int id) :
        _position(position), _id(id), _exploded(false), _explosionRemoved(false)
{
    _time = static_cast<float>(glfwGetTime());
}

Bomb::~Bomb() {}

float       Bomb::getTime() const{
    return _time;
}

bool    Bomb::getExploded() {
    return _exploded;
}

bool        Bomb::explodeTime(){
    return glfwGetTime() - _time > 1.5;
}

bool        Bomb::removeExplosionTime(){
    return glfwGetTime() - _time > 2.5 ;//&& glfwGetTime() - _time < 2.6;
}

int         Bomb::getId() const
{
    return _id;
}

glm::vec3   Bomb::getPosition() const
{
    return _position;
}

void        Bomb::setExploded(bool exploded) {
    _exploded = exploded;
}

void        Bomb::setExplosionRemoved(bool explosionRemoved) {
    _explosionRemoved = explosionRemoved;
}
bool        Bomb::getExplosionRemoved() {
    return _explosionRemoved;
}