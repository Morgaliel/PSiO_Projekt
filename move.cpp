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

void Move::move(const sf::Vector2f direction, const float& deltaTime, unsigned int *row, int type)
{


    if(type==0){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            *row=4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            *row=12;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            *row=8;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            *row=0;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            *row=2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            *row=14;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            *row=6;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            *row=10;
        }
    }
    else{
        if(direction.x==-1.0f&&direction.y==1.0f){
            *row=5;
        }
        else if(direction.x==1.0f&&direction.y==1.0f){
            *row=3;
        }
        else if(direction.x==-1.0f&&direction.y==-1.0f){
            *row=7;
        }
        else if(direction.x==1.0f&&direction.y==-1.0f){
            *row=1;
        }
        else if(direction.x==-1.0f){
            *row=6;
        }
        else if(direction.x==1.0f){
            *row=2;
        }
        else if(direction.y==-1.0f){
            *row=0;
        }
        else if(direction.y==1.0f){
            *row=4;
        }
    }

    this->velocity.x=this->speed*direction.x;
    this->velocity.y=this->speed*direction.y;


}

void Move::update(const float &deltaTime)
{

    this->sprite.move(this->velocity*deltaTime);
}
