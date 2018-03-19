#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

struct Eyes
{
    sf::ConvexShape black;
    sf::ConvexShape white;
};

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void initEllipse(sf::ConvexShape &ellipse, const sf::Vector2f &ellipseRadius, const sf::Vector2f &position)
{
    constexpr int pointCount = 200;

    ellipse.setPosition(position);
    ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::sin(angle),
            ellipseRadius.y * std::cos(angle)};
        ellipse.setPoint(pointNo, point);
    }
}

void initEyes(Eyes &eyes, const sf::Vector2f &position)
{
    initEllipse(eyes.black, {30.f, 50.f}, position);
    initEllipse(eyes.white, {80.f, 120.f}, position);
    eyes.black.setFillColor(sf::Color(0x0, 0x0, 0x0));
    eyes.white.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << " , y=" << event.y << std::endl;

    mousePosition = {
        float(event.x),
        float(event.y)};
}

void drawEye(sf::RenderWindow &window, const Eyes &eyes)
{
    window.draw(eyes.white);
    window.draw(eyes.black);
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

void updateEyes(const sf::Vector2f &mousePosition, Eyes &eyes)
{
    const sf::Vector2f radius = {20.f, 40.f};

    const sf::Vector2f delta = mousePosition - eyes.white.getPosition();
    const float angle = atan2(delta.y, delta.x);
    std::cout << "angle: " << angle << std::endl;
    sf::Vector2f shapePosition;

    shapePosition.x = radius.x * std::cos(angle);
    shapePosition.y = radius.y * std::sin(angle);

    std::cout << "shape position:" << shapePosition.x << " , " << shapePosition.y << std::endl;

    eyes.black.setPosition(eyes.white.getPosition() + shapePosition);
}

void update(const sf::Vector2f &mousePosition, Eyes &leftEye, Eyes &rightEye)
{
    updateEyes(mousePosition, leftEye);
    updateEyes(mousePosition, rightEye);
}

void redrawFrame(sf::RenderWindow &window, const Eyes &leftEye, const Eyes &rightEye)
{
    window.clear();
    drawEye(window, leftEye);
    drawEye(window, rightEye);
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
        "Eyes follows mouse", sf::Style::Default, settings);

    Eyes leftEye;
    initEyes(leftEye, {270, 300});
    Eyes rightEye;
    initEyes(rightEye, {470, 300});

    sf::Vector2f mousePosition;
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, leftEye, rightEye);
        redrawFrame(window, leftEye, rightEye);
    }
}