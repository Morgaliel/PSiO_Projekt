#ifndef PLAYER_H
#define PLAYER_H
#include <animation.h>
#include <character.h>

class Player:public Character
{
public:
    Player(sf::Vector2f position,std::map<std::string, sf::Texture> &textures);
    ~Player();

    virtual void loseHP(const int hp, const float deltaTime);
    virtual void gainHP(const int hp);
    void updateAttack();
    void updateAnimation(const float& deltaTime);
    void update(const float& deltaTime);
    bool getAtck();
    bool getAttacking();

private:
    int one=0;

    void initVariables();
    void initComponents();
};

#endif // PLAYER_H
