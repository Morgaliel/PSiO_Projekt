#include "wall.h"
Wall::Wall(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, float rotation){
    setSize(size);
    setPosition(position);
    setOrigin(size.x/2,size.y/2);
    setTexture(texture);
    sf::IntRect bound=static_cast<sf::IntRect>(getGlobalBounds());
    setTextureRect(bound);
    rotate(rotation);
}

Wall::~Wall()
{

}
