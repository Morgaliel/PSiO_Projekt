#include "animation.h"

Animation::Animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime)
{
    this->imageCount=imageCount;
    this->switchTime=switchTime;
    totalTime=0;
    currentImage.x=0;

    uvRect.width=texture->getSize().x/float(imageCount.x);
    uvRect.height=texture->getSize().y/float(imageCount.y)+1;
}

Animation::~Animation()
{

}

void Animation::Update(sf::Texture* texture, unsigned int row, float deltaTime){
    currentImage.y=row;
    totalTime += deltaTime;

    uvRect.width=texture->getSize().x/float(imageCount.x);
    uvRect.height=texture->getSize().y/float(imageCount.y)+1;

    if(totalTime>=switchTime){
        totalTime-=switchTime;
        currentImage.x++;
            if(currentImage.x>=imageCount.x){
                currentImage.x=0;
            }
    }
    uvRect.top=currentImage.y*uvRect.height;
    uvRect.left=currentImage.x*uvRect.width;
    uvRect.width=abs(uvRect.width);
}
