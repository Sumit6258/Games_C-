#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Game"), player(sf::Vector2f(50, 50)), velocity(200.0f) {}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    // Handle events
}
