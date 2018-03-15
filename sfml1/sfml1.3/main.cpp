#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "House");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({250, 450});
    shape1.setRotation(90);
    shape1.setPosition({600, 300});
    shape1.setFillColor(sf::Color(102, 51, 0));
    window.draw(shape1);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(102, 0, 0));
    trapeze.setPosition({375, 150});
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-110, 0});
    trapeze.setPoint(1, {+110, 0});
    trapeze.setPoint(2, {+280, 150});
    trapeze.setPoint(3, {-280, 150});
    window.draw(trapeze);

    sf::RectangleShape shape2;
    shape2.setSize({150, 80});
    shape2.setRotation(90);
    shape2.setPosition({270, 400});
    shape2.setFillColor(sf::Color(28, 28, 28));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({100, 45});
    shape3.setRotation(90);
    shape3.setPosition({470, 120});
    shape3.setFillColor(sf::Color(54, 54, 54));
    window.draw(shape3);

    sf::CircleShape shape4(20);
    shape4.setPosition({440, 60});
    shape4.setFillColor(sf::Color(105, 105, 105));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({45, 75});
    shape5.setRotation(90);
    shape5.setPosition({484, 95});
    shape5.setFillColor(sf::Color(54, 54, 54));
    window.draw(shape5);

    sf::CircleShape shape6(25);
    shape6.setPosition({450, 30});
    shape6.setFillColor(sf::Color(105, 105, 105));
    window.draw(shape6);

    sf::CircleShape shape7(30);
    shape7.setPosition({475, 10});
    shape7.setFillColor(sf::Color(105, 105, 105));
    window.draw(shape7);

    sf::CircleShape shape8(35);
    shape8.setPosition({505, 3});
    shape8.setFillColor(sf::Color(105, 105, 105));
    window.draw(shape8);

    window.display();

    sf::sleep(sf::seconds(7));
}