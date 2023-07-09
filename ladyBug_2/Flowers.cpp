#include "Flowers.h"

Flowers::Flowers() {
    for (int i = 0; i < 10; i++) {
        sf::Color color(i * 50, i * 25, i * 3);
        flowers.push_back(makeFlowers(color));
        flowers[i].setScale(0.05f, 0.05f);
    }
}

sf::Sprite Flowers::makeFlowers(sf::Color color) {
    sf::Texture textureFlower;
    if (!textureFlower.loadFromFile("D:/C++/ladybug/flower.png")) {
        // Error handling if failed to load flower image
        return sf::Sprite(); // Return an empty sprite in case of failure
    }

    const int maxAttempts = 100;
    const float minDistance = 5.0f;

    for (int i = 0; i < maxAttempts; i++) {
        int randomX = rand() % 600 - 100;
        int randomY = rand() % 600 - 100;

        sf::Sprite flowerSprite(textureFlower);
        flowerSprite.setColor(color);
        flowerSprite.setPosition(randomX, randomY);

        bool hasCollision = false;

        for (const auto& otherFlower : flowers) {
            if (checkCollision(flowerSprite, otherFlower)) {
                hasCollision = true;
                break;
            }
        }

        if (!hasCollision) {
            return flowerSprite;
        }
    }

    return sf::Sprite();
}

bool Flowers::checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();
    return bounds1.intersects(bounds2);
}

std::vector<sf::Sprite> Flowers::getFlowers() const {
    return flowers;
}