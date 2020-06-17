#ifndef MAINMENU_H
#define MAINMENU_H
#include <gstate.h>
#include <button.h>

class MainMenu:public Resources
{
public:
    MainMenu(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~MainMenu();

    void updateInput(const float &deltaTime);
    void updateButtons();
    void update(const float &deltaTime);
    void renderButtons(sf::RenderWindow& window);
    void render(sf::RenderWindow* window);
private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    void initVariables();
    void initBackground();
    void initFonts();
    void initButtons();
};

#endif // MAINMENU_H
