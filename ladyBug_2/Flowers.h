#pragma once
#ifndef FLOWERS_H
#define FLOWERS_H

#include <SFML/Graphics.hpp>
#include <vector>

class Flowers {
private:
    std::vector<sf::Sprite> flowers;

    sf::Sprite makeFlowers(sf::Color color);
    bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);

public:
    Flowers();
    std::vector<sf::Sprite> getFlowers() const;
};

#endif // FLOWERS_H
