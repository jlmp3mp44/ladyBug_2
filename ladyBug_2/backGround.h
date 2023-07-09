#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class BackGround {
private:
    sf::Texture backTexture;
    sf::Sprite backgroundSprite;

public:
    BackGround();
    sf::Sprite getSprite() const;
};

#endif // BACKGROUND_H

