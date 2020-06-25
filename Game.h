#ifndef SIMCITYBETA_GAME_H
#define SIMCITYBETA_GAME_H

#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


class GameState;

class Game {
public:
    sf::RenderWindow window;
    std::unique_ptr<GameState> state;

    void run();

    Game();

    virtual ~Game();
};


#endif //SIMCITYBETA_GAME_H
