#include "Gameplay.h"


void Gameplay::draw(const sf::Time dt) {
    this->game->window.clear();
    this->game->window.setView(this->guiView);
    this->game->window.draw(this->background);
    this->game->window.setView(this->cityView);
    this->city->map.draw(this->game->window, dt);
    ImGui::SFML::Render(this->game->window);
}

void Gameplay::update(const sf::Time dt) {
    // updateCity(dt)

    // update gui info
    this->updateGui(dt);

}

void Gameplay::updateInput() {

    sf::Event event{};

    sf::Vector2f gamePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window),
                                                               this->cityView);

    while (this->game->window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        switch (event.type) {
            case sf::Event::MouseMoved: {
                if (moveCamera) {
                    sf::Vector2f pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->game->window) -
                                                                 this->cameraMoveAnchor);
                    this->cityView.move(-1.0f * pos * this->zoom);
                    this->cameraMoveAnchor = sf::Mouse::getPosition(this->game->window);
                }
            }
            case sf::Event::MouseButtonPressed: {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (!this->moveCamera) {
                        auto x = gamePos.x / this->city->map.tileSize;
                        auto y = gamePos.y / this->city->map.tileSize;
                        this->city->map.changeTile(x, y, this->buildChoice);

                    }
                    // narysuj kafelek DOM
                    this->cameraMoveAnchor = sf::Mouse::getPosition(this->game->window);
                }

                if (event.mouseButton.button == sf::Mouse::Middle) {
                    if (!this->moveCamera) {
                        this->moveCamera = true;
                        this->cameraMoveAnchor = sf::Mouse::getPosition(this->game->window);
                    }
                }
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (event.mouseButton.button == sf::Mouse::Middle) {
                    this->moveCamera = false;
                }
                break;
            }
            case sf::Event::MouseWheelMoved: {
                if (event.mouseWheel.delta < 0) {
                    this->cityView.zoom(2.0f);
                    this->zoom *= 2.0f;
                } else {
                    this->cityView.zoom(0.5f);
                    this->zoom *= 0.5f;
                }
                break;
            }

            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape) this->game->window.close();
                break;
            }

            case sf::Event::Closed: {
                this->game->window.close();
                break;
            }

            default: {
                break;
            }
        }
    }
}

Gameplay::Gameplay(Game *game) : GameState(game) {
    this->initTextures();

    this->background.setTexture(*this->textures.at("background"));

    this->city = std::make_unique<City>("Wegrzynowo", 5, 5, 16, this->textures);

    auto view_size = static_cast<sf::Vector2f>(this->game->window.getSize());
    this->guiView.setSize(view_size);
    this->guiView.setCenter(view_size * 0.5f);

    this->cityView.setSize(view_size);

    sf::Vector2f centre(this->city->map.width, this->city->map.height);
    centre *= static_cast<float>(this->city->map.tileSize) * 0.5f;

    this->cityView.setCenter(centre);

    this->zoom = 1.0f;

}

void Gameplay::initTextures() {
    std::unique_ptr<sf::Texture> bground(new sf::Texture());
    std::string filepath = "../res/textures/background.jpg";
    if (!bground->loadFromFile(filepath))
        throw std::runtime_error("Gameplay::initTextures() - Failed to load " + filepath);
    this->textures.insert(std::make_pair("background", std::move(bground)));

    std::unique_ptr<sf::Texture> tex(new sf::Texture());
    filepath = "../res/textures/forest.jpg";
    if (!tex->loadFromFile(filepath))
        throw std::runtime_error("Gameplay::initTextures() - Failed to load " + filepath);
    this->textures.insert(std::make_pair("forest", std::move(tex)));

    std::unique_ptr<sf::Texture> tex2(new sf::Texture());
    filepath = "../res/textures/grass.jpg";
    if (!tex2->loadFromFile(filepath))
        throw std::runtime_error("Gameplay::initTextures() - Failed to load " + filepath);
    this->textures.insert(std::make_pair("grass", std::move(tex2)));

    std::unique_ptr<sf::Texture> tex3(new sf::Texture());
    filepath = "../res/textures/iron.jpg";
    if (!tex3->loadFromFile(filepath))
        throw std::runtime_error("Gameplay::initTextures() - Failed to load " + filepath);
    this->textures.insert(std::make_pair("iron", std::move(tex3)));

    std::unique_ptr<sf::Texture> tex4(new sf::Texture());
    filepath = "../res/textures/kostka.jpg";
    if (!tex4->loadFromFile(filepath))
        throw std::runtime_error("Gameplay::initTextures() - Failed to load " + filepath);
    this->textures.insert(std::make_pair("kostka", std::move(tex4)));

    std::unique_ptr<sf::Texture> tex5(new sf::Texture());
    filepath = "../res/textures/water.jpg";
    if (!tex5->loadFromFile(filepath))
        throw std::runtime_error("Gameplay::initTextures() - Failed to load " + filepath);
    this->textures.insert(std::make_pair("water", std::move(tex5)));
}

void Gameplay::updateGui(const sf::Time dt) {
    ImGui::SFML::Update(this->game->window, dt);
    ImGui::Begin("Menu budowy");
    ImGui::Text("Co budujemy?");
    ImGui::RadioButton("Nic", &this->buildChoice, 0);
    ImGui::RadioButton("Domy", &this->buildChoice, 1);
    ImGui::RadioButton("Publiczne", &this->buildChoice, 2);
    ImGui::RadioButton("Przemysl", &this->buildChoice, 3);
    ImGui::End();
}
