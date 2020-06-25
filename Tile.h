#ifndef SIMCITYBETA_TILE_H
#define SIMCITYBETA_TILE_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

//enum class TileType {
//    VOID, GRASS, FOREST, WATER, RESIDENTIAL, COMMERCIAL, INDUSTRIAL, ROAD
//};

class Tile {
public:
    sf::Sprite sprite;

    explicit Tile(sf::Texture &texture);

    Tile();

    virtual ~Tile();

    void draw(sf::RenderWindow &window, sf::Time dt) const;
};


#endif //SIMCITYBETA_TILE_H
