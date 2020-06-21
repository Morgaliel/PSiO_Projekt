#ifndef GOATMAN_H
#define GOATMAN_H

#include <enemy.h>

class Goatman:public Enemy
{
public:
    Goatman(sf::Vector2f position, std::map<std::string, sf::Texture> &textures);
    virtual ~Goatman();

    virtual void loseHP(const int hp);
    void update(const float &deltaTime);
private:
    bool isAttacking=false;
};

#endif // GOATMAN_H
