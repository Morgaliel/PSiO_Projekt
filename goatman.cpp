#include "goatman.h"

Goatman::Goatman(sf::Vector2f position, std::map<std::string, sf::Texture> &textures)
{
    this->enemyType=1;
    this->hpMax=100;
    this->hp=10;
    this->attackDmg=5;
    this->setDie(false);
    this->setPosition(position);
    this->createHitbox(this->sprite,sf::FloatRect(15,5,40.0f,70.0f));
    this->createHitbox(this->sprite,sf::FloatRect(15,50,40.0f,25.0f),2);
    this->createMove(50.0f);

    this->createAnimation(textures["GOATMAN_NEUTRAL"]);
    this->createAnimation(textures["GOATMAN_WALK"]);
    this->createAnimation(textures["GOATMAN_ATTACK"]);
    this->createAnimation(textures["GOATMAN_DIE"]);

    //creating animation (I FORGOT TWICE): load texture, createAnimation, addAnimation
    this->animation[0].addAnimation("GOATMAN_NEUTRAL",sf::Vector2u(10,8),0.1f);
    this->animation[1].addAnimation("GOATMAN_WALK",sf::Vector2u(8,8),0.1f);
    this->animation[2].addAnimation("GOATMAN_ATTACK",sf::Vector2u(16,8),0.05f);
    this->animation[3].addAnimation("GOATMAN_DIE",sf::Vector2u(19,8),0.06f);
}

Goatman::~Goatman()
{

}

/*void Enemy::updateAttack()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->isAttacking=true;
        this->sprite.setOrigin(15.0f,3.0f);
    }
}*/

/*void Enemy::updateAnimation(const float &deltaTime)
{
    if(this->isAttacking){
        this->animation[2].play("GOATMAN_ATTACK",deltaTime,this->row,true);
        if(this->animation[2].isDone("GOATMAN_ATTACK")){
            this->isAttacking=false;
            this->sprite.setOrigin(0.0f,0.0f);
        }
    }
}*/

void Goatman::loseHP(const int hp, const float& deltaTime)
{
    this->hp-=hp;

    if(this->hp<=0){
        this->hp=0;

    }
}

void Goatman::update(const float &deltaTime)
{
    if(!this->isAttacking)
    this->movement->update(deltaTime);

    if(this->movement->isStopped()){
        this->animation[0].play("GOATMAN_NEUTRAL",deltaTime,this->row);
    }else{
        this->animation[1].play("GOATMAN_WALK",deltaTime,this->row);
    }

    if(this->hp==0){
        this->sprite.setOrigin(38.0f,30.0f);
        this->animation[3].play("GOATMAN_DIE",deltaTime,this->row,true);
        if(this->animation[3].isDone("GOATMAN_DIE")){
            this->sprite.setOrigin(0.0f,0.0f);
            hp=1;
            this->setDie(true);
        }
    }
    //this->updateAttack();
    //this->updateAnimation(deltaTime);


}
