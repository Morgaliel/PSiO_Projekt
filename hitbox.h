#ifndef HITBOX_H
#define HITBOX_H

class Hitbox:public sf::RectangleShape
{
public:
    Hitbox(sf::Sprite& sprite, sf::FloatRect position);
    virtual ~Hitbox();

    bool checkIntersect(const sf::FloatRect& frect);

    void update(bool isDied);
    sf::FloatRect getGlobalB();

    sf::FloatRect globalPosition;
private:
    sf::Sprite& sprite;
    sf::FloatRect position;
};

#endif // HITBOX_H
