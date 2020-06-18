#include "player.h"

void Player::initVariables()
{
    this->isAttacking=false;
}

void Player::initComponents()
{

}

Player::Player(sf::Vector2f position, std::map<std::string, sf::Texture> &textures){

    this->initVariables();
    row=0;

    this->setPosition(position);

    this->createHitbox(this->sprite,sf::FloatRect(15,15,40.0f,70.0f));
    this->createMove(250.0f);
    this->createAnimation(textures["PLAYER_NEUTRAL"]);
    this->createAnimation(textures["PLAYER_RUN"]);
    this->createAnimation(textures["PLAYER_ATTACK"]);

    //creating animation (I FORGOT TWICE): load texture, createAnimation, addAnimation
    this->animation[0].addAnimation("PLAYER_NEUTRAL",sf::Vector2u(8,16),0.1f);
    this->animation[1].addAnimation("PLAYER_RUN",sf::Vector2u(8,16),0.1f);
    this->animation[2].addAnimation("PLAYER_ATTACK",sf::Vector2u(15,16),0.05f);

}

Player::~Player(){}

void Player::updateAttack()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->isAttacking=true;
        this->sprite.setOrigin(44.0f,14.0f);
    }
}

void Player::updateAnimation(const float &deltaTime)
{
    if(this->isAttacking){
        this->animation[2].play("PLAYER_ATTACK",deltaTime,this->row,true);
        if(this->animation[2].isDone("PLAYER_ATTACK")){
            this->isAttacking=false;
            this->sprite.setOrigin(0.0f,0.0f);
        }
    }
}


void Player::update(const float &deltaTime)
{
    if(!this->isAttacking)
    this->movement->update(deltaTime);

    if(this->movement->isStopped()){
        this->animation[0].play("PLAYER_NEUTRAL",deltaTime,this->row);
    }else{
        this->animation[1].play("PLAYER_RUN",deltaTime,this->row);
    }

    this->updateAttack();
    this->updateAnimation(deltaTime);

    this->hitbox->update();

}

/*
//Collider Player::GetCollider() {return Collider(body);}

sf::Vector2f Player::GetPosition()
{
    sf::Vector2f pos=body.getPosition();
    pos.x+=body.getOrigin().x;
    pos.y+=body.getOrigin().y;
    return pos;
}*/
