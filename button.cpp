#include "button.h"

Button::Button(float x, float y, float width,float height,sf::Font* font,std::string text,
               sf::Color idleColor,sf::Color hoverColor, sf::Color pressedColor)
{
    this->buttonState = BTN_IDLE;

    this->jenson.setPosition(sf::Vector2f(x,y));
    this->jenson.setSize(sf::Vector2f(width,height));

    this->font=font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(20);
    this->text.setPosition(
         this->jenson.getPosition().x+(jenson.getGlobalBounds().width/2.0f)-this->text.getGlobalBounds().width/2.0f,
         this->jenson.getPosition().y+(jenson.getGlobalBounds().height/2.0f)-this->text.getGlobalBounds().height
    );

    this->idleColor=idleColor;
    this->hoverColor=hoverColor;
    this->pressedColor=pressedColor;

    this->jenson.setFillColor(this->idleColor);
    this->jenson.setOutlineThickness(2.0f);
    this->jenson.setOutlineColor(sf::Color(212, 81, 25));
}

Button::~Button()
{

}


void Button::update(const sf::Vector2f mousePos)
{
    this->buttonState=BTN_IDLE;
    this->jenson.setFillColor(this->idleColor);
    //hover
    if(this->jenson.getGlobalBounds().contains(mousePos)){
        this->buttonState=BTN_HOVER;
        this->jenson.setFillColor(this->hoverColor);
        //pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState=BTN_PRESSED;
            this->jenson.setFillColor(this->pressedColor);
        }
    }


}

void Button::render(sf::RenderWindow& window)
{
    window.draw(this->jenson);
    window.draw(this->text);
}

bool Button::isPressed() const
{
    if(this->buttonState==BTN_PRESSED){
        return true;
    }
    return false;
}
