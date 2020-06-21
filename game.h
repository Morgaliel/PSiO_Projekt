#ifndef GAME_H
#define GAME_H
#include <mainmenu.h>



class Game
{
public:
    Game();
    ~Game();

    void quitGame();

    void updateDT();
    void updateEvents();
    void update();
    void render();
    void run();

private:
    //Variables
    sf::RenderWindow *window;
    sf::Event event;

    sf::Clock theClock;
    float deltaTime;

    std::stack<Resources*> layers;

    Player *hero;
    Tilemap *map;

    //Init
    void initVariables();
    void initWindow();
    void initResources();

};

#endif // GAME_H
