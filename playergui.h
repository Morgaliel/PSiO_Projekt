#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include <player.h>

class PlayerGUI
{
public:
    PlayerGUI(Player* player);
    virtual ~PlayerGUI();

    void update(const float& deltaTime, const float& potionTimer);
    void render(sf::RenderWindow* window);
private:
    Player* player;

    sf::Font font;
    sf::RectangleShape hpBarOut;
    sf::RectangleShape hpBarIn;
    sf::RectangleShape gameOverBar;
    sf::Text gameOverText;

    std::string potionTimeString;
    sf::Text potionTimeText;
    sf::RectangleShape potionTime;
    float hpMaxWidth;
};

#endif // PLAYERGUI_H
