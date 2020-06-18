#ifndef ANIMATION_H
#define ANIMATION_H

class Animation{
private:
    class Animate{
    public:
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float totalTime;
        float switchTime;
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        sf::IntRect uvRect;
        bool done;

        Animate(sf::Sprite& sprite,sf::Texture& textureSheet,sf::Vector2u imageCount, float switchTime):sprite(sprite),textureSheet(textureSheet),totalTime(0),done(false){
            this->imageCount=imageCount;
            this->switchTime=switchTime;
            currentImage.x=0;
            currentImage.y=0;
            uvRect.width=textureSheet.getSize().x/float(this->imageCount.x);
            uvRect.height=textureSheet.getSize().y/float(this->imageCount.y)+1;
        }
        ~Animate(){};

        const bool& isDone() const{
            return this->done;
        }

        const bool& play(const float& deltaTime, unsigned int row){
            this->done=false;
            currentImage.y=row;
            totalTime+=deltaTime;
            if(totalTime>=switchTime){
                totalTime-=switchTime;
                currentImage.x++;
                    if(currentImage.x>=imageCount.x){
                        currentImage.x=0;
                        this->done=true;
                    }

            }
            uvRect.top=currentImage.y*uvRect.height;
            uvRect.left=currentImage.x*uvRect.width;
            uvRect.width=abs(uvRect.width);
            this->sprite.setTexture(this->textureSheet,true);
            this->sprite.setTextureRect(this->uvRect);

            return this->done;
        };
        void reset(){
            totalTime=0.0f; //=switchTime;
            currentImage.x=0;
        }
    };

    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string,Animate*> animations;
    Animate* lastAnimation;
    Animate* priorityAnimation;


public:
    Animation(sf::Sprite& sprite,sf::Texture& textureSheet);
    virtual ~Animation();

    const bool& isDone(const std::string key);

    void addAnimation(const std::string key,sf::Vector2u imageCount, float switchTime);
    void play(const std::string key,const float& deltaTime,unsigned int row, const bool priority=false);

    //sf::IntRect uvRect;

};

#endif // ANIMATION_H
