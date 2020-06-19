#ifndef WALL_H
#define WALL_H


class Wall:public sf::RectangleShape{
public:
    Wall(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, float rotation);
    ~Wall();
    //void render(sf::RenderWindow& window);
    //Collider GetCollider();
private:
    sf::RectangleShape body;
};
#endif // WALL_H
