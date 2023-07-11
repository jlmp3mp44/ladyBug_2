#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>

#include "BackGround.h"
#include "Flowers.h"
#include "LadyBug.h"

using namespace sf;

int main()
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("C:/Windows/Media/chord.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);



    BackGround backGround;
    Sprite backgroundSprite = backGround.getSprite();

    LadyBug ladyBug;
    Sprite ladyBugSprite = ladyBug.getLadyBug();

    Flowers flower;
    std::vector<Sprite> flowers = flower.getFlowers();

    Sprite sprite;
    std::vector<Sprite> flowersCome;
    for (int i = 0; i < flowers.size(); i++) {
        sprite.setPosition(i*15, i * 30);
        flowersCome.push_back(sprite);
        if (flowersCome[i].getGlobalBounds() == flowers[i].getGlobalBounds()) {
            std::cout << 9;
        }
    }



    Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/BRITANIC.ttf")) {
        std::cout << "File didn`t found" << " ";
    }
    Text text("Scale", font);
    text.setCharacterSize(24);
    text.setFillColor(Color::Black);
    text.setPosition(50, 20);

    int dynamScale = 0;

    RenderWindow window(VideoMode(650, 650), "LADYBUG!");
    while (window.isOpen())

    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Left)
                {
                    ladyBug.updatePosition(Vector2f(-5, 0));
                    ladyBugSprite = ladyBug.getLadyBug();
                    window.draw(ladyBugSprite);
                }
                else if (event.key.code == Keyboard::Right)
                {
                    ladyBug.updatePosition(Vector2f(5, 0));
                    ladyBugSprite = ladyBug.getLadyBug();
                    window.draw(ladyBugSprite);
                }
                else if (event.key.code == Keyboard::Down)
                {
                    ladyBug.updatePosition(Vector2f(0, 5));
                    ladyBugSprite = ladyBug.getLadyBug();
                    window.draw(ladyBugSprite);
                }
                else if (event.key.code == Keyboard::Up)
                {
                    ladyBug.updatePosition(Vector2f(0, -5));
                    ladyBugSprite = ladyBug.getLadyBug();
                    window.draw(ladyBugSprite);
                }
                else if (event.key.code == Keyboard::Space) {
                    if (ladyBug.foundBounds(window.getSize().x, window.getSize().y)) {
                        std::cout << "LadyBug is out of bounds. Resetting position." << std::endl;
                        ladyBugSprite.setPosition(325, 325);
                        ladyBug.updatePosition(Vector2f(0, 0));
                        ladyBugSprite = ladyBug.getLadyBug();
                    }
                }

                //////////////SCALE
                dynamScale = ladyBug.updateScale(dynamScale, flowers, flowersCome);
                ladyBugSprite = ladyBug.getLadyBug();
                text.setString("Scale: " + std::to_string(dynamScale));
                window.draw(text);
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(ladyBugSprite);
        for (int i = 0; i < flowers.size(); i++) {
            window.draw(flowers[i]);
        }
        window.draw(text);
        window.display();
        }
    
    return 0;
}
