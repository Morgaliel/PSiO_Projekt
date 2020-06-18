#include "wall.h"
Wall::Wall(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position){
    body.setSize(size);
    body.setPosition(position);
    body.setOrigin(size.x/2,size.y/2);
    body.setTexture(texture);
    sf::IntRect bound=static_cast<sf::IntRect>(body.getGlobalBounds());
    body.setTextureRect(bound);
    body.rotate(-26.0f);
}

Wall::~Wall()
{

}

void Wall::Draw(sf::RenderWindow &window){
    window.draw(body);
}

void Wall::getPosition()
{
    sf::FloatRect bounds=body.getGlobalBounds();
    std::cout<<bounds.top<<"     "<<bounds.left<<"     "<<bounds.width<<std::endl;
}

Collider Wall::GetCollider() {return Collider(body);}

//walls
/*sf::Texture textureWall;
if(!textureWall.loadFromFile("images/wall.png")) {
    std::cerr << "Could not load wall" << std::endl;
}
textureWall.setRepeated(true);

std::vector<Wall> walls;

walls.push_back(Wall(&textureWall,sf::Vector2f(250.0,100.0),sf::Vector2f(450.0f,480.0f)));
walls.push_back(Wall(&textureWall,sf::Vector2f(300.0f,100.0f),sf::Vector2f(400.0f,180.0f)));
walls.push_back(Wall(&textureWall,sf::Vector2f(250.0f,100.0f),sf::Vector2f(860.0f,380.0f)));
walls.push_back(Wall(&textureWall,sf::Vector2f(3500.0f,150.0f),sf::Vector2f(640.0f,690.0f)));
*/
