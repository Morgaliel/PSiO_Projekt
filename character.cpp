#include "character.h"

void Character::initVariables()
{
    this->movement=nullptr;
}

Character::Character()
{
    this->initVariables();
}

Character::~Character()
{
    delete this->movement;
}

void Character::setTexture(sf::Texture &texture)
{
    this->sprite.setTexture(texture);
}


void Character::createMove(const float speed)
{
    this->movement = new Move(this->sprite,speed);
}

void Character::createAnimation(sf::Texture &textureSheet)
{
    //this->animation=new Animation(this->sprite,textureSheet);
    animation.emplace_back(Animation(this->sprite,textureSheet));
}

void Character::setRow(unsigned int row)
{
    this->row=row;
}

void Character::setPosition(const sf::Vector2f position)
{
        this->sprite.setPosition(position.x,position.y);
}

void Character::move(const sf::Vector2f direction,const float &deltaTime)
{
    if(this->movement){
        this->movement->move(direction, deltaTime); //sets velocity
    }
}

void Character::update(const float &deltaTime)
{

}

void Character::render(sf::RenderWindow* window)
{
    window->draw(this->sprite);
}


