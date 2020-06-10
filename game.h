#ifndef GAME_H
#define GAME_H
#include <mainmenu.h>


static const float VIEW_HEIGHT=600.0f;

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
    sf::View *view;
    sf::Event event;

    sf::Clock theClock;
    float deltaTime;

    std::stack<Resources*> layers;

    Player *hero;
    Tilemap *map;

    //Init
    void initWindow();
    void initResources();

};

#endif // GAME_H
