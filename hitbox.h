#ifndef HITBOX_H
#define HITBOX_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Hitbox
{
public:
    Hitbox(sf::Sprite& sprite, sf::FloatRect position);
    virtual ~Hitbox();

    bool checkIntersect(const sf::FloatRect& frect);

    void update();
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape hitbox;
    sf::Sprite& sprite;
    sf::FloatRect position;
};

#endif // HITBOX_H
