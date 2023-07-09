#include "LadyBug.h"

LadyBug::LadyBug() {
    if (!textureLadyBug.loadFromFile("D:/C++/ladybug/ladybag.png")) {
        return;
    }
    ladyBugSprite.setTexture(textureLadyBug);
    ladyBugSprite.setScale(0.14f, 0.14f);
    ladyBugSprite.setPosition(500, 600);

    position = sf::Vector2f(500, 600);
}

sf::Sprite LadyBug::getLadyBug() {
    return ladyBugSprite;
}

void LadyBug::updatePosition(const sf::Vector2f& offset) {
    position += offset;
    ladyBugSprite.setPosition(position);

    float angle = 0.0f;
    if (offset.x < 0)
        angle = 0.0f;
    else if (offset.x > 0)
        angle = 180.0f;
    else if (offset.y < 0)
        angle = 90.0f;
    else if (offset.y > 0)
        angle = -90.0f;

    ladyBugSprite.setRotation(angle);
}

int LadyBug::updateScale(int scale, const std::vector<sf::Sprite>& flowers) {
    sf::FloatRect ladyBounds = ladyBugSprite.getGlobalBounds();

    for (int i = 0; i < flowers.size(); i++) {
        if (flowers[i].getGlobalBounds().intersects(ladyBounds)) {
            scale++;
            break;
        }
    }
    return scale;
}




