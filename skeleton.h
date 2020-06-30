#ifndef SKELETON_H
#define SKELETON_H

#include <enemy.h>

class Skeleton:public Enemy
{
public:
    Skeleton(sf::Vector2f position, std::map<std::string, sf::Texture> &textures);
    virtual ~Skeleton();

    virtual void updateAttack();
    virtual void updateAnimation(const float &deltaTime);
    virtual void loseHP(const int hp, const float deltaTime);
    void update(const float &deltaTime);
};

#endif // SKELETON_H
