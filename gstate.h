#ifndef GSTATE_H
#define GSTATE_H
#include <resources.h>

class GState:public Resources
{
public:
    GState(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~GState();

    void updateInput(const float &deltaTime);
    void update(const float &deltaTime);
    void render();
private:
    Player* player;

    void initTextures();
    void initPlayer();
};

#endif // GSTATE_H
