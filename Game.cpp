#include "Game.h"
#include "Gameplay.h"


void Game::run() {
    sf::Clock clock;

    while (this->window.isOpen()) {
        sf::Time dt = clock.restart();

        this->state->updateInput();
        this->state->update(dt);
        this->state->draw(dt);
        this->window.display();
    }
    ImGui::SFML::Shutdown();
}

Game::Game() : window(sf::VideoMode(800, 600), "SimCity 2137") {
    this->window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(this->window);
    this->state = std::make_unique<Gameplay>(this);
}

Game::~Game() = default;
