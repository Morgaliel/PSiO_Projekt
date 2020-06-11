#ifndef CHARACTER_H
#define CHARACTER_H
#include <move.h>
#include <animation.h>


class Character:public sf::Sprite
{
public:
    Character();
    virtual ~Character();

    void setTexture(sf::Texture& texture);
    void createMove(const float speed);
    void createAnimation(sf::Texture& textureSheet);

    void setRow(unsigned int row);
    virtual void setPosition(const sf::Vector2f position);
    virtual void move(const sf::Vector2f direction,const float &deltaTime);

    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderWindow* window);

protected:
    sf::Sprite sprite;
    Move* movement;
    std::vector<Animation> animation;
    unsigned int row;

private:
    void initVariables();
};

#endif // CHARACTER_H
