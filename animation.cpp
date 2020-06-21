#include "animation.h"

Animation::Animation(sf::Sprite& sprite,sf::Texture& textureSheet):sprite(sprite),textureSheet(textureSheet),lastAnimation(nullptr),priorityAnimation(nullptr)
{

}

Animation::~Animation()
{
    for(auto &it:this->animations){
        delete it.second;
    }
}

const bool &Animation::isDone(const std::string key)
{
    return this->animations[key]->isDone();
}

void Animation::addAnimation(const std::string key,sf::Vector2u imageCount, float switchTime)
{
    this->animations[key]= new Animate(this->sprite,this->textureSheet,imageCount,switchTime);
}

void Animation::play(const std::string key,const float& deltaTime,unsigned int row, const bool priority)
{

        if(this->priorityAnimation){
            if(this->priorityAnimation==this->animations[key]){
                if(this->lastAnimation!=this->animations[key]){
                    if(this->lastAnimation==nullptr){
                        this->lastAnimation=this->animations[key];
                    }else{
                        this->lastAnimation->reset();
                        this->lastAnimation=this->animations[key];
                    }
                }

                if(this->animations[key]->play(deltaTime,row)){
                    this->priorityAnimation=nullptr;
                }
            }
        }else{
            if(priority){
                this->priorityAnimation=this->animations[key];
            }
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

}
