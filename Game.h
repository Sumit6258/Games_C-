#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handleCollisions();

private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::CircleShape collectible;
    float velocity;
    sf::Time deltaTime;
    int score;
};
