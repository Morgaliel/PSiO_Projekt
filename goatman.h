#ifndef GOATMAN_H
#define GOATMAN_H

#include <enemy.h>

class Goatman:public Enemy
{
public:
    Goatman(sf::Vector2f position, std::map<std::string, sf::Texture> &textures);
    virtual ~Goatman();

    virtual void updateAttack();
    virtual void updateAnimation(const float &deltaTime);
    virtual void loseHP(const int hp, const float deltaTime);
    void update(const float &deltaTime);
private:
};

#endif // GOATMAN_H
