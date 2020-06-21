#ifndef COLLIDER_H
#define COLLIDER_H

namespace collision
{
bool satRectangleAndPoints(const sf::Vector2f rectangleSize, const std::array<sf::Vector2f, 4>& points);

template <class T1, class T2, class T3>
bool areColliding(const T1& object1, const T2& object2, T3& object3,const float &deltaTime,float rotation, const int collisionLevel = -1)
{
    // LEVEL 0 (axis-aligned bounding box)

    if(collisionLevel==0){
    sf::Vector2f otherPosition = object1->getPosition();
    sf::Vector2f thisPosition = object2->getPosition();
    sf::Vector2f otherHalfSize = sf::Vector2f(object1->getSize().x/2.0f,object1->getSize().y/2.0f);
    sf::Vector2f thisHalfSize = sf::Vector2f(object2->getSize().x/2.0f,object2->getSize().y/2.0f);


    float deltaX=otherPosition.x-thisPosition.x;
    float deltaY=otherPosition.y-thisPosition.y;
    float intersectX=fabs(deltaX)-(otherHalfSize.x+thisHalfSize.x);
    float intersectY=fabs(deltaY)-(otherHalfSize.y+thisHalfSize.y);

        if(intersectX<0.0f && intersectY<0.0f){

            if(intersectX>intersectY){
                if(deltaX>0.0f){
                    object3->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
                }else{
                    object3->move(sf::Vector2f(1.0f,0.0f),deltaTime);
                }
            }else{
                if(deltaY>0.0f){
                    object3->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
                }else{
                    object3->move(sf::Vector2f(0.0f,1.0f),deltaTime);
                }
            }
        }
    }
    const bool level0{object1->getGlobalBounds().intersects(object2->getGlobalBounds())};
    if (!level0 || collisionLevel == 0){
        return level0;
    }


    // LEVEL 1 (any corners inside opposite rectangle)
    const sf::Transform transform1{ object1->getTransform() };
    const sf::Transform transform2{ object2->getTransform() };
    const sf::Transform inverseTransform1{ object1->getInverseTransform() };
    const sf::Transform inverseTransform2{ object2->getInverseTransform() };
    const sf::FloatRect rect1Bounds( object1->getLocalBounds() );
    const sf::FloatRect rect2Bounds{ object2->getLocalBounds() };
    const sf::Vector2f rect1Size{ rect1Bounds.width, rect1Bounds.height };
    const sf::Vector2f rect2Size{ rect2Bounds.width, rect2Bounds.height };
    const sf::Vector2f rect1TopLeft{ inverseTransform2.transformPoint(transform1.transformPoint({ 0.f, 0.f })) };
    const sf::Vector2f rect1TopRight{ inverseTransform2.transformPoint(transform1.transformPoint({ rect1Size.x, 0.f })) };
    const sf::Vector2f rect1BottomRight{ inverseTransform2.transformPoint(transform1.transformPoint(rect1Size)) };
    const sf::Vector2f rect1BottomLeft{ inverseTransform2.transformPoint(transform1.transformPoint({ 0.f, rect1Size.y })) };
    const sf::Vector2f rect2TopLeft{ inverseTransform1.transformPoint(transform2.transformPoint({ 0.f, 0.f })) };
    const sf::Vector2f rect2TopRight{ inverseTransform1.transformPoint(transform2.transformPoint({ rect2Size.x, 0.f })) };
    const sf::Vector2f rect2BottomRight{ inverseTransform1.transformPoint(transform2.transformPoint(rect2Size)) };
    const sf::Vector2f rect2BottomLeft{ inverseTransform1.transformPoint(transform2.transformPoint({ 0.f, rect2Size.y })) };


    // LEVEL 2 (SAT)
    std::array<sf::Vector2f, 4> rect1Points
    {
        rect1BottomLeft,
        rect1BottomRight,
        rect1TopRight,
        rect1TopLeft,
    };
    //needed to debug
    //std::cout<<"BOTL1 "<<rect1BottomLeft.x<<"        "<<rect1BottomLeft.y<<std::endl;
    //std::cout<<"BOTR1 "<<rect1BottomRight.x<<"        "<<rect1BottomRight.y<<std::endl;
    //std::cout<<"TOPL1 "<<rect1TopLeft.x<<"        "<<rect1TopLeft.y<<std::endl;
    //std::cout<<"TOPR1 "<<rect1TopRight.x<<"        "<<rect1TopRight.y<<std::endl;
    if (!satRectangleAndPoints(rect2Size, rect1Points)){
        return false;
    }
    std::array<sf::Vector2f, 4> rect2Points
    {
        rect2BottomLeft,
        rect2BottomRight,
        rect2TopRight,
        rect2TopLeft,
    };
    //needed to debug
    //std::cout<<"BOTL2 "<<rect2BottomLeft.x<<"        "<<rect2BottomLeft.y<<std::endl;
    //std::cout<<"BOTR2 "<<rect2BottomRight.x<<"        "<<rect2BottomRight.y<<std::endl;
    //std::cout<<"TOPL2 "<<rect2TopLeft.x<<"        "<<rect2TopLeft.y<<std::endl;
    //std::cout<<"TOPR2 "<<rect2TopRight.x<<"        "<<rect2TopRight.y<<std::endl;

    if(!satRectangleAndPoints(rect1Size, rect2Points)){
    }
    const bool level1{ (
        (rect1Bounds.contains(rect2TopLeft)) ||
        (rect1Bounds.contains(rect2TopRight)) ||
        (rect1Bounds.contains(rect2BottomLeft)) ||
        (rect1Bounds.contains(rect2BottomRight)) ||
        (rect2Bounds.contains(rect1TopLeft)) ||
        (rect2Bounds.contains(rect1TopRight)) ||
        (rect2Bounds.contains(rect1BottomLeft)) ||
        (rect2Bounds.contains(rect1BottomRight))) };
    if (level1 || collisionLevel == 1){

        //rotation 0
        if(rotation==0.0f){
            //bottom
            if(rect2BottomLeft.y>0&&rect2BottomRight.y>0&&rect2TopLeft.y>0&&rect2TopRight.y>0){
                object3->move(sf::Vector2f(0.0f,0.5f),deltaTime);
            }
            //left
            else if(rect2BottomLeft.x<0&&rect2BottomRight.x>0&&rect2TopLeft.x<0&&rect2TopRight.x>0){
                object3->move(sf::Vector2f(-0.5f,0.0f),deltaTime);
            }
            //right
            else if(rect2BottomLeft.x>0&&rect2BottomRight.x>0&&rect2TopLeft.x>0&&rect2TopRight.x>0){
                object3->move(sf::Vector2f(0.5f,0.0f),deltaTime);
            }
            //top
            else if(rect2BottomLeft.y>0&&rect2BottomRight.y>0&&rect2TopLeft.y<0&&rect2TopRight.y<0){
                object3->move(sf::Vector2f(0.0f,-0.5f),deltaTime);
            }
        }
        //rotation 334
        if(rotation==334.0f){
            //left
            if(rect2BottomLeft.x<0&&rect2BottomRight.x<0&&rect2TopLeft.x<0&&rect2TopRight.x>0){
                object3->move(sf::Vector2f(-0.5f,0.0f),deltaTime);
            }
            //top
            else if(rect2BottomLeft.y<0&&rect2BottomRight.y>0&&rect2TopLeft.y<0&&rect2TopRight.y<0){
                object3->move(sf::Vector2f(0.0f,-0.5f),deltaTime);
            }
            //right
            else if(rect2BottomLeft.x>0&&rect2BottomRight.x>0&&rect2TopLeft.x>0&&rect2TopRight.x>0){
                object3->move(sf::Vector2f(0.5f,0.0f),deltaTime);
            }
            //bottom
            else if(rect2BottomLeft.y>0&&rect2BottomRight.y>0&&rect2TopLeft.y>0&&rect2TopRight.y>0){
                object3->move(sf::Vector2f(0.0f,0.5f),deltaTime);
            }
        }
        //rotation 207
        if(rotation==207){
            //right
            if(rect2BottomLeft.x<0&&rect2BottomRight.x<0&&rect2TopLeft.x>0&&rect2TopRight.x<0){
                object3->move(sf::Vector2f(0.5f,0.0f),deltaTime);
            }
            //top
            else if(rect2BottomLeft.y>0&&rect2BottomRight.y>0&&rect2TopLeft.y>0&&rect2TopRight.y>0){
                object3->move(sf::Vector2f(0.0f,-0.5f),deltaTime);
            }
            //left
            else if(rect2BottomLeft.x>0&&rect2BottomRight.x>0&&rect2TopLeft.x>0&&rect2TopRight.x>0){
                object3->move(sf::Vector2f(-0.5f,0.0f),deltaTime);
            }
            //bottom
            else if(rect2BottomLeft.y<0&&rect2BottomRight.y<0&&rect2TopLeft.y<0&&rect2TopRight.y>0){
                object3->move(sf::Vector2f(0.0f,0.5f),deltaTime);
            }
        }

        return level1;
    }
    return satRectangleAndPoints(rect1Size, rect2Points);
}

bool satRectangleAndPoints(const sf::Vector2f rectangleSize, const std::array<sf::Vector2f, 4>& points)
{
    bool allPointsLeftOfRectangle{ true };
    bool allPointsRightOfRectangle{ true };
    bool allPointsAboveRectangle{ true };
    bool allPointsBelowRectangle{ true };
    for (auto& point : points)
    {
        if (point.x >= 0.f)
            allPointsLeftOfRectangle = false;
        if (point.x <= rectangleSize.x)
            allPointsRightOfRectangle = false;
        if (point.y >= 0.f)
            allPointsAboveRectangle = false;
        if (point.y <= rectangleSize.y)
            allPointsBelowRectangle = false;
    }
    return !(allPointsLeftOfRectangle || allPointsRightOfRectangle || allPointsAboveRectangle || allPointsBelowRectangle);
}

}

#endif // COLLIDER_H
