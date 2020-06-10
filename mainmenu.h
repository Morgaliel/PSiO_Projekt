#ifndef MAINMENU_H
#define MAINMENU_H
#include <gstate.h>
#include <button.h>

class MainMenu:public Resources
{
public:
    MainMenu(sf::RenderWindow* window,std::stack<Resources*>* layers);
    virtual ~MainMenu();

    void endLayer();
    void updateInput(const float &deltaTime);
    void updateButtons();
    void update(const float &deltaTime);
    void renderButtons();
    void render();
private:
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    void initFonts();
    void initButtons();
};

#endif // MAINMENU_H
