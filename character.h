#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <player.h>
#include <wall.h>
#include <tilemap.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Character
{
public:
    Character();
    virtual ~Character();

    virtual void move(const float &deltaTime, const float x, const float y);

    virtual void update(const float& deltaTime)=0;
    virtual void render()=0;

protected:
    sf::RectangleShape shape;
    float speed;
private:

};

#endif // CHARACTER_H
