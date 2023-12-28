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

private:
    sf::RenderWindow window;
    sf::RectangleShape player;
    float velocity;
    sf::Time deltaTime;
};
