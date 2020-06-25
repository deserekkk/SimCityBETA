#ifndef SIMCITYBETA_GAMEPLAY_H
#define SIMCITYBETA_GAMEPLAY_H

#include "GameState.h"
#include "City.h"


class Gameplay : public GameState {

    sf::View cityView;
    sf::View guiView;

    float zoom;
    int buildChoice{};

    sf::Vector2i cameraMoveAnchor;

    std::unique_ptr<City> city;

    std::map<std::string, std::unique_ptr<sf::Texture>> textures;

    sf::Sprite background;

    bool moveCamera{};

public:

    explicit Gameplay(Game *game);

    void draw(sf::Time dt) override;

    void update(sf::Time dt) override;

    void updateInput() override;

    void initTextures();

    void updateGui(sf::Time dt);

};


#endif //SIMCITYBETA_GAMEPLAY_H
