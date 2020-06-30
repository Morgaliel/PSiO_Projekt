#include "playergui.h"

PlayerGUI::PlayerGUI(Player* player)
{
    float width=200.0f;
    float height=40.0f;
    this->hpMaxWidth=width;
    this->player=player;
    this->font.loadFromFile("fonts/diablo_h.ttf");
    this->hpBarOut.setSize(sf::Vector2f(width,height));
    this->hpBarOut.setFillColor(sf::Color(50,50,50,200));
    this->hpBarOut.setPosition(this->player->getCenter().x-450.0f,this->player->getCenter().y+280.0f);
    this->hpBarOut.setOutlineThickness(1.0f);
    this->hpBarOut.setOutlineColor(sf::Color::White);

    this->hpBarIn.setSize(sf::Vector2f(width,height));
    this->hpBarIn.setFillColor(sf::Color(250,20,20,200));
    this->hpBarIn.setPosition(this->hpBarOut.getPosition());

    this->potionTimeText.setFont(this->font);
    this->potionTime.setSize(sf::Vector2f(height,height));
    this->potionTime.setFillColor(sf::Color(50,50,50,200));
    this->potionTime.setPosition(this->player->getCenter().x-230.0f,this->player->getCenter().y+280.0f);
    this->potionTime.setOutlineThickness(1.0f);
    this->potionTime.setOutlineColor(sf::Color::White);

    this->gameOverText.setFont(this->font);
    this->gameOverBar.setSize(sf::Vector2f(1280,720));
    this->gameOverBar.setFillColor(sf::Color(0,0,0,255));
    this->gameOverBar.setPosition(this->player->getCenter().x,this->player->getCenter().y);

    this->GGText.setFont(this->font);
    this->GGBar.setSize(sf::Vector2f(1280,720));
    this->GGBar.setFillColor(sf::Color(0,0,0,255));
    this->GGBar.setPosition(this->player->getCenter().x,this->player->getCenter().y);
}

PlayerGUI::PlayerGUI(Enemy *enemy,Player* player)
{
    float width=100.0f;
    float height=20.0f;
    this->hpMaxWidth=width;
    this->player=player;
    this->enemy=enemy;
    this->hpBarOutE.setSize(sf::Vector2f(width,height));
    this->hpBarOutE.setFillColor(sf::Color(50,50,50,200));
    this->hpBarOutE.setPosition(this->player->getCenter().x,this->player->getCenter().y-250.0f);
    this->hpBarOutE.setOutlineThickness(1.0f);
    this->hpBarOutE.setOutlineColor(sf::Color::White);

    this->hpBarInE.setSize(sf::Vector2f(width,height));
    this->hpBarInE.setFillColor(sf::Color(250,20,20,200));
    this->hpBarInE.setPosition(this->hpBarOutE.getPosition());
}

PlayerGUI::~PlayerGUI()
{

}

void PlayerGUI::update(const float &deltaTime, const float& potionTimer)
{
    float percent=static_cast<float>(this->player->hp)/static_cast<float>(this->player->hpMax);
    this->hpBarIn.setSize(sf::Vector2f(std::floor(this->hpMaxWidth*percent),this->hpBarIn.getSize().y));

    this->hpBarOut.setPosition(player->getPosition().x-450.0f,player->getPosition().y+280.0f);
    this->hpBarIn.setPosition(this->hpBarOut.getPosition());
    this->potionTime.setPosition(player->getPosition().x-230.0f,player->getPosition().y+280.0f);
    this->gameOverBar.setPosition(this->player->getCenter().x-640,this->player->getCenter().y-360);
    this->GGBar.setPosition(this->player->getCenter().x-640,this->player->getCenter().y-360);

    this->potionTimeText.setOrigin(potionTimeText.getLocalBounds().width/2.f,potionTimeText.getLocalBounds().height/2.f);
    this->potionTimeText.setPosition(potionTime.getPosition().x+17,potionTime.getPosition().y+9);
    this->potionTimeText.setString(std::to_string(static_cast<int>(potionTimer)));

    this->gameOverText.setOrigin(gameOverText.getLocalBounds().width/2.f,gameOverText.getLocalBounds().height/2.f);
    this->gameOverText.setPosition(gameOverBar.getPosition().x+640,gameOverBar.getPosition().y+320);
    this->gameOverText.setString("GAME OVER \n PRESS ESC");
    this->gameOverText.setCharacterSize(50);

    this->GGText.setOrigin(GGText.getLocalBounds().width/2.f,GGText.getLocalBounds().height/2.f);
    this->GGText.setPosition(GGBar.getPosition().x+640,GGBar.getPosition().y+320);
    this->GGText.setString("  YOU WIN \n PRESS ESC");
    this->GGText.setCharacterSize(50);
}

void PlayerGUI::updateEnemy()
{
    float percent=static_cast<float>(this->enemy->hp)/static_cast<float>(this->enemy->hpMax);
    this->hpBarInE.setSize(sf::Vector2f(std::floor(this->hpMaxWidth*percent),this->hpBarInE.getSize().y));

    this->hpBarOutE.setPosition(player->getPosition().x,player->getPosition().y-250.0f);
    this->hpBarInE.setPosition(this->hpBarOutE.getPosition());
}

void PlayerGUI::render(sf::RenderWindow *window,int x)
{
    window->draw(this->hpBarOut);
    window->draw(this->hpBarIn);
    window->draw(this->potionTime);
    window->draw(this->potionTimeText);
    if(player->hp==0){
        window->draw(this->gameOverBar);
        window->draw(this->gameOverText);
    }
    if(x==0){
        window->draw(this->GGBar);
        window->draw(this->GGText);
    }
}

void PlayerGUI::renderEnemy(sf::RenderWindow *window)
{
    if(enemy->hp>0){
        window->draw(this->hpBarOutE);
        window->draw(this->hpBarInE);
    }
}
