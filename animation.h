#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>


class Animation{
public:
    Animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);
    ~Animation();

    void Update(sf::Texture* texture, unsigned int row, float deltaTime);

    sf::IntRect uvRect;
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};

#endif // ANIMATION_H
