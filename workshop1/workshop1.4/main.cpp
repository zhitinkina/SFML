#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mousePosition, sf::Sprite &sprite)
{
    mousePosition = {
        float(event.x),
        float(event.y)};

    const sf::Vector2f distance = mousePosition - sprite.getPosition();
    const float angle = fmodf(atan2(distance.y, distance.x) + 2 * M_PI, 2 * M_PI);
    if ((toDegrees(angle) <= 270) && (toDegrees(angle) >= 90))
    {
        sprite.setScale(-1, 1);
    }
    else
    {
        sprite.setScale(1, 1);
    }
}

float wayOfTheVector(const sf::Vector2f &vector)
{
    return std::hypotf(vector.x, vector.y);
}

void update(const sf::Vector2f &mousePosition, sf::Sprite &sprite, sf::Clock &clock, sf::Vector2f &position, sf::Sprite &laser)
{
    const float epsilon = 0.1f;
    laser.setPosition(mousePosition);
    const sf::Vector2f motion = mousePosition - sprite.getPosition();
    sf::Vector2f direction = {0, 0};

    if (wayOfTheVector(motion) > epsilon)
    {
        direction = motion / wayOfTheVector(motion);
    }

    const float dt = clock.restart().asSeconds();
    float speed = 215.f;

    position += direction * speed * dt;
    sprite.setPosition(position);
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition, sf::Sprite &sprite)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, mousePosition, sprite);
            break;
        default:
            break;
        }
    }
}

void drawFrame(sf::RenderWindow &window, sf::Sprite &sprite, sf::Sprite &laser)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(sprite);
    window.draw(laser);
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
    cat.loadFromFile("workshop1.4/cat.png");
    if (!cat.loadFromFile("workshop1.4/cat.png"))
    {
        std::cout << "Не удалось загрузить текстуру кота!!!" << std::endl;
    }
    sf::Texture redPointer;
    redPointer.loadFromFile("workshop1.4/red_pointer.png");
    if (!redPointer.loadFromFile("workshop1.4/red_pointer.png"))
    {
        std::cout << "Не удалось загрузить текстуру указки!!!" << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(cat);
    sprite.setPosition(370, 290);
    sprite.setOrigin(20, 17);

    sf::Sprite laser;
    laser.setTexture(redPointer);
    laser.setOrigin(20, 20);

    sf::Clock clock;
    sf::Vector2f position;
    sf::Vector2f mousePosition = {-50, -50};
    while (window.isOpen())
    {
        pollEvents(window, mousePosition, sprite);
        update(mousePosition, sprite, clock, position, laser);
        drawFrame(window, sprite, laser);
    }
}