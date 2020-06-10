#ifndef BUTTONS_H
#define BUTTONS_H

#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum button_state{BTN_IDLE=0,BTN_HOVER,BTN_PRESSED};

class Button
{
public:
    Button(float x, float y, float width,float height,sf::Font* font,std::string text,
           sf::Color idleColor,sf::Color hoverColor, sf::Color pressedColor);
    ~Button();

    void update(const sf::Vector2f mousePos);
    void render(sf::RenderWindow* window);


    bool isPressed() const;

private:
    short unsigned buttonState;

    sf::RectangleShape jenson; //le epic joke :DDDDDD
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressedColor;
};

#endif // BUTTONS_H
