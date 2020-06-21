#include "tilemap.h"

Tilemap::Tilemap()
{

}

bool Tilemap::load(sf::Texture& texture, std::vector<int> tiles, unsigned int width, unsigned int height,sf::Vector2i tileSize, sf::Vector2i vOrigin, int lvl)
{
    m_tileset=texture;
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);
    vOrigin=vOrigin*lvl;

    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {

            int tileNumber = tiles[i + j * width];
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            if(tileSize.y==320){
                quad[0].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4)-240)+j * tileSize.y+i*(tileSize.y/2-120)-j*(tileSize.y/2+120));
                quad[1].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4)-240)+j * tileSize.y+i*(tileSize.y/2-120)-j*(tileSize.y/2+120));
                quad[2].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4)-240)+(j + 1) * tileSize.y+i*(tileSize.y/2-120)-j*(tileSize.y/2+120));
                quad[3].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4)-240)+(j + 1) * tileSize.y+i*(tileSize.y/2-120)-j*(tileSize.y/2+120));
            }else if(tileSize.y==385){
                quad[0].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4.8125)-288.75)+j * tileSize.y+i*(tileSize.y/2-150)-j*(tileSize.y/2+150));
                quad[1].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4.8125)-288.75)+j * tileSize.y+i*(tileSize.y/2-150)-j*(tileSize.y/2+150));
                quad[2].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4.8125)-288.75)+(j + 1) * tileSize.y+i*(tileSize.y/2-150)-j*(tileSize.y/2+150));
                quad[3].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/4.8125)-288.75)+(j + 1) * tileSize.y+i*(tileSize.y/2-150)-j*(tileSize.y/2+150));
            }
            else if(tileSize.y==640){
                quad[0].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/8)-560)+j * tileSize.y+i*(tileSize.y/4-120)-j*(tileSize.y/4+440));
                quad[1].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/8)-560)+j * tileSize.y+i*(tileSize.y/4-120)-j*(tileSize.y/4+440));
                quad[2].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/8)-560)+(j + 1) * tileSize.y+i*(tileSize.y/4-120)-j*(tileSize.y/4+440));
                quad[3].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, ((vOrigin.y*tileSize.y/8)-560)+(j + 1) * tileSize.y+i*(tileSize.y/4-120)-j*(tileSize.y/4+440));
            }else{
                quad[0].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, (vOrigin.y*tileSize.y)+j * tileSize.y+i*tileSize.y/2-j*tileSize.y/2);
                quad[1].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, (vOrigin.y*tileSize.y)+j * tileSize.y+i*tileSize.y/2-j*tileSize.y/2);
                quad[2].position = sf::Vector2f((vOrigin.x*tileSize.x)+(i + 1) * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, (vOrigin.y*tileSize.y)+(j + 1) * tileSize.y+i*tileSize.y/2-j*tileSize.y/2);
                quad[3].position = sf::Vector2f((vOrigin.x*tileSize.x)+i * tileSize.x-i*tileSize.x/2-j*tileSize.x/2, (vOrigin.y*tileSize.y)+(j + 1) * tileSize.y+i*tileSize.y/2-j*tileSize.y/2);
            }

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}


void Tilemap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices, states);
}
