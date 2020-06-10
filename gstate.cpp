#include "gstate.h"

GState::GState(sf::RenderWindow* window,std::stack<Resources*>* layers):Resources(window,layers)
{

}

GState::~GState()
{

}

void GState::endLayer()
{

}

void GState::updateInput(const float &deltaTime)
{
    this->closeLayer();
}

void GState::update(const float &deltaTime)
{

    this->updateMousePos();
    this->updateInput(deltaTime);


}

void GState::render()
{

}
