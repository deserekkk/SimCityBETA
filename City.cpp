#include "City.h"


City::City(std::string name, const unsigned int w, const unsigned int h, const unsigned int tile_size,
           const std::map<std::string, std::unique_ptr<sf::Texture>> &textures) : name(
        std::move(name)), map(Map(w, h, tile_size, textures)), dayLength(1.f), currentTime(0.f) {

}

City::~City() = default;
