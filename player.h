#ifndef PLAYER_H
#define PLAYER_H
#include <animation.h>
#include <character.h>

class Player:public Character
{
public:
    Player(sf::Vector2f position,std::map<std::string, sf::Texture> &textures);
    ~Player();

    void updateAttack();
    void updateAnimation(const float& deltaTime);
    void update(const float& deltaTime);

    //Collider GetCollider();
    //sf::Vector2f GetPosition();
private:
    bool isAttacking;

    void initVariables();
    void initComponents();
};

#endif // PLAYER_H
