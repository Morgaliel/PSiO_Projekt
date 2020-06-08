#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <player.h>
#include <wall.h>

static const float VIEW_HEIGHT=720.0f;

void ResizeView(const sf::RenderWindow &window,sf::View &view){
    float aspectRatio=float(window.getSize().x)/float(window.getSize().y);

    view.setSize(VIEW_HEIGHT*aspectRatio,VIEW_HEIGHT);
}

int main() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,VIEW_HEIGHT));
    // create some shapes
    //grass
    sf::Texture textureSky;
    if (!textureSky.loadFromFile("D:/STUDIA/PSiO/QTProjekty/GraProjekt/images/sky.png")) {
        std::cerr << "Could not load grass" << std::endl;
    }
    textureSky.setRepeated(true);

    sf::Sprite sky;
    sky.setTexture(textureSky);
    sky.setScale(1.0f, 3.0f);
    sky.setTextureRect(sf::IntRect(0, 0, 1280, 720));

    //hero
    sf::Texture tex;
    tex.loadFromFile("D:/STUDIA/PSiO/QTProjekty/GraProjekt/images/paladin_neutral.png");


    Player hero(&tex,sf::Vector2u(8,16),0.1f,200.0f);
    hero.setBounds(0, window.getSize().y, 0, window.getSize().x);

    //walls
    sf::Texture textureWall;
    if(!textureWall.loadFromFile("D:/STUDIA/PSiO/QTProjekty/GraProjekt/images/wall.png")) {
        std::cerr << "Could not load wall" << std::endl;
    }
    textureWall.setRepeated(true);

    std::vector<Wall> walls;

    walls.push_back(Wall(&textureWall,sf::Vector2f(250.0,100.0),sf::Vector2f(450.0f,480.0f)));
    walls.push_back(Wall(&textureWall,sf::Vector2f(300.0f,100.0f),sf::Vector2f(400.0f,180.0f)));
    walls.push_back(Wall(&textureWall,sf::Vector2f(250.0f,100.0f),sf::Vector2f(860.0f,380.0f)));
    walls.push_back(Wall(&textureWall,sf::Vector2f(3500.0f,150.0f),sf::Vector2f(640.0f,690.0f)));


    sf::Clock clock;
    sf::Clock animation_clock;
    float deltaTime=0.0f;
    // run the program as long as the window is open
    while (window.isOpen()) {
        //sf::Time elapsed = clock.restart();
        deltaTime=animation_clock.restart().asSeconds();
        if(deltaTime>1.0f/20.0f){
            deltaTime=1.0f/20.0f;
        }
        sf::Event event;
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
                    }
                }
            if(event.type == sf::Event::Resized){
                ResizeView(window,view);
            }
        }

        hero.Update(deltaTime);
        view.setCenter(hero.GetPosition());

        Collider col=hero.GetCollider();
        for(Wall& p:walls){
            p.GetCollider().CheckCollision(col,1.0f);
        }



        // clear the window with black color
        window.clear(sf::Color::Black);
        window.setView(view);
        // draw everything here...
        window.draw(sky);
        hero.Draw(window);
        for(Wall& p:walls){
            p.Draw((window));
        }

        // end the current frame
        window.display();
    }

    return 0;
}
