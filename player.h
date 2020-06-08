#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "animation.h"
#include "collider.h"

class Player {
public:
    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime,float speed);
    ~Player();

    void Update(float deltaTime);


    void Draw(sf::RenderWindow& window);

    void setBounds(int top, int height, int left, int width );

    Collider GetCollider();

    sf::Vector2f GetPosition();
private:
    sf::RectangleShape body;
    Animation animation;
    sf::FloatRect player_bounds;
    sf::IntRect limit;
    unsigned int row;
    float speed;

    sf::Texture neutral;
    sf::Texture run;
    sf::Texture current;
};

#endif // PLAYER_H
