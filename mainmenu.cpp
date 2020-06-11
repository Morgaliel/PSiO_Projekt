#include "mainmenu.h"


void MainMenu::initVariables()
{

}
void MainMenu::initBackground()
{
    this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));

    if(!this->backgroundTexture.loadFromFile("images/menu_background.png")){
        std::cout<<"there is no background menu texture"<<std::endl;
    }

    this->background.setTexture(&this->backgroundTexture);
}
void MainMenu::initFonts()
{
    if(!this->font.loadFromFile("fonts/diablo_h.ttf")){
        std::cout<<"smth wrong with the font"<<std::endl;
    }
}

void MainMenu::initButtons()
{
    this->buttons["GAME"]=new Button(400,600,150,50,&this->font, "New Game",
                                sf::Color(70,70,70,200),sf::Color(150,150,150,255),sf::Color(20,20,20,200));
    this->buttons["EXIT"]=new Button(700,600,150,50,&this->font, "Quit",
                                sf::Color(70,70,70,200),sf::Color(150,150,150,255),sf::Color(20,20,20,200));

}


MainMenu::MainMenu(sf::RenderWindow* window,std::stack<Resources*>* layers):Resources(window,layers)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initButtons();


}

MainMenu::~MainMenu()
{
    for(auto it=this->buttons.begin(); it!=this->buttons.end();++it){
        delete it->second;
    }
}


void MainMenu::updateInput(const float &deltaTime)
{
}

void MainMenu::updateButtons()
{
    for(auto &it:this->buttons){
        it.second->update(this->mousePosView);
    }

    if(this->buttons["GAME"]->isPressed()){
        this->layers->push(new GState(this->window,this->layers));
    }

    if(this->buttons["EXIT"]->isPressed()){
        this->endLayer();
    }
}

void MainMenu::update(const float &deltaTime)
{
    this->updateMousePos();
    this->updateInput(deltaTime);

    this->updateButtons();
}

void MainMenu::renderButtons()
{
    for(auto &it:this->buttons){
        it.second->render(window);
    }
}

void MainMenu::render(){
    window->draw(this->background);
    renderButtons();
}




