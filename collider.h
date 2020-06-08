#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>
#include <cmath>


class Collider{
public:
    Collider(sf::RectangleShape& body);
    ~Collider();;

    void Move(float dx, float dy);
    bool CheckCollision(Collider& other, float push);

    sf::Vector2f GetPosition();
    sf::Vector2f GetHalfSize();
private:
    sf::RectangleShape& body;
};

#endif // COLLIDER_H
