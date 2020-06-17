#ifndef GSTATE_H
#define GSTATE_H
#include <resources.h>

static const float VIEW_HEIGHT=600.0f;

class GState:public Resources
{
public:
    GState(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~GState();

    void updateView();
    void updateInput(const float &deltaTime);
    void update(const float &deltaTime);
    void render(sf::RenderWindow* window);
private:
    sf::View* view;
    Player* player;
    Tilemap map;

    void initTextures();
    void initPlayer();
};

#endif // GSTATE_H
