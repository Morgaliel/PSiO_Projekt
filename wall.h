#ifndef WALL_H
#define WALL_H
#include <SFML/Graphics.hpp>
#include "collider.h"


class Wall{
public:
    Wall(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);
    ~Wall();
    void Draw(sf::RenderWindow& window);
    Collider GetCollider();
private:
    sf::RectangleShape body;
};
#endif // WALL_H
