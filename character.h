#ifndef CHARACTER_H
#define CHARACTER_H
#include <move.h>
#include <animation.h>
#include <hitbox.h>


class Character:public sf::Sprite
{
public:
    Character();
    virtual ~Character();

    void setTexture(sf::Texture& texture);
    void createHitbox(sf::Sprite& sprite,sf::FloatRect position,int which=1);
    void createMove(const float speed);
    void createAnimation(sf::Texture& textureSheet);

    void setRow(unsigned int row);
    unsigned int getRow();
    virtual void setPosition(const sf::Vector2f position);
    virtual const sf::Vector2f &getPosition() const;
    virtual void move(const sf::Vector2f direction,const float &deltaTime);

    virtual void setDie(bool die);
    virtual bool getDie();
    virtual void loseHP(const int hp)=0;
    virtual void gainHP(const int hp)=0;
    virtual float getDistance(const Character& character) const;
    virtual const sf::Vector2f getCenter() const;
    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderWindow& window);
    Hitbox* hitbox;
    Hitbox* hitboxAttack;

    int hp;
    int hpMax;
    int attackDmg;
    int exp;
    int range;
protected:
    sf::Sprite sprite;
    Move* movement;
    std::vector<Animation> animation;
    unsigned int row;
    int characterType;
    bool isDied;



private:
    void initVariables();
};

#endif // CHARACTER_H
