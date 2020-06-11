#include "gstate.h"

void GState::initTextures()
{
    if(!textures["PLAYER_NEUTRAL"].loadFromFile("images/paladin_neutral.png")){
        std::cout<<"player neutral texture rip"<<std::endl;
    }
    if(!textures["PLAYER_RUN"].loadFromFile("images/paladin_run.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
}

void GState::initPlayer()
{
    this->player=new Player(sf::Vector2f(10.0f,10.0f), textures);
}

GState::GState(sf::RenderWindow* window,std::stack<Resources*>* layers):Resources(window,layers)
{
    this->initTextures();
    this->initPlayer();
}

GState::~GState()
{
    delete this->player;
}


void GState::updateInput(const float &deltaTime)
{
    this->player->move(sf::Vector2f(0.0f,0.0f),deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->player->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
        this->player->setRow(4);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->player->move(sf::Vector2f(1.0f,0.0f),deltaTime);
        this->player->setRow(12);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->player->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
        this->player->setRow(8);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->player->move(sf::Vector2f(0.0f,1.0f),deltaTime);
        this->player->setRow(0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->player->move(sf::Vector2f(-1.0f,1.0f),deltaTime);
        this->player->setRow(2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->player->move(sf::Vector2f(1.0f,1.0f),deltaTime);
        this->player->setRow(14);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->player->move(sf::Vector2f(-1.0f,-1.0f),deltaTime);
        this->player->setRow(6);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->player->move(sf::Vector2f(1.0f,-1.0f),deltaTime);
        this->player->setRow(10);
    }
    /*if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    if(mousePosWindow.y > this->player->getPosition().y){
        this->player->move(sf::Vector2f(0.0f,1.0f),deltaTime);
        }
    if (mousePosWindow.y < this->player->getPosition().y){
        this->player->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
        }
    if (mousePosWindow.x < this->player->getPosition().x){
        this->player->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
        }
    if (mousePosWindow.x > this->player->getPosition().x){
        this->player->move(sf::Vector2f(1.0f,0.0f),deltaTime);
    }
    }*/

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->player->move(sf::Vector2f(0.0f,0.0f),deltaTime);
            /*body.setTexture(&current);
            body.setScale(1.7,1.4);
            imageCount.x=15;
            deltaTime*=2;*/
        }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endLayer();
    }
}

void GState::update(const float &deltaTime)
{

    this->updateMousePos();
    this->updateInput(deltaTime);

    this->player->update(deltaTime);
}

void GState::render()
{
    this->player->render(window);
}


