#pragma once
#ifndef LADYBUG_H
#define LADYBUG_H

#include <SFML/Graphics.hpp>
#include "Flowers.h"

class LadyBug {
private:
    sf::Texture textureLadyBug;
    sf::Sprite ladyBugSprite;
    sf::Vector2f position;

public:
    LadyBug();
    sf::Sprite getLadyBug();
    void updatePosition(const sf::Vector2f& offset);
    int updateScale(int scale, const std::vector<sf::Sprite>& flowers);
};

#endif // LADYBUG_H

