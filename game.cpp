#include "game.h"

//Static functions
void ResizeView(const sf::RenderWindow &window,sf::View &view){
    float aspectRatio=float(window.getSize().x)/float(window.getSize().y);

    view.setSize(VIEW_HEIGHT*aspectRatio,VIEW_HEIGHT);
}

//Init functions

void Game::initVariables()
{
    this->window=NULL;
    this->deltaTime=0.0f;
}
void Game::initWindow()
{
    this->window=new sf::RenderWindow(sf::VideoMode(1280, 720), "MaksGra");
    this->view=new sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(800.0f,VIEW_HEIGHT));
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

    //hero settings
    //sf::Texture tex;
    //tex.loadFromFile("images/paladin_neutral.png");
    //this->hero=new Player(&tex,sf::Vector2u(8,16),0.1f,200.0f);

    //map settings

    /*const int level_1_ground[] =
        {
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
            0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        };
    sf::Texture tileset;
    tileset.loadFromFile("images/swamp_ground.png");
    if(!map->load("images/swamp_ground.png", level_1_ground, 16, 16)){
        std::cerr<<"Texture not loaded";
    }*/
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
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                }
            }
        if(event.type == sf::Event::Resized){
            ResizeView(*window,*view);
        }
    }

    //hero->Update(deltaTime);
    //view->setCenter(hero->GetPosition());

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
        this->layers.top()->render();
    }
    //this->window->draw(*map);
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


