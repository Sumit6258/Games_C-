#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Game"), player(sf::Vector2f(50, 50)),
    collectible(20), playerVelocity(200.0f), enemyVelocity(150.0f), deltaTime(sf::Time::Zero), score(0) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle font loading error
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(10, 10);

    if (!collectSoundBuffer.loadFromFile("collect.wav")) {
        // Handle sound loading error
    }

    collectSound.setBuffer(collectSoundBuffer);

    // Initialize player, enemies, and collectible positions
    // ...

    // Initialize enemies
    for (int i = 0; i < 5; ++i) {
        sf::RectangleShape enemy(sf::Vector2f(30, 30));
        enemy.setPosition(100 * i + 50, 100);
        enemies.push_back(enemy);
    }
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

    // Handle player input
    // ...
}

void Game::update(sf::Time deltaTime) {
    // Update player and enemies positions
    // ...

    // Check for out-of-bounds enemies and respawn them
    // ...

    // Update game logic here
}

void Game::handleCollisions() {
    // Check for collision between player and collectible
    // ...

    // Check for collision between player and enemies
    // ...

    // Check for out-of-bounds collectible and respawn it
    // ...

    // Check for out-of-bounds enemies and respawn them
    // ...
}

void Game::render() {
    window.clear();
    window.draw(player);

    // Draw enemies
    // ...

    window.draw(collectible);
    window.draw(scoreText);

    window.display();
}
