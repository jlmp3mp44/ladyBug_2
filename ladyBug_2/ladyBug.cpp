#include "LadyBug.h"
#include <iostream>

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

int LadyBug::updateScale(int scale, const std::vector<sf::Sprite> flowers, std::vector<sf::Sprite>& flowersCome) {
    sf::FloatRect ladyBounds = ladyBugSprite.getGlobalBounds();

    for (int i = 0; i < flowers.size(); i++) {\
        if ((flowers[i].getGlobalBounds().intersects(ladyBounds)) && (!contains(flowers[i], flowersCome))) {
            scale++;
            flowersCome[i].setPosition(flowers[i].getPosition());
            break;
        }
    }
    return scale;
}



bool LadyBug:: foundBounds(int x, int y) {
    if (ladyBugSprite.getPosition().x > x || ladyBugSprite.getPosition().y > y) {
        return true;
    }
    return false;
}


bool LadyBug::contains(sf::Sprite sprite, const std::vector<sf::Sprite>& targetSprites) {
   for(int i=0; i<targetSprites.size(); i++){
       if (sprite.getPosition() == targetSprites[i].getPosition()) {
           return true;
       }
        }
    return false;
}





