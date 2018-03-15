#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 500}), "Initials");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({150, 50});
    shape1.setRotation(180);
    shape1.setPosition({250, 200});
    shape1.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({150, 50});
    shape2.setRotation(135);
    shape2.setPosition({250, 200});
    shape2.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({150, 50});
    shape3.setRotation(180);
    shape3.setPosition({257, 321});
    shape3.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({180, 50});
    shape4.setRotation(130);
    shape4.setPosition({430, 180});
    shape4.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({180, 50});
    shape5.setRotation(-316);
    shape5.setPosition({398, 152});
    shape5.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({150, 35});
    shape6.setRotation(180);
    shape6.setPosition({470, 278});
    shape6.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({160, 50});
    shape7.setRotation(90);
    shape7.setPosition({600, 150});
    shape7.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({160, 50});
    shape8.setRotation(360);
    shape8.setPosition({550, 150});
    shape8.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({160, 50});
    shape9.setRotation(360);
    shape9.setPosition({550, 265});
    shape9.setFillColor(sf::Color(0x0, 0x0, 0xFF));
    window.draw(shape9);

    window.display();

    sf::sleep(sf::seconds(7));
}