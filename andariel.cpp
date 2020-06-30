#include "andariel.h"

Andariel::Andariel(sf::Vector2f position, std::map<std::string, sf::Texture> &textures)
{
    this->enemyType=2;
    this->hpMax=150;
    this->hp=150;
    this->attackDmg=25;
    this->isAttacking=false;
    this->setDie(false);
    this->setPosition(position);
    this->createHitbox(this->sprite,sf::FloatRect(60,40,50.0f,135.0f));
    this->createHitbox(this->sprite,sf::FloatRect(60,140,50.0f,35.0f),2);
    this->createMove(120.0f);

    this->createAnimation(textures["ANDARIEL_NEUTRAL"]);
    this->createAnimation(textures["ANDARIEL_WALK"]);
    this->createAnimation(textures["ANDARIEL_ATTACK"]);
    this->createAnimation(textures["ANDARIEL_DIE"]);

    //creating animation (I FORGOT TWICE): load texture, createAnimation, addAnimation
    this->animation[0].addAnimation("ANDARIEL_NEUTRAL",sf::Vector2u(16,8),0.1f);
    this->animation[1].addAnimation("ANDARIEL_WALK",sf::Vector2u(12,8),0.1f);
    this->animation[2].addAnimation("ANDARIEL_ATTACK",sf::Vector2u(16,8),0.05f);
    this->animation[3].addAnimation("ANDARIEL_DIE",sf::Vector2u(23,8),0.1f);
}

Andariel::~Andariel()
{

}

void Andariel::updateAttack()
{
        this->isAttacking=true;
        this->sprite.setOrigin(33.0f,20.0f);
}

void Andariel::updateAnimation(const float &deltaTime)
{
    if(this->isAttacking&&hp>0){
        this->animation[2].play("ANDARIEL_ATTACK",deltaTime,this->row,true);
        this->attack=true;
        if(this->one==1){
            attack=false;
        }else{
            this->one=1;
        }
        if(this->animation[2].isDone("ANDARIEL_ATTACK")){
            this->sprite.setOrigin(0.0f,0.0f);
            this->isAttacking=false;
            this->one=0;
        }
    }
}


void Andariel::loseHP(const int hp, const float deltaTime)
{
    this->hp-=hp;

    if(this->hp<=0){
        this->hp=0;
        update(deltaTime);
    }
}

void Andariel::update(const float &deltaTime)
{


    if(!this->isAttacking)
    this->movement->update(deltaTime);



    if(this->movement->isStopped()){
        this->animation[0].play("ANDARIEL_NEUTRAL",deltaTime,this->row);
    }else{
        this->animation[1].play("ANDARIEL_WALK",deltaTime,this->row);
    }
    if(this->hp==0){

        this->sprite.setOrigin(25.0f,20.0f);
        this->animation[3].play("ANDARIEL_DIE",deltaTime,this->row,true);
        if(this->animation[3].isDone("ANDARIEL_DIE")){
            this->sprite.setOrigin(0.0f,0.0f);
            this->setDie(true);
        }
    }

    this->updateAnimation(deltaTime);


}
