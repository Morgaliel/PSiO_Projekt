#ifndef GSTATE_H
#define GSTATE_H
#include <resources.h>
#include <playergui.h>
#include <enemy.h>
#include <goatman.h>
#include <andariel.h>
#include <skeleton.h>
#include <object.h>

static const float VIEW_HEIGHT=600.0f;

class GState:public Resources
{
public:
    GState(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~GState();

    void updateCombat(const float &deltaTime);
    void updateView();
    void updateInput(const float &deltaTime);
    void update(const float &deltaTime);
    void render(sf::RenderWindow* window);
    float potionTimer;
private:
    sf::View* view;
    Player* player;
    std::vector<Enemy*> enemies;
    std::vector<Object*> objects;
    Enemy* enemy;
    PlayerGUI* playerGUI;
    std::vector<PlayerGUI*> enemyGUI;
    std::map<std::string,Tilemap*> maps;
    sf::Texture textureWall;
    std::vector<Wall*>walls;
    std::vector<Wall*>teleport;
    sf::Music music;
    float oneSecond;

    void initTextures();
    void initObjects();
    void initMaps();
};

#endif // GSTATE_H
