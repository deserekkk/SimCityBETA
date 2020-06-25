#include "Tile.h"


Tile::~Tile() = default;

void Tile::draw(sf::RenderWindow &window, const sf::Time dt) const {
    window.draw(this->sprite);
}

Tile::Tile(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

Tile::Tile() {
}

//Tile::Tile(const unsigned int tileSize, sf::Texture &texture,
//           const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel,
//           const unsigned int maxLevels)
//        : tileType(tileType), cost(cost), population(0),
//          maxPopPerLevel(maxPopPerLevel), maxLevels(maxLevels), production(0),
//          storedGoods(0) {
//    this->sprite.setTexture(texture);
//}
//
//void Tile::draw(sf::RenderWindow &window, const float dt) {
//    // rzeczy z animacjami jakos wymyslec
//
//    window.draw(this->sprite);
//}
//
//void Tile::update() {
//    // jesli max pop albo max level to cos zmien...
//}
//
//std::string Tile::getCost() const {
//    return std::to_string(this->cost);
//}
