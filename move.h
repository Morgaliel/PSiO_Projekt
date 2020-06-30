#ifndef MOVE_H
#define MOVE_H
#include <wall.h>
#include <tilemap.h>

class Move
{
public:
    Move(sf::Sprite& sprite,float speed);
    virtual ~Move();

    const sf::Vector2f &getVelocity() const;
    bool isStopped() const;

    void move(const sf::Vector2f direction, const float& deltaTime, unsigned int *row, int type);
    void update(const float& deltaTime);

private:
    sf::Sprite& sprite;
    float speed;
    sf::Vector2f velocity;

};

#endif // MOVE_H
