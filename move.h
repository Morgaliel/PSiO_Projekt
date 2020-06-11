#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <wall.h>
#include <tilemap.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Move
{
public:
    Move(sf::Sprite& sprite,float speed);
    virtual ~Move();

    const sf::Vector2f &getVelocity() const;
    bool isStopped() const;

    void move(const sf::Vector2f direction, const float& deltaTime);
    void update(const float& deltaTime);

private:
    sf::Sprite& sprite;
    float speed; //maxVelocity
    sf::Vector2f velocity;

};

#endif // MOVE_H
