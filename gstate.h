#ifndef GSTATE_H
#define GSTATE_H
#include <resources.h>

class GState:public Resources
{
public:
    GState(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~GState();

    void endLayer();
    void updateInput(const float &deltaTime);
    void update(const float &deltaTime);
    void render();
private:

};

#endif // GSTATE_H
