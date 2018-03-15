#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({60, 360}), "svetofor");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({105, 330});
    shape1.setPosition({25, 20});
    shape1.setFillColor(sf::Color(363636, 363636, 363636));
    window.draw(shape1);

    sf::CircleShape shape2(48);
    shape2.setPosition({30, 34});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(48);
    shape3.setPosition({30, 136});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(48);
    shape4.setPosition({30, 238});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(10));
}