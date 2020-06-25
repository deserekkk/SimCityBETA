#ifndef SIMCITYBETA_MAP_H
#define SIMCITYBETA_MAP_H


#include <vector>
#include "Tile.h"

class Map {
public:
    unsigned int width, height;
    unsigned int tileSize;

    Tile forest;
    Tile grass;
    Tile iron;
    Tile kostka;
    Tile water;

    Map(unsigned int width, unsigned int height, unsigned int tileSize,
        const std::map<std::string, std::unique_ptr<sf::Texture>> &textures);

    void draw(sf::RenderWindow &window, sf::Time dt);

    void changeTile(unsigned int x, unsigned int y, unsigned int choice);

private:
    std::vector<Tile> tiles;

};


#endif //SIMCITYBETA_MAP_H
