#include "move.h"

Move::Move(sf::Sprite& sprite,float speed):sprite(sprite),speed(speed)
{
    this->speed=speed;
}

Move::~Move()
{

}

const sf::Vector2f &Move::getVelocity() const
{
    return this->velocity;
}

bool Move::isStopped() const
{
    if(this->velocity.x==0.0f && this->velocity.y==0.0f)
        return true;

    return false;
}

void Move::move(const sf::Vector2f direction, const float& deltaTime)
{
    this->velocity.x=this->speed*direction.x;
    this->velocity.y=this->speed*direction.y;


}

void Move::update(const float &deltaTime)
{

    this->sprite.move(this->velocity*deltaTime);
}
