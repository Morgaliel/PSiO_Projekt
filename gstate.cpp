#include "gstate.h"



void GState::initTextures()
{
    if(!textures["PLAYER_NEUTRAL"].loadFromFile("images/paladin_neutral.png")){
        std::cout<<"player neutral texture rip"<<std::endl;
    }
    if(!textures["PLAYER_RUN"].loadFromFile("images/paladin_run.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!textures["PLAYER_ATTACK"].loadFromFile("images/paladin_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!mapTextures["LEVEL_1"].loadFromFile("images/swamp_ground.png")){
        std::cerr<<"Texture not loaded";
    }

    mapLayout["LEVEL_1"]={
            1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 1, 1, 141, 140, 0, 0, 2, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 144, 143, 142, 3, 3, 3, 3, 3, 3,
            0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
            0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
            0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
            0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3, 3, 3,
            0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
            0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
            0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
            0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1
};
}

void GState::initPlayer()
{
    this->player=new Player(sf::Vector2f(1000.0f,500.0f), textures);
    map.load(mapTextures["LEVEL_1"],mapLayout["LEVEL_1"],16,16);
}

GState::GState(sf::RenderWindow* window,std::stack<Resources*>* layers):Resources(window,layers)
{
    float aspectRatio=float(window->getSize().x)/float(window->getSize().y);
    this->view.setSize(VIEW_HEIGHT*aspectRatio,VIEW_HEIGHT);
    this->initTextures();
    this->initPlayer();
}

GState::~GState()
{
    delete this->player;
    //delete this->map;
}

void GState::updateView()
{
    this->view.setCenter(this->player->getPosition().x+39,this->player->getPosition().y+46);
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
    if(mousePosView.y > this->player->getPosition().y){
        this->player->move(sf::Vector2f(0.0f,1.0f),deltaTime);
        }
    if (mousePosView.y < this->player->getPosition().y){
        this->player->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
        }
    if (mousePosView.x < this->player->getPosition().x){
        this->player->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
        }
    if (mousePosView.x > this->player->getPosition().x){
        this->player->move(sf::Vector2f(1.0f,0.0f),deltaTime);
    }
    if(mousePosView.y > this->player->getPosition().y && mousePosView.x < this->player->getPosition().x){
        this->player->move(sf::Vector2f(-1.0f,1.0f),deltaTime);
        }
    if (mousePosView.y < this->player->getPosition().y && mousePosView.x > this->player->getPosition().x){
        this->player->move(sf::Vector2f(1.0f,-1.0f),deltaTime);
        }
    if (mousePosView.x > this->player->getPosition().x && mousePosView.y > this->player->getPosition().y){
        this->player->move(sf::Vector2f(1.0f,1.0f),deltaTime);
        }
    if (mousePosView.x < this->player->getPosition().x && mousePosView.y < this->player->getPosition().y){
        this->player->move(sf::Vector2f(-1.0f,-1.0f),deltaTime);
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
    this->updateView();
    this->player->update(deltaTime);

}

void GState::render(sf::RenderWindow* window)
{
    this->window->setView(view);
    window->draw(map);
    this->player->render(*window);
}


