#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200;
    const sf::Vector2f ellipseRadius = {20.f, 130.f};
    sf::Clock clock;
    const sf::Vector2f speed = {250.f, 50.f};
    const float Radius = 100;
    float speedX = 0;
    float speedY = 0;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Ellipse",
        sf::Style::Default, settings);

    sf::ConvexShape ellipse;
    ellipse.setPosition({390, 300});
    ellipse.setFillColor(sf::Color(0xFF, 0x0, 0xFF));

    ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            float(200 * sin(6 * angle)) * std::sin(angle),
            float(200 * sin(6 * angle)) * std::cos(angle)};
        ellipse.setPoint(pointNo, point);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float time = clock.getElapsedTime().asSeconds();
        const sf::Vector2f offset = {390, 300};

        speedX = 390 + Radius * std::cos(time);
        speedY = 300 + Radius * std::sin(time);

        ellipse.setPosition(speedX, speedY);

        window.clear();
        window.draw(ellipse);
        window.display();
    }
}
