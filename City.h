#ifndef SIMCITYBETA_CITY_H
#define SIMCITYBETA_CITY_H


#include <utility>
#include <map>

#include "Map.h"

class City {
    std::string name;
    float currentTime;
    float dayLength;

public:
    Map map;

    explicit City(std::string name, unsigned int w, unsigned int h, unsigned int tile_size,
                  const std::map<std::string, std::unique_ptr<sf::Texture>> &textures);

    virtual ~City();
};


#endif //SIMCITYBETA_CITY_H
