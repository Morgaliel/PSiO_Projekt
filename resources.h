#ifndef RESOURCES_H
#define RESOURCES_H
#include <player.h>


class Resources
{
public:
    Resources(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~Resources();

    const bool& getEnd() const; //getquit
    void endLayer(); //endState

    virtual void updateMousePos();
    virtual void updateInput(const float& deltaTime)=0;
    virtual void update(const float& deltaTime)=0;
    virtual void render()=0;
protected:
    std::stack<Resources*>* layers;
    std::map<std::string, sf::Texture> textures;
    sf::RenderWindow* window;
    bool end;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

};

#endif // RESOURCES_H
