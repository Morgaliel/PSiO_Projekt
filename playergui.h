#ifndef PLAYERGUI_H
#define PLAYERGUI_H

#include <player.h>
#include <enemy.h>

class PlayerGUI
{
public:
    PlayerGUI(Player* player);
    PlayerGUI(Enemy* enemy,Player* player);
    virtual ~PlayerGUI();

    void update(const float& potionTimer);
    void updateEnemy();
    void render(sf::RenderWindow* window,int x);
    void renderEnemy(sf::RenderWindow* window);
private:
    Player* player;
    Enemy* enemy;

    sf::Font font;
    sf::RectangleShape hpBarOut;
    sf::RectangleShape hpBarIn;
    sf::RectangleShape hpBarOutE;
    sf::RectangleShape hpBarInE;
    sf::RectangleShape gameOverBar;
    sf::Text gameOverText;

    sf::RectangleShape GGBar;
    sf::Text GGText;

    std::string potionTimeString;
    sf::Text potionTimeText;
    sf::RectangleShape potionTime;
    float hpMaxWidth;
};

#endif // PLAYERGUI_H
