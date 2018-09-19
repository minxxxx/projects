//
// Created by Tony MACK on 2017/08/29.
//

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "../include/player.hpp"

#ifndef GAME_BOMB_HPP
#define GAME_BOMB_HPP

class Bomb {
private:
    glm::vec3   _position;
    glm::vec2   _direction;
    float       _time;
    int         _id;
    bool        _exploded;
    bool        _explosionRemoved;
public:
    Bomb(glm::vec3  position, int id);
    virtual         ~Bomb();
    bool            explodeTime();
    bool            removeExplosionTime();
    void            draw();
    float           getTime() const;
    int             getId() const;
    glm::vec3       getPosition() const;
    bool            getExploded();
    void            setExploded(bool exploded);
    void            setExplosionRemoved(bool explosionRemoved);
    bool            getExplosionRemoved();

};

#endif //GAME_BOMB_HPP
