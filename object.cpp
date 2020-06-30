#include "object.h"

Object::Object(sf::Vector2f position,std::map<std::string, sf::Texture> &textures, int type)
{
    this->enemyType=0;
    this->objectType=type;
    this->hpMax=10000;
    this->hp=10000;
    this->attackDmg=5;
    this->isAttacking=false;
    this->setDie(false);
    this->setPosition(position);
    if(objectType==0){
        this->createHitbox(this->sprite,sf::FloatRect(5,43,65.0f,30.0f),2);
    }
    if(objectType==1){
        this->createHitbox(this->sprite,sf::FloatRect(2,110,34.0f,30.0f),2);
    }
    if(objectType==2){
        this->createHitbox(this->sprite,sf::FloatRect(27,225,106.0f,65.0f),2);
    }
    if(objectType==3){
        this->createHitbox(this->sprite,sf::FloatRect(0,330,155.0f,5.0f),2);
    }
    if(objectType==4){
        this->createHitbox(this->sprite,sf::FloatRect(0,0,0.0f,0.0f),2);
    }
    if(objectType==5){
        this->createHitbox(this->sprite,sf::FloatRect(0,0,0.0f,0.0f),2);
    }
    if(objectType==6){
        this->createHitbox(this->sprite,sf::FloatRect(0,0,0.0f,0.0f),2);
    }
    if(objectType==7){
        this->createHitbox(this->sprite,sf::FloatRect(0,0,0.0f,0.0f),2);
    }
    if(objectType==8){
        this->createHitbox(this->sprite,sf::FloatRect(5,25,45.0f,30.0f),2);
    }
    if(objectType==9){
        this->createHitbox(this->sprite,sf::FloatRect(5,25,45.0f,30.0f),2);
    }
    if(objectType==10){
        this->createHitbox(this->sprite,sf::FloatRect(20,110,120.0f,40.0f),2);
    }
    this->createMove(0.0f);
    this->createAnimation(textures["BLOOD_VESSEL"]);
    this->createAnimation(textures["FIRE_COLUMN"]);
    this->createAnimation(textures["COLUMN"]);
    this->createAnimation(textures["ALTAR"]);
    this->createAnimation(textures["BENCH_1"]);
    this->createAnimation(textures["BENCH_2"]);
    this->createAnimation(textures["BENCH_3"]);
    this->createAnimation(textures["BENCH_4"]);
    this->createAnimation(textures["CANDLE_1"]);
    this->createAnimation(textures["CANDLE_2"]);
    this->createAnimation(textures["THRONE"]);

    this->animation[0].addAnimation("BLOOD_VESSEL",sf::Vector2u(6,1),0.1f);
    this->animation[1].addAnimation("FIRE_COLUMN",sf::Vector2u(19,1),0.1f);
    this->animation[2].addAnimation("COLUMN",sf::Vector2u(1,1),0.1f);
    this->animation[3].addAnimation("ALTAR",sf::Vector2u(1,1),0.1f);
    this->animation[4].addAnimation("BENCH_1",sf::Vector2u(1,1),0.1f);
    this->animation[5].addAnimation("BENCH_2",sf::Vector2u(1,1),0.1f);
    this->animation[6].addAnimation("BENCH_3",sf::Vector2u(1,1),0.1f);
    this->animation[7].addAnimation("BENCH_4",sf::Vector2u(1,1),0.1f);
    this->animation[8].addAnimation("CANDLE_1",sf::Vector2u(10,1),0.1f);
    this->animation[9].addAnimation("CANDLE_2",sf::Vector2u(10,1),0.1f);
    this->animation[10].addAnimation("THRONE",sf::Vector2u(1,1),0.1f);
}

Object::~Object()
{

}

void Object::update(const float &deltaTime)
{
    if(objectType==0){
        this->animation[0].play("BLOOD_VESSEL",deltaTime,this->row);
    }
    if(objectType==1){
        this->animation[1].play("FIRE_COLUMN",deltaTime,this->row);
    }
    if(objectType==2){
        this->animation[2].play("COLUMN",deltaTime,this->row);
    }
    if(objectType==3){
        this->animation[3].play("ALTAR",deltaTime,this->row);
    }
    if(objectType==4){
        this->animation[4].play("BENCH_1",deltaTime,this->row);
    }
    if(objectType==5){
        this->animation[5].play("BENCH_2",deltaTime,this->row);
    }
    if(objectType==6){
        this->animation[6].play("BENCH_3",deltaTime,this->row);
    }
    if(objectType==7){
        this->animation[7].play("BENCH_4",deltaTime,this->row);
    }
    if(objectType==8){
        this->animation[8].play("CANDLE_1",deltaTime,this->row);
    }
    if(objectType==9){
        this->animation[9].play("CANDLE_2",deltaTime,this->row);
    }
    if(objectType==10){
        this->animation[10].play("THRONE",deltaTime,this->row);
    }
}

void Object::updateAttack()
{

}

void Object::updateAnimation(const float &deltaTime)
{

}

int Object::getType()
{
    return objectType;
}
