#include "hitbox.h"

Hitbox::Hitbox(sf::Sprite& sprite, sf::FloatRect position):sprite(sprite),position(position)
{
    setPosition(this->sprite.getPosition().x+this->position.left,this->sprite.getPosition().y+this->position.top);
    setSize(sf::Vector2f(position.width,position.height));
    setFillColor(sf::Color::Transparent);
    setOutlineThickness(1.0f);
    setOutlineColor(sf::Color::Green);
}

Hitbox::~Hitbox()
{

}

bool Hitbox::checkIntersect(const sf::FloatRect& frect)
{
    return getGlobalBounds().intersects(frect);
}

void Hitbox::update()
{
    setPosition(this->sprite.getPosition().x+this->position.left,this->sprite.getPosition().y+this->position.top);
}



sf::FloatRect Hitbox::getGlobalB()
{
    return getGlobalBounds();
}
