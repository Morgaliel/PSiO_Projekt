#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <player.h>
#include <wall.h>
#include <tilemap.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <player.h>
#include <wall.h>
#include <tilemap.h>

static const float VIEW_HEIGHT=600.0f;

class Game
{
public:
    Game();
    ~Game();

    void updateDT();
    void updateEvents();
    void update();
    void render();
    void run();

private:
    //Variables
    sf::RenderWindow *window;
    sf::View *view;
    sf::Event event;

    sf::Clock theClock;
    float deltaTime;

    Player *hero;
    Tilemap *map;

    //Init
    void initializeWindow();

};

#endif // GAME_H
