#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& tileset, const int* tiles, unsigned int width, unsigned int height);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Vector2u tileSize;
};


#endif // TILEMAP_H
