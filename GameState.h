#ifndef SIMCITYBETA_GAMESTATE_H
#define SIMCITYBETA_GAMESTATE_H


#include "Game.h"

class GameState {
protected:
    Game *game;
public:
    explicit GameState(Game *game);

    virtual ~GameState();

    virtual void draw(sf::Time dt) = 0;

    virtual void update(sf::Time dt) = 0;

    virtual void updateInput() = 0;
};


#endif //SIMCITYBETA_GAMESTATE_H
