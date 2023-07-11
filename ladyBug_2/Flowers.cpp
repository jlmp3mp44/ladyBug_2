#include "Flowers.h"
#include <random>

Flowers::Flowers() {
    for (int i = 0; i < 40; i++) {
        sf::Color color(i * 50, i * 25, i * 3);
        flowers.push_back(makeFlowers(color));
        flowers[i].setScale(0.05f, 0.05f);
    }
}

sf::Sprite Flowers::makeFlowers(sf::Color color) {
    sf::Texture textureFlower;
    if (!textureFlower.loadFromFile("D:/C++/ladybug/flower.png")) {
        // Обробка помилки, якщо не вдалося завантажити зображення квітки
        return sf::Sprite(); // Повернути пустий спрайт у разі невдалого завантаження
    }

    const int maxAttempts = 150;
    const float minDistance = 5.0f;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-80, 600);

    for (int i = 0; i < maxAttempts; i++) {
        int randomX = dis(gen);
        int randomY = dis(gen);

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