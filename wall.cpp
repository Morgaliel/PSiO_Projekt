#include "wall.h"
Wall::Wall(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position){
    body.setSize(size);
    body.setPosition(position);
    body.setOrigin(size.x/2,size.y/2);
    body.setTexture(texture);
    sf::IntRect bound=static_cast<sf::IntRect>(body.getGlobalBounds());
    body.setTextureRect(bound);
}

Wall::~Wall()
{

}

void Wall::Draw(sf::RenderWindow &window){
    window.draw(body);
}

//Collider Wall::GetCollider() {return Collider(body);}
