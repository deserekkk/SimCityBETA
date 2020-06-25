#include <map>
#include "Map.h"

Map::Map(unsigned int width, unsigned int height, unsigned int tileSize,
         const std::map<std::string, std::unique_ptr<sf::Texture>> &textures) : width(width), height(height),
                                                                                tileSize(tileSize) {
    forest = Tile(*(textures.at("forest")));
    grass = Tile(*(textures.at("grass")));
    iron = Tile(*(textures.at("iron")));
    kostka = Tile(*(textures.at("kostka")));
    water = Tile(*(textures.at("water")));
    for (int i = 0; i < 100; ++i) {
        this->tiles.emplace_back(*(textures.at("grass")));
    }
}

void Map::draw(sf::RenderWindow &window, const sf::Time dt) {
    for (int y = 0; y < this->height; ++y)
        for (int x = 0; x < this->height; ++x) {
            sf::Vector2f pos;
            pos.x = x * this->tileSize;
            pos.y = y * this->tileSize;
            this->tiles[y * this->width + x].sprite.setPosition(pos);
            this->tiles[y * this->width + x].draw(window, dt);
        }
}

void Map::changeTile(const unsigned int x, const unsigned int y, const unsigned int c) {
    if (x >= this->width || x < 0 || y >= this->height || y < 0)
        return;
    switch (c) {
        case 1: {
            this->tiles[y * this->width + x] = kostka;
            break;
        }
        case 2: {
            this->tiles[y * this->width + x] = forest;
            break;
        }
        case 3: {
            this->tiles[y * this->width + x] = water;
            break;
        }
        default: {
            break;
        }
    }
}
