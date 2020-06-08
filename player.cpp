#include "player.h"


Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed):animation(texture,imageCount,switchTime){
    this->speed=speed;
    row=0;
    body.setSize(sf::Vector2f(50.0f,75.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(100,100);
    neutral.loadFromFile("D:/STUDIA/PSiO/QTProjekty/GraProjekt/images/paladin_neutral.png");
    run.loadFromFile("D:/STUDIA/PSiO/QTProjekty/GraProjekt/images/paladin_run.png");

    current=neutral;
    body.setTexture(&current);
}

Player::~Player(){}

void Player::Update(float deltaTime){
    sf::Vector2f movement(0.0f,0.0f);

    player_bounds=body.getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        movement.x-=speed*deltaTime;
        row=4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        movement.x+=speed*deltaTime;
        row=12;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        movement.y-=speed*deltaTime;
        row=8;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        movement.y+=speed*deltaTime;
        row=0;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        row=2;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        row=6;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        row=14;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        row=10;
    }

    if(movement.x==0.0f && movement.y==0.0f){
        current=neutral;
        body.setTexture(&current);
    }else{
        current=run;
        body.setTexture(&current);
    }

    animation.Update(&current,row,deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);

}

void Player::Draw(sf::RenderWindow &window){
    window.draw(body);
}


void Player::setBounds(int top, int height, int left, int width)
{
    limit.top = top;
    limit.height = height;
    limit.left = left;
    limit.width = width;
}

Collider Player::GetCollider() {return Collider(body);}

sf::Vector2f Player::GetPosition()
{
    return body.getPosition();
}
