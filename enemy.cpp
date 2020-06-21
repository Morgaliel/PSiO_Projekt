#include "enemy.h"

Enemy::Enemy()
{
    this->setDie(false);
    characterType=1;
    row=0;
}

Enemy::~Enemy()
{

}

void Enemy::loseHP(const int hp)
{
    this->hp-=hp;

    if(this->hp<0){
        this->hp=0;
    }
}

void Enemy::gainHP(const int hp)
{
    this->hp+=hp;

    if(this->hp>hpMax){
        this->hp=hpMax;
    }
}

void Enemy::setRenderNum(int x)
{
    renderNum=x;
}

int Enemy::getRenderNum() const
{
    return renderNum;
}

