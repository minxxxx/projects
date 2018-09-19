#include <scene.hpp>

void Scene::bombExplode(Scene *scene, const Bomb &bomb) {

    int x = scene->getWorldx(bomb.getPosition().x);
    int y = scene->getWorldy(bomb.getPosition().z);

    bool r = true, l = true, u = true, d = true;
    for (int i = 0; i <= scene->_player->getPowerExplosion(); ++i) {

        if (scene->_blocks[y - 1 - i][x] != nullptr && scene->_blocks[y - 1 - i][x]->isBreakable() && d) {
            d = false;
            MainGame::renderer.removeFromRender("breakBlock", scene->_blocks[y - 1 - i][x]->getId());
            scene->_blocks[y - 1 - i][x]->setCollision(false);
        }
        if (scene->_blocks[y + 1 + i][x] != nullptr && scene->_blocks[y + 1 + i][x]->isBreakable() && u) {
            u = false;
            MainGame::renderer.removeFromRender("breakBlock", scene->_blocks[y + 1 + i][x]->getId());
            scene->_blocks[y + 1 + i][x]->setCollision(false);
        }
        if (scene->_blocks[y][x - 1 - i] != nullptr && scene->_blocks[y][x - 1 - i]->isBreakable() && l) {
            l = false;
            MainGame::renderer.removeFromRender("breakBlock", scene->_blocks[y][x - 1 - i]->getId());
            scene->_blocks[y][x - 1 - i]->setCollision(false);
        }
        if (scene->_blocks[y][x + 1 + i] != nullptr && scene->_blocks[y][x + 1 + i]->isBreakable() && r) {
            r = false;
            MainGame::renderer.removeFromRender("breakBlock", scene->_blocks[y][x + 1 + i]->getId());
            scene->_blocks[y][x + 1 + i]->setCollision(false);
        }
    }
}

void Scene::renderExplosion(Scene *scene, const Bomb &bomb, MainGame *game) {
    int x = scene->getGridx(bomb.getPosition().x);
    int y = scene->getGridy(bomb.getPosition().z);

    int xx = scene->getWorldx(bomb.getPosition().x);
    int yy = scene->getWorldy(bomb.getPosition().z);

    bool r = true, l = true, u = true, d = true;
    Zion::Renderable *model;

    model = game->getModel("explosion");

    for (int i = 0; i < 1 + scene->_player->getPowerExplosion(); ++i ) {
            glm::mat4 middle = glm::translate(glm::mat4(), glm::vec3(x, 0, y));
            glm::mat4 matup = glm::translate(glm::mat4(), glm::vec3(x, 0,  y - ((i + 1) * GRID_BLOCK_SIZE)));
            glm::mat4 matdown = glm::translate(glm::mat4(), glm::vec3(x, 0,  y + (i + 1) * GRID_BLOCK_SIZE));
            glm::mat4 matleft = glm::translate(glm::mat4(), glm::vec3(x - ((i + 1)  * GRID_BLOCK_SIZE), 0,  y));
            glm::mat4 matright = glm::translate(glm::mat4(), glm::vec3(x + (i + 1) * GRID_BLOCK_SIZE, 0,  y));
        if (model != nullptr)
        {
                MainGame::renderer.addToRender("explosion", bomb.getId() , model, middle);
            if (u)
                MainGame::renderer.addToRender("explosion1", bomb.getId() + i , model, matup);
            if (d)
                MainGame::renderer.addToRender("explosion2", bomb.getId() + i , model, matdown);
            if (l)
                MainGame::renderer.addToRender("explosion3", bomb.getId() + i , model, matleft);
            if (r)
                MainGame::renderer.addToRender("explosion4", bomb.getId() + i , model, matright);
            if (scene->_blocks[yy - 1 - i][xx] != nullptr && d) {
                d = false;
            }
            if (scene->_blocks[yy + 1 + i][xx] != nullptr && u) {
                u = false;
            }
            if (scene->_blocks[yy][xx - 1 - i] != nullptr && l) {
                l = false;
            }
            if (scene->_blocks[yy][xx + 1 + i] != nullptr && r) {
                r = false;
            }
        }
    }
}