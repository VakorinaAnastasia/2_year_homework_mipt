#include <SFML/Graphics.hpp>
#include <vector>

class Toggle {
    sf::RectangleShape mShape;
    bool mState;
    sf::Color mOnColor, mOffColor;
public:
    Toggle(sf::Vector2f position, sf::Vector2f size, bool initialState = false)
        : mState(initialState), mOnColor(sf::Color::Green), mOffColor(sf::Color::Red) {
        mShape.setSize(size);
        mShape.setOrigin(size/2.f);
        mShape.setPosition(position);
        mShape.setFillColor(mState ? mOnColor : mOffColor);
        mShape.setOutlineColor(sf::Color::White);
        mShape.setOutlineThickness(2);
    }
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mShape.getGlobalBounds().contains(mouse)) {
                mState = !mState;
                mShape.setFillColor(mState ? mOnColor : mOffColor);
            }
        }
    }
    void draw(sf::RenderWindow& window) const { window.draw(mShape); }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 600), "Toggles");
    window.setFramerateLimit(60);
    std::vector<Toggle> toggles;
    for (int i = 0; i < 10; ++i)
        toggles.emplace_back(sf::Vector2f(200, 50 + i * 50), sf::Vector2f(80, 30));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            for (auto& t : toggles) t.handleEvent(event, window);
        }
        window.clear(sf::Color::Black);
        for (const auto& t : toggles) t.draw(window);
        window.display();
    }
}