#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr float BALL_SIZE = 40;
    float speedX = 100.f;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving Ball");
    sf::Clock clock;

    const sf::Vector2f position = {10, 300};

    float time = 0;
    float x = 0;

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

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

        constexpr float amplitudeY = 100.f;
        constexpr float periodY = 2;

        const float dt = clock.restart().asSeconds();
        time += dt;
        x += speedX * dt;
        const float wavePhase = time * float(2 * M_PI);
        const float y = amplitudeY * std::sin(wavePhase / periodY);
        const sf::Vector2f offset = {x, y};

        if ((position.x + offset.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0))
        {
            speedX = -speedX;
        }
        if ((position.x + offset.x < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }

        ball.setPosition(position + offset);

        window.clear();
        window.draw(ball);
        window.display();
    }
}