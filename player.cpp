#include "player.h"

void Player::initVariables()
{

}

void Player::initComponents()
{

}

Player::Player(sf::Vector2f position, std::map<std::string, sf::Texture> &textures){

    characterType=0;
    this->initVariables();
    this->exp=0;
    this->hpMax=300;
    this->hp=300;
    this->attackDmg=15;
    this->range=60.0f;
    this->isAttacking=false;
    this->setDie(false);
    row=0;

    this->setPosition(position);

    this->createHitbox(this->sprite,sf::FloatRect(15,15,40.0f,70.0f));
    this->createHitbox(this->sprite,sf::FloatRect(15,60,40.0f,25.0f),2);
    this->createMove(250.0f);
    this->createAnimation(textures["PLAYER_NEUTRAL"]);
    this->createAnimation(textures["PLAYER_RUN"]);
    this->createAnimation(textures["PLAYER_ATTACK"]);

    //creating animation (I FORGOT TWICE): load texture, createAnimation, addAnimation
    this->animation[0].addAnimation("PLAYER_NEUTRAL",sf::Vector2u(8,16),0.1f);
    this->animation[1].addAnimation("PLAYER_RUN",sf::Vector2u(8,16),0.09f);
    this->animation[2].addAnimation("PLAYER_ATTACK",sf::Vector2u(15,16),0.04f);

}

Player::~Player(){}

void Player::loseHP(const int hp, const float deltaTime)
{
    this->hp-=hp;

    if(this->hp<0){
        this->hp=0;
    }
}

void Player::gainHP(const int hp)
{
    this->hp+=hp;

    if(this->hp>hpMax){
        this->hp=hpMax;
    }
}

void Player::updateAttack()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        this->isAttacking=true;
        this->sprite.setOrigin(44.0f,14.0f);

    }
}

void Player::updateAnimation(const float &deltaTime)
{

    if(this->isAttacking){
        this->animation[2].play("PLAYER_ATTACK",deltaTime,this->row,true);
        this->attack=true;
        if(this->one==1){
            attack=false;
        }else{
            this->one=1;
        }
        if(this->animation[2].isDone("PLAYER_ATTACK")){
            this->isAttacking=false;
            this->one=0;
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
        this->attack=false;
    }else{
        this->animation[1].play("PLAYER_RUN",deltaTime,this->row);
        this->attack=false;
    }

    this->updateAttack();
    this->updateAnimation(deltaTime);


}

bool Player::getAtck()
{
    return attack;
}

bool Player::getAttacking()
{
    return isAttacking;
}
