#include "skeleton.h"

Skeleton::Skeleton(sf::Vector2f position, std::map<std::string, sf::Texture> &textures)
{
    this->enemyType=1;
    this->hpMax=30;
    this->hp=30;
    this->attackDmg=10;
    this->isAttacking=false;
    this->setDie(false);
    this->setPosition(position);
    this->createHitbox(this->sprite,sf::FloatRect(42,25,36.0f,70.0f));
    this->createHitbox(this->sprite,sf::FloatRect(42,70,36.0f,25.0f),2);
    this->createMove(130.0f);

    this->createAnimation(textures["SKELETON_NEUTRAL"]);
    this->createAnimation(textures["SKELETON_WALK"]);
    this->createAnimation(textures["SKELETON_ATTACK"]);
    this->createAnimation(textures["SKELETON_DIE"]);

    //creating animation (I FORGOT TWICE): load texture, createAnimation, addAnimation
    this->animation[0].addAnimation("SKELETON_NEUTRAL",sf::Vector2u(13,8),0.1f);
    this->animation[1].addAnimation("SKELETON_WALK",sf::Vector2u(8,8),0.08f);
    this->animation[2].addAnimation("SKELETON_ATTACK",sf::Vector2u(12,8),0.05f);
    this->animation[3].addAnimation("SKELETON_DIE",sf::Vector2u(15,8),0.1f);
}

Skeleton::~Skeleton()
{

}
void Skeleton::updateAttack()
{
        this->isAttacking=true;
        this->sprite.setOrigin(0.0f,0.0f);
}

void Skeleton::updateAnimation(const float &deltaTime)
{
    if(this->isAttacking&&hp>0){
        this->animation[2].play("SKELETON_ATTACK",deltaTime,this->row,true);
        this->attack=true;
        if(this->one==1){
            attack=false;
        }else{
            this->one=1;
        }
        if(this->animation[2].isDone("SKELETON_ATTACK")){
            this->sprite.setOrigin(0.0f,0.0f);
            this->isAttacking=false;
            this->one=0;
        }
    }
}


void Skeleton::loseHP(const int hp, const float deltaTime)
{
    this->hp-=hp;

    if(this->hp<=0){
        this->hp=0;
        update(deltaTime);
    }
}

void Skeleton::update(const float &deltaTime)
{
    if(!this->isAttacking)
    this->movement->update(deltaTime);



    if(this->movement->isStopped()){
        this->animation[0].play("SKELETON_NEUTRAL",deltaTime,this->row);
    }else{
        this->animation[1].play("SKELETON_WALK",deltaTime,this->row);
    }
    if(this->hp==0){

        this->sprite.setOrigin(0.0f,0.0f);
        this->animation[3].play("SKELETON_DIE",deltaTime,this->row,true);
        if(this->animation[3].isDone("SKELETON_DIE")){
            this->sprite.setOrigin(0.0f,0.0f);
            this->setDie(true);
        }
    }

    this->updateAnimation(deltaTime);


}
