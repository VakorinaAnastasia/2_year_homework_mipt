#include <SFML/Graphics.hpp>
#include "slider.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "RGB Circle");
    window.setFramerateLimit(60);
    Slider sliderR(window, {200, 500}, {300, 20}, {20, 60});
    Slider sliderG(window, {400, 500}, {300, 20}, {20, 60});
    Slider sliderB(window, {600, 500}, {300, 20}, {20, 60});
    sf::CircleShape circle(150);
    circle.setOrigin(150, 150);
    circle.setPosition(400, 250);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            sliderR.handleEvent(event);
            sliderG.handleEvent(event);
            sliderB.handleEvent(event);
        }
        sf::Uint8 r = static_cast<sf::Uint8>(sliderR.getValue() * 2.55f);
        sf::Uint8 g = static_cast<sf::Uint8>(sliderG.getValue() * 2.55f);
        sf::Uint8 b = static_cast<sf::Uint8>(sliderB.getValue() * 2.55f);
        circle.setFillColor(sf::Color(r, g, b));

        window.clear(sf::Color::Black);
        sliderR.draw();
        sliderG.draw();
        sliderB.draw();
        window.draw(circle);
        window.display();
    }
}