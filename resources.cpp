#include "resources.h"

Resources::Resources(sf::RenderWindow* window, std::stack<Resources*>* layers)
{
    this->window=window;
    this->layers=layers;
    this->end=false;
}

Resources::~Resources()
{

}

const bool &Resources::getEnd() const
{
    return this->end;
}

void Resources::closeLayer()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->end=true;
    }
}

void Resources::updateMousePos()
{
    this->mousePosScreen=sf::Mouse::getPosition();
    this->mousePosWindow=sf::Mouse::getPosition(*this->window);
    this->mousePosView=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
