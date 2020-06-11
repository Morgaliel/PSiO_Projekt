#ifndef PLAYER_H
#define PLAYER_H
#include "animation.h"
#include "collider.h"
#include <character.h>

class Player:public Character
{
public:
    Player(sf::Vector2f position,std::map<std::string, sf::Texture> &textures);
    ~Player();

    //void Update(float deltaTime);
    void update(const float& deltaTime);


    Collider GetCollider();

    sf::Vector2f GetPosition();
private:

    void initVariables();
    void initComponents();
};

#endif // PLAYER_H
