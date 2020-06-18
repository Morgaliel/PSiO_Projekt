#include "collider.h"

Collider::Collider(sf::RectangleShape& body):body(body){}

Collider::~Collider(){}

void Collider::Move(float dx, float dy){body.move(dx,dy);}

bool Collider::CheckCollision(Collider &other){
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX=otherPosition.x-thisPosition.x;
    float deltaY=otherPosition.y-thisPosition.y;
    float intersectX=fabs(deltaX)-(otherHalfSize.x+thisHalfSize.x);
    float intersectY=fabs(deltaY)-(otherHalfSize.y+thisHalfSize.y);

    if(intersectX<0.0f && intersectY<0.0f){

        if(intersectX>intersectY){
            if(deltaX>0.0f){
                Move(0.0f,0.0f);
                other.Move(-intersectX,0.0f);
            }else{
                Move(0.0f,0.0f);
                other.Move(intersectX,0.0f);
            }
        }else{
            if(deltaY>0.0f){
                Move(0.0f,0.0f);
                other.Move(0.0f,-intersectY);
            }else{
                Move(0.0f,0.0f);
                other.Move(0.0f,intersectY);
            }
        }

        return true;
    }

    return false;
}

sf::Vector2f Collider::GetPosition(){return body.getPosition();}

sf::Vector2f Collider::GetHalfSize(){return body.getSize()/2.0f;}
