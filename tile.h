#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>


class Tile
{
public:
    Tile(int X, int Y, sf::Color color);

    int X;
    int Y;

    sf::Color color;
};

#endif // TILE_H

// Position in the tileset
