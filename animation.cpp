#include "animation.h"

Animation::Animation(sf::Sprite& sprite,sf::Texture& textureSheet):sprite(sprite),textureSheet(textureSheet),lastAnimation(nullptr)
{

}

Animation::~Animation()
{
    for(auto &it:this->animations){
        delete it.second;
    }
}

void Animation::addAnimation(const std::string key,sf::Vector2u imageCount, float switchTime)
{
    this->animations[key]= new Animate(this->sprite,this->textureSheet,imageCount,switchTime);
}

void Animation::play(const std::string key,const float& deltaTime,unsigned int row)
{
    if(this->lastAnimation!=this->animations[key]){
        if(this->lastAnimation==nullptr){
            this->lastAnimation=this->animations[key];
        }else{
            this->lastAnimation->reset();
            this->lastAnimation=this->animations[key];
        }
    }

    this->animations[key]->play(deltaTime,row);
}
