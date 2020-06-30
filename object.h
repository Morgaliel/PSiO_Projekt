#ifndef OBJECT_H
#define OBJECT_H
#include <enemy.h>

class Object:public Enemy
{
public:
    Object(sf::Vector2f position,std::map<std::string, sf::Texture> &textures, int type);
    virtual ~Object();


    void update(const float& deltaTime);
    virtual void updateAttack();
    virtual void updateAnimation(const float &deltaTime);
    int getType();
protected:
    int objectType;
};

#endif // OBJECT_H
