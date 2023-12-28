#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Game"), player(sf::Vector2f(50, 50)), 
    collectible(20), velocity(200.0f), deltaTime(sf::Time::Zero), score(0) {
    collectible.setFillColor(sf::Color::Red);
    collectible.setPosition(400, 300);
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        handleCollisions();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-velocity * deltaTime.asSeconds(), 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(velocity * deltaTime.asSeconds(), 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.move(0, -velocity * deltaTime.asSeconds());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.move(0, velocity * deltaTime.asSeconds());
}

void Game::update(sf::Time deltaTime) {
    // Update game logic here
}

void Game::handleCollisions() {
    // Check for collision between player and collectible
    if (player.getGlobalBounds().intersects(collectible.getGlobalBounds())) {
        // Increase score and respawn collectible
        score++;
        collectible.setPosition(rand() % 760 + 20, rand() % 560 + 20);
    }
}

void Game::render() {
    window.clear();
    window.draw(player);
    window.draw(collectible);

    // Display score
    sf::Font font;
    if (font.loadFromFile("arial.ttf")) {
        sf::Text scoreText("Score: " + std::to_string(score), font, 20);
        scoreText.setPosition(10, 10);
        window.draw(scoreText);
    }

    window.display();
}
