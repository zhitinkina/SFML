#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

//инициализирует фигуру-указатель
void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;

    mousePosition = {float(event.x),
                     float(event.y)};
}

//опрашивает и обрабатывает доступные события в цикле
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

//обновляет фигуру, указывающую на мышь
void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock clock)
{
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    const float angle = fmodf(atan2(delta.y, delta.x) + 2 * M_PI, 2 * M_PI);

    const float dt = clock.restart().asSeconds();
    float rotation = pointer.getRotation();
    const float maxSpeed = 15;

    float dAngle = std::min((maxSpeed * dt), float(abs(toDegrees(angle) - rotation)));

    if (toDegrees(angle) < rotation)
    {
        dAngle = -dAngle;
    }
    if (abs((toDegrees(angle) - rotation)) > 180.f)
    {
        dAngle = -dAngle;
    }

    pointer.setRotation(rotation + dAngle);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
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
        "Printer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }
}