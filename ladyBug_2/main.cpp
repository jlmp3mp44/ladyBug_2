#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <sstream>
#include <iostream>

#include "BackGround.h"
#include "Flowers.h"
#include "LadyBug.h"

using namespace sf;

int main()
{
    BackGround backGround;
    Sprite backgroundSprite = backGround.getSprite();

    LadyBug ladyBug;
    Sprite ladyBugSprite = ladyBug.getLadyBug();

    Flowers flower;
    std::vector<Sprite> flowers = flower.getFlowers();

    Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/BRITANNIC.ttf")) {
        std::cout << "File didn`t found" << " ";
    }
    Text text("Scale", font);

    RenderWindow window(VideoMode(650, 650), "LADYBUG!");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Left) {
                ladyBug.updatePosition(Vector2f(-1, 0));
                ladyBugSprite = ladyBug.getLadyBug();
                window.draw(ladyBugSprite);
            }
            if (event.key.code == Keyboard::Right) {
                ladyBug.updatePosition(Vector2f(1, 0));
                ladyBugSprite = ladyBug.getLadyBug();
                window.draw(ladyBugSprite);
            }
            if (event.key.code == Keyboard::Down) {
                ladyBug.updatePosition(Vector2f(0, 1));
                ladyBugSprite = ladyBug.getLadyBug();
                window.draw(ladyBugSprite);
            }
            if (event.key.code == Keyboard::Up) {
                ladyBug.updatePosition(Vector2f(0, -1));
                ladyBugSprite = ladyBug.getLadyBug();
                window.draw(ladyBugSprite);
            }
        }

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