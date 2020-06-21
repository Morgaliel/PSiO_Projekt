#ifndef ENEMY_H
#define ENEMY_H
#include <character.h>

class Enemy:public Character
{
public:
    Enemy();
    virtual ~Enemy();

    //virtual void updateAttack();
    //virtual void updateAnimation(const float &deltaTime);

    virtual void loseHP(const int hp, const float& deltaTime);
    virtual void gainHP(const int hp);
    virtual void update(const float &deltaTime)=0;
    virtual void setRenderNum(int x);
    virtual int getRenderNum() const;

protected:
    int enemyType;
    int renderNum=0;
};

#endif // ENEMY_H
