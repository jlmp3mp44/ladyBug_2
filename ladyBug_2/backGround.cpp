#include "BackGround.h"

BackGround::BackGround() {
    if (!backTexture.loadFromFile("D:/C++/ladybug/background.jpg")) {
        return;
    }
    backgroundSprite.setTexture(backTexture);
}

sf::Sprite BackGround::getSprite() const {
    return backgroundSprite;
}
