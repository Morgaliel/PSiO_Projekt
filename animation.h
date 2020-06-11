#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <map>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Animation{
private:
    class Animate{
    public:
        Animate(sf::Sprite& sprite,sf::Texture& textureSheet,sf::Vector2u imageCount, float switchTime):sprite(sprite),textureSheet(textureSheet){
            this->imageCount=imageCount;
            this->switchTime=switchTime;
            totalTime=0;
            currentImage.x=0;
            currentImage.y=0;
            uvRect.width=textureSheet.getSize().x/float(this->imageCount.x);
            uvRect.height=textureSheet.getSize().y/float(this->imageCount.y)+1;
        }
        ~Animate(){};

        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float totalTime;
        float switchTime;
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        sf::IntRect uvRect;

        void play(const float& deltaTime, unsigned int row){
            currentImage.y=row;
            totalTime+=deltaTime;
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
            this->sprite.setTexture(this->textureSheet,true);
            this->sprite.setTextureRect(this->uvRect);
        };
        void reset(){
            totalTime=0.0f;
            currentImage.x=0;
        }
    };

    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string,Animate*> animations;
    Animate* lastAnimation;


public:
    Animation(sf::Sprite& sprite,sf::Texture& textureSheet);
    virtual ~Animation();

    void addAnimation(const std::string key,sf::Vector2u imageCount, float switchTime);
    void play(const std::string key,const float& deltaTime,unsigned int row);

    //sf::IntRect uvRect;

};

#endif // ANIMATION_H
