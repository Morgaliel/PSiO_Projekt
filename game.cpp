#include "game.h"



//Init functions

void Game::initVariables()
{
    this->window=NULL;
    this->deltaTime=0.0f;
}
void Game::initWindow()
{
    this->window=new sf::RenderWindow(sf::VideoMode(1280, 720), "MaksGra");
}

void Game::initResources()
{
    this->layers.push(new MainMenu(this->window,&this->layers));
}


//Constructor/Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initResources();

}

Game::~Game()
{
    delete this->window;
    while(!this->layers.empty()){
        delete this->layers.top();
        this->layers.pop();
    }
}



//Funcutions
void Game::quitGame()
{
    //std::cout<<"QUIT"<<"/n";
}
void Game::updateDT()
{
    this->deltaTime = this->theClock.restart().asSeconds();
}
void Game::updateEvents()
{

    if(deltaTime>1.0f/20.0f){
        deltaTime=1.0f/20.0f;
    }
    // check all the window's events that were triggered since the last iteration of the loop
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed){
            this->window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosView=window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                    std::cout << "Mouse clicked: " << mousePosView.x << ", " << mousePosView.y << std::endl;
                }
            }

    }

}

void Game::update()
{
    this->updateEvents();

    if(!this->layers.empty()){
        this->layers.top()->update(this->deltaTime);

        if(this->layers.top()->getEnd()){
            this->layers.top()->endLayer();
            delete this->layers.top();
            this->layers.pop();
        }
    }else{
        this->quitGame();
        this->window->close();
    }
}

void Game::render()
{
    // clear and view
    this->window->clear(sf::Color::Black);

    //render
    if(!this->layers.empty()){
        this->layers.top()->render(window);
    }

    // End the current frame
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen()) {
        this->updateDT();
        this->update();
        this->render();
    }
}


