#include "gstate.h"
#include "collider.h"


void GState::initTextures()
{
    if(!music.openFromFile("sound/Tristram.flac")){
        std::cerr<<"Music not loaded";
    }

    if(!texturesPlayer["PLAYER_NEUTRAL"].loadFromFile("images/paladin_neutral.png")){
        std::cout<<"player neutral texture rip"<<std::endl;
    }
    if(!texturesPlayer["PLAYER_RUN"].loadFromFile("images/paladin_run.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesPlayer["PLAYER_ATTACK"].loadFromFile("images/paladin_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!texturesEnemies["GOATMAN_NEUTRAL"].loadFromFile("images/goatman_neutral.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["GOATMAN_WALK"].loadFromFile("images/goatman_walk.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["GOATMAN_ATTACK"].loadFromFile("images/goatman_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!mapTextures["LEVEL_1"].loadFromFile("images/town_floor.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_1_OBJ"].loadFromFile("images/town_objects.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_1_TREES"].loadFromFile("images/trees.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_1_ENTRY"].loadFromFile("images/entry.png")){
        std::cerr<<"Texture not loaded";
    }


}

void GState::initPlayer()
{
    this->player=new Player(sf::Vector2f(1400.0f,1020.0f), texturesPlayer);
    this->playerGUI=new PlayerGUI(this->player);


    enemies.emplace_back(new Enemy(sf::Vector2f(1600.0f,1020.0f), texturesEnemies));
    //this->enemy=new Enemy(sf::Vector2f(1600.0f,1020.0f), texturesEnemies);

}

void GState::initMaps()
{
    mapLayout["LEVEL_1"]={
            183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 183, 183,
            183, 183, 183, 184, 184, 186, 185, 184, 184, 184, 183, 183, 183,
            7, 7, 7, 7, 99, 189, 188, 187, 97, 7, 7, 7, 7,
            7, 7, 7, 7, 143, 52, 52, 52, 113, 7, 7, 7, 7,
            4, 7, 18, 18, 7, 4, 7, 4, 4, 4, 7, 4, 7,
            7, 7, 17, 14, 49, 7, 182, 181, 180, 7, 7, 4, 7,
            4, 7, 8, 52, 9, 4, 179, 178, 177, 4, 7, 4, 7,
            7, 7, 7, 7, 7, 7, 176, 175, 174, 7, 7, 7, 7,
            7, 7, 4, 4, 7, 4, 7, 4, 7, 4, 4, 4, 4,
            7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
            7, 7, 4, 4, 7, 4, 7, 4, 7, 4, 4, 4, 4,
            7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
            7, 7, 4, 4, 7, 4, 7, 4, 7, 4, 4, 4, 4,
};
    mapLayout["LEVEL_1_OBJ"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 55, 54, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 53, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 51, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
};
    mapLayout["LEVEL_1_WALL"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            7, 5, 4, 3, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            2, 35, 56, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            1, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            1, 52, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            1, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            0, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
};
    mapLayout["LEVEL_1_WALL2"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 7,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 2,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 0,
};
    mapLayout["LEVEL_1_WALL_CORNER"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            6, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 6
};
    mapLayout["LEVEL_1_TREES"]={
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 54, 9,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 36, 55, 10, 120,
            120, 99, 120, 120, 120, 18, 120, 27, 37, 45, 120, 63, 120,
            100, 0, 108, 36, 19, 9, 28, 72, 46, 90, 64, 120, 81,
            1, 109, 37, 120, 10, 120, 73, 120, 91, 120, 120, 82, 120,
};
    mapLayout["LEVEL_1_ENTRY"]={
            20, 19, 18, 17, 16, 15, 55, 55, 12, 11, 10, 9, 8,
            55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
            55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
};
    mapLayout["LEVEL_1_ENTRY2"]={
            55, 55, 55, 55, 55, 55, 14, 13, 55, 55, 55, 55, 55,
};

    maps["LEVEL_1"]=new Tilemap();
    maps["LEVEL_1"]->load(mapTextures["LEVEL_1"],mapLayout["LEVEL_1"],13,13,sf::Vector2i(160,80), sf::Vector2i (9,7));

    maps["LEVEL_1_OBJ"]=new Tilemap();
    maps["LEVEL_1_OBJ"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_OBJ"],13,11,sf::Vector2i(160,320), sf::Vector2i (8,8));

    maps["LEVEL_1_WALL"]=new Tilemap();
    maps["LEVEL_1_WALL"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_WALL"],13,7,sf::Vector2i(160,320), sf::Vector2i (8,8));
    maps["LEVEL_1_WALL2"]=new Tilemap();
    maps["LEVEL_1_WALL2"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_WALL2"],13,7,sf::Vector2i(160,320), sf::Vector2i (8,8));

    maps["LEVEL_1_WALL_CORNER"]=new Tilemap();
    maps["LEVEL_1_WALL_CORNER"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_WALL_CORNER"],13,2,sf::Vector2i(160,320), sf::Vector2i (8,8));
    maps["LEVEL_1_TREES"]=new Tilemap();
    maps["LEVEL_1_TREES"]->load(mapTextures["LEVEL_1_TREES"],mapLayout["LEVEL_1_TREES"],13,11,sf::Vector2i(160,385), sf::Vector2i (8,8));
    maps["LEVEL_1_ENTRY"]=new Tilemap();
    maps["LEVEL_1_ENTRY"]->load(mapTextures["LEVEL_1_ENTRY"],mapLayout["LEVEL_1_ENTRY"],13,3,sf::Vector2i(160,640), sf::Vector2i (8,8));
    maps["LEVEL_1_ENTRY2"]=new Tilemap();
    maps["LEVEL_1_ENTRY2"]->load(mapTextures["LEVEL_1_ENTRY"],mapLayout["LEVEL_1_ENTRY2"],13,1,sf::Vector2i(160,640), sf::Vector2i (8,8));
}

GState::GState(sf::RenderWindow* window,std::stack<Resources*>* layers):Resources(window,layers)

{
    this->potionTimer=10;
    float aspectRatio=float(window->getSize().x)/float(window->getSize().y);
    this->view=new sf::View();
    this->view->setSize(VIEW_HEIGHT*aspectRatio,VIEW_HEIGHT);
    this->initTextures();
    this->initPlayer();
    this->initMaps();

    music.setVolume(5.0f);
    music.setLoop(true);
    //music.play();

    if(!textureWall.loadFromFile("images/wall.png")) {
        std::cerr << "Could not load wall" << std::endl;
    }
    textureWall.setRepeated(true);
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1400.0,100.0),sf::Vector2f(876.0f-160.0f,890.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(380.0,100.0),sf::Vector2f(1440.0f,690.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(900.0,100.0),sf::Vector2f(1440.0f,600.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(460.0,100.0),sf::Vector2f(2130.0f,950.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1400.0,100.0),sf::Vector2f(2060.0f-80.0f,1340.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1400.0,100.0),sf::Vector2f(1040.0f-80.0f,1280.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1235.0f-80.0f,805.0f-40.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1435.0f-80.0f,801.0f-40.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1130.0f-80.0f,810.0f-40.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1270.0f-80.0f,840.0f-40.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(150.0,100.0),sf::Vector2f(1500.0f-80.0f,800.0f-40.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(900.0,100.0),sf::Vector2f(1600.0f-80.0f,770.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(100.0,100.0),sf::Vector2f(1450.0f-80.0f,810.0f-40.0f),0.0f));


}

GState::~GState()
{
    delete this->player;
    delete this->view;
    for(auto &it:maps){
        delete it.second;
    }
    for(auto &it:walls){
        delete it;
    }
    delete this->playerGUI;
    for(auto &it:enemies){
        delete it;
    }
}

void GState::updateView()
{
    this->view->setCenter(this->player->getPosition().x+39,this->player->getPosition().y+46);
}

void GState::updatePlayerGUI(const float &deltaTime)
{
    this->playerGUI->update(deltaTime, potionTimer);
}


void GState::updateInput(const float &deltaTime)
{
    this->player->move(sf::Vector2f(0.0f,0.0f),deltaTime);
    //this->enemy->move(sf::Vector2f(0.0f,0.0f),deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->player->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->player->move(sf::Vector2f(1.0f,0.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(1.0f,0.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->player->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->player->move(sf::Vector2f(0.0f,1.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(0.0f,1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->player->move(sf::Vector2f(-1.0f,1.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(-1.0f,1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->player->move(sf::Vector2f(1.0f,1.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(1.0f,1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->player->move(sf::Vector2f(-1.0f,-1.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(-1.0f,-1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->player->move(sf::Vector2f(1.0f,-1.0f),deltaTime);
        //this->enemy->move(sf::Vector2f(1.0f,-1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
        if(potionTimer<1){
            player->gainHP(player->hpMax*0.5);
            potionTimer=30;
        }
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endLayer();
    }
}

void GState::update(const float &deltaTime)
{

    if(potionTimer>0)
        potionTimer-=deltaTime;
    this->updateMousePos();
    this->updateInput(deltaTime);
    this->player->hitbox->update();
    this->player->hitboxAttack->update();
    //this->enemy->hitbox->update();
    //this->enemy->hitboxAttack->update();

    for(auto &it:enemies){
        it->hitbox->update();
        it->hitboxAttack->update();
    }
    for(auto &it:walls){
        collision::areColliding(it,player->hitbox,player,deltaTime,it->getRotation(),2);
        for(auto &i:enemies){
            collision::areColliding(it,i->hitbox,i,deltaTime,it->getRotation(),2);
        }
    }
    for(auto &it:enemies){
        collision::areColliding(it->hitboxAttack,player->hitboxAttack,player,deltaTime,it->hitboxAttack->getRotation(),0);
    }
    //collision::areColliding(enemy->hitboxAttack,player->hitboxAttack,player,deltaTime,enemy->hitboxAttack->getRotation(),0)

    //this->enemy->update(deltaTime);
    for(auto &it:enemies){
        it->update(deltaTime);
    }
    this->player->update(deltaTime);
    //this->enemy->move(sf::Vector2f(1.0f,0.0f),deltaTime);
    this->updateView();
    this->playerGUI->update(deltaTime, potionTimer);
//this->wall->getGlobalBounds().intersects(player->hitbox->getGlobalBounds());

}

void GState::render(sf::RenderWindow* window)
{


    //walls.push_back(Wall(textureWall,sf::Vector2f(250.0,100.0),sf::Vector2f(876.0f,536.0f)));
    this->window->setView(*view);
    window->draw(*maps["LEVEL_1"]);
    window->draw(*maps["LEVEL_1_ENTRY"]);
    window->draw(*maps["LEVEL_1_WALL"]);
    window->draw(*maps["LEVEL_1_WALL_CORNER"]);
    window->draw(*maps["LEVEL_1_OBJ"]);
    if(this->player->hitbox->getGlobalBounds().top<878){
        this->player->render(*window);
        window->draw(*maps["LEVEL_1_ENTRY2"]);
    }else{
        window->draw(*maps["LEVEL_1_ENTRY2"]);
        this->player->render(*window);
    }
    window->draw(*maps["LEVEL_1_TREES"]);
    window->draw(*maps["LEVEL_1_WALL2"]);

    this->playerGUI->render(window);
    for(auto &it:enemies){
        it->render(*window);
    }
    //this->enemy->render(*window);
    //this->player->hitbox->render(*window);
    /*for(Wall& p:*walls){
            p.draw(*window);
        }*/
    //wall.Draw(*window);
    for(auto &it:walls){
        window->draw(*it);
    }


}


