#include "character.h"

void Character::initVariables()
{
    this->hitbox=nullptr;
    this->movement=nullptr;
}

Character::Character()
{
    this->initVariables();
}

Character::~Character()
{
    delete this->hitbox;
    delete this->hitboxAttack;
    delete this->movement;
}

void Character::setTexture(sf::Texture &texture)
{
    this->sprite.setTexture(texture);
}

void Character::createHitbox(sf::Sprite &sprite,sf::FloatRect position,int which)
{
    if(which==1){
        this->hitbox=new Hitbox(sprite,position);
    }else if(which==2){
        this->hitboxAttack=new Hitbox(sprite,position);
    }
}


void Character::createMove(const float speed)
{
    this->movement = new Move(this->sprite,speed);
}

void Character::createAnimation(sf::Texture &textureSheet)
{
    animation.emplace_back(Animation(this->sprite,textureSheet));
}

void Character::setRow(unsigned int row)
{
    this->row=row;
}

unsigned int Character::getRow()
{
    return row;
}

void Character::setPosition(const sf::Vector2f position)
{
    this->sprite.setPosition(position.x,position.y);
}

const sf::Vector2f &Character::getPosition() const
{
    return this->sprite.getPosition();
}

void Character::move(const sf::Vector2f direction,const float &deltaTime)
{
    if(this->movement){
        this->movement->move(direction, deltaTime, &row, type); //sets velocity
    }
}

void Character::update(const float &deltaTime)
{

}

void Character::render(sf::RenderWindow& window)
{
    window.draw(this->sprite);

    if(this->hitbox){
        window.draw(*this->hitbox);
    }
    if(this->hitboxAttack){
        window.draw(*this->hitboxAttack);
    }
}


