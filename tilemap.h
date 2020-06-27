#ifndef TILEMAP_H
#define TILEMAP_H


class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
    Tilemap();
    bool load(sf::Texture& texture, std::vector<int> tiles, unsigned int width, unsigned int height,sf::Vector2i tileSize, sf::Vector2i vOrigin, int lvl);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Vector2u tileSize;
    sf::Vector2i vOrigin;
};


#endif // TILEMAP_H
