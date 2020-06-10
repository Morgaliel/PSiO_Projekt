#include "character.h"

Character::Character()
{
    this->shape.setSize(sf::Vector2f(50.0f,50.0f));
    this->speed=100.0f;
}

Character::~Character()
{

}

void Character::move(const float &deltaTime, const float dir_x, const float dir_y)
{
    //mam to rozwiązane lepiej w playerze!
    this->shape.move(dir_x*this->speed*deltaTime,dir_y*this->speed*deltaTime);
}
