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
    this->hpBarOut.setPosition(this->player->getPosition().x-450.0f,this->player->getPosition().y+280.0f);
    this->hpBarOut.setOutlineThickness(1.0f);
    this->hpBarOut.setOutlineColor(sf::Color::White);

    this->hpBarIn.setSize(sf::Vector2f(width,height));
    this->hpBarIn.setFillColor(sf::Color(250,20,20,200));
    this->hpBarIn.setPosition(this->hpBarOut.getPosition());

    this->potionTimeText.setFont(this->font);
    this->potionTime.setSize(sf::Vector2f(height,height));
    this->potionTime.setFillColor(sf::Color(50,50,50,200));
    this->potionTime.setPosition(this->player->getPosition().x-230.0f,this->player->getPosition().y+280.0f);
    this->potionTime.setOutlineThickness(1.0f);
    this->potionTime.setOutlineColor(sf::Color::White);
    //this->potionTime.setOrigin(potionTime.getSize().x/2,potionTime.getSize().y/2);

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

    this->potionTimeText.setOrigin(potionTimeText.getLocalBounds().width/2.f,potionTimeText.getLocalBounds().height/2.f);
    this->potionTimeText.setPosition(potionTime.getPosition().x+17,potionTime.getPosition().y+9);
    //std::cout<<potionTimeText.getLocalBounds().width;
    this->potionTimeText.setString(std::to_string(static_cast<int>(potionTimer)));


}

void PlayerGUI::render(sf::RenderWindow *window)
{
    window->draw(this->hpBarOut);
    window->draw(this->hpBarIn);
    window->draw(this->potionTime);
    window->draw(this->potionTimeText);
}
