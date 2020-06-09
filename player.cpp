#include "player.h"


Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed):animation(texture,imageCount,switchTime){
    this->speed=speed;
    row=0;
    body.setSize(sf::Vector2f(50.0f,75.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(900,500);
    neutral.loadFromFile("images/paladin_neutral.png");
    run.loadFromFile("images/paladin_run.png");
    attack.loadFromFile("images/paladin_attack.png");
    current=neutral;
    body.setTexture(&current);
    this->canAttack=true;
    this->imageCount=imageCount;
    body.setTextureRect(sf::IntRect(0, 0, 75, 95));
}

Player::~Player(){}

void Player::Update(float deltaTime){
    sf::Vector2f movement(0.0f,0.0f);

    imageCount.x=8;
    body.setScale(1,1);
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        canAttack=false;
        movement.x=0;
        movement.y=0;
        current=attack;
        body.setTexture(&current);
        body.setScale(1.5,1.5);
        imageCount.x=15;
        animation.Update(&current,row,deltaTime,imageCount);
    }
    animation.Update(&current,row,deltaTime,imageCount);
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
    sf::Vector2f pos=body.getPosition();
    pos.x+=body.getOrigin().x;
    pos.y+=body.getOrigin().y;
    return pos;
}
