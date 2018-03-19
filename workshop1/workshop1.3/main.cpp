#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void drawFrame(sf::RenderWindow &window, sf::Sprite &sprite)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sprite);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "cat", sf::Style::Default, settings);

    sf::Texture cat;
    cat.loadFromFile("workshop1.3/cat.png");
    if (!cat.loadFromFile("workshop1.3/cat.png"))
    {
        std::cout << "Не удалось загрузить текстуру!!!" << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(cat);
    sprite.setPosition(370, 290);

    while (window.isOpen())
    {
        pollEvents(window);
        drawFrame(window, sprite);
    }
}