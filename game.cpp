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
    //delete this->view;
    while(!this->layers.empty()){
        delete this->layers.top();
        this->layers.pop();
    }
}



//Funcutions
void Game::quitGame()
{
    std::cout<<"ELO"<<"/n";
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
                    //sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
                    sf::Vector2f mousePosView=window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                    //std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                    std::cout << "Mouse clicked: " << mousePosView.x << ", " << mousePosView.y << std::endl;
                }
            }
    }

    //hero->Update(deltaTime);

    //Collider col=hero->GetCollider();
    /*for(Wall& p:walls){
        p.GetCollider().CheckCollision(col,1.0f);
    }*/

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
    //this->window->setView(*view);

    //render
    if(!this->layers.empty()){
        this->layers.top()->render(window);
    }
    //hero->Draw(*window);
    /*for(Wall& p:walls){
        p.Draw((window));
    }*/

    // End the current frame
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen()) {

    //FOR NOW THIS IS HERE

        //walls
        /*sf::Texture textureWall;
        if(!textureWall.loadFromFile("images/wall.png")) {
            std::cerr << "Could not load wall" << std::endl;
        }
        textureWall.setRepeated(true);

        std::vector<Wall> walls;

        walls.push_back(Wall(&textureWall,sf::Vector2f(250.0,100.0),sf::Vector2f(450.0f,480.0f)));
        walls.push_back(Wall(&textureWall,sf::Vector2f(300.0f,100.0f),sf::Vector2f(400.0f,180.0f)));
        walls.push_back(Wall(&textureWall,sf::Vector2f(250.0f,100.0f),sf::Vector2f(860.0f,380.0f)));
        walls.push_back(Wall(&textureWall,sf::Vector2f(3500.0f,150.0f),sf::Vector2f(640.0f,690.0f)));
*/

        //DELETE LATER
        this->updateDT();
        this->update();
        this->render();
    }
}


