#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void initArrow(sf::ConvexShape &arrow)
{
    arrow.setPosition({400, 290});
    arrow.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
    arrow.setPointCount(7);
    arrow.setPoint(0, {50, 0});
    arrow.setPoint(1, {0, -50});
    arrow.setPoint(2, {0, -25});
    arrow.setPoint(3, {-50, -25});
    arrow.setPoint(4, {-50, 25});
    arrow.setPoint(5, {0, 25});
    arrow.setPoint(6, {0, 50});
    arrow.setOutlineColor(sf::Color(0, 0, 0));
    arrow.setOutlineThickness(2);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {
        float(event.x),
        float(event.y)};
}

float wayVector(const sf::Vector2f &vector)
{
    return std::hypotf(vector.x, vector.y);
}

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

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &arrow, sf::Clock &clock, sf::Vector2f &position)
{
    const sf::Vector2f motion = mousePosition - arrow.getPosition();
    const sf::Vector2f direction = motion / wayVector(motion);

    const float dt = clock.restart().asSeconds();
    const float speed = 200.f;

    const float angle = fmodf(atan2(motion.y, motion.x) + 2 * M_PI, 2 * M_PI);
    float rotation = arrow.getRotation();
    const float maxAngularSpeed = 90;

    float dAngle = std::min((maxAngularSpeed * dt), float(abs(toDegrees(angle) - rotation)));
    if (toDegrees(angle) < rotation)
    {
        dAngle = -dAngle;
    }
    if (abs((toDegrees(angle) - rotation)) > 180.f)
    {
        dAngle = -dAngle;
    }

    position += direction * speed * dt;

    arrow.setRotation(rotation + dAngle);
    arrow.setPosition(position);
}

void drawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(arrow);
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
        "Arrow follows mouse", sf::Style::Default, settings);

    sf::ConvexShape arrow;
    initArrow(arrow);

    sf::Clock clock;
    sf::Vector2f position;

    sf::Vector2f mousePosition;
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow, clock, position);
        drawFrame(window, arrow);
    }
}