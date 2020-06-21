#ifndef ENEMY_H
#define ENEMY_H
#include <character.h>

class Enemy:public Character
{
public:
    Enemy(sf::Vector2f position, std::map<std::string, sf::Texture> &textures);
    virtual ~Enemy();

    //void updateAttack();
    //void updateAnimation(const float &deltaTime);
    void update(const float &deltaTime);

private:
    bool isAttacking=false;
};

#endif // ENEMY_H
