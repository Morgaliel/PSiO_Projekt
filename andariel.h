#ifndef ANDARIEL_H
#define ANDARIEL_H

#include <enemy.h>

class Andariel:public Enemy
{
public:
    Andariel(sf::Vector2f position, std::map<std::string, sf::Texture> &textures);
    virtual ~Andariel();

    virtual void updateAttack();
    virtual void updateAnimation(const float &deltaTime);
    virtual void loseHP(const int hp, const float deltaTime);
    void update(const float &deltaTime);
};

#endif // ANDARIEL_H
