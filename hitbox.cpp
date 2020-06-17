#include "hitbox.h"

Hitbox::Hitbox(sf::Sprite& sprite, sf::FloatRect position):sprite(sprite),position(position)
{
    this->hitbox.setPosition(this->sprite.getPosition().x+position.left,this->sprite.getPosition().y+position.top);
    this->hitbox.setSize(sf::Vector2f(position.width,position.height));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(1.0f);
    this->hitbox.setOutlineColor(sf::Color::Green);
}

Hitbox::~Hitbox()
{

}

bool Hitbox::checkIntersect(const sf::FloatRect& frect)
{
    return this->hitbox.getGlobalBounds().intersects(frect);
}

void Hitbox::update()
{
    this->hitbox.setPosition(this->sprite.getPosition().x+this->position.left,this->sprite.getPosition().y+this->position.top);
}

void Hitbox::render(sf::RenderWindow& window)
{
    window.draw(this->hitbox);
}
