#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class DropList {
    sf::Font& mFont;
    std::vector<std::string> mItems;
    int mSelected;
    bool mExpanded;
    sf::RectangleShape mMainRect;
    std::vector<sf::RectangleShape> mItemRects;
    sf::Vector2f mPosition;
    sf::Vector2f mSize;
public:
    DropList(sf::Font& font, sf::Vector2f position, sf::Vector2f size, const std::vector<std::string>& items)
        : mFont(font), mItems(items), mSelected(0), mExpanded(false), mPosition(position), mSize(size) {
        mMainRect.setSize(size);
        mMainRect.setPosition(position);
        mMainRect.setFillColor(sf::Color(200,200,200));
        mMainRect.setOutlineColor(sf::Color::White);
        mMainRect.setOutlineThickness(2);
        for (size_t i = 0; i < items.size(); ++i) {
            sf::RectangleShape rect(sf::Vector2f(size.x, size.y));
            rect.setPosition(position.x, position.y + (i+1) * size.y);
            rect.setFillColor(sf::Color(180,180,180));
            rect.setOutlineColor(sf::Color::White);
            rect.setOutlineThickness(1);
            mItemRects.push_back(rect);
        }
    }
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mExpanded) {
                for (size_t i = 0; i < mItemRects.size(); ++i) {
                    if (mItemRects[i].getGlobalBounds().contains(mouse)) {
                        mSelected = i;
                        mExpanded = false;
                        return;
                    }
                }
                if (!mMainRect.getGlobalBounds().contains(mouse))
                    mExpanded = false;
            } else {
                if (mMainRect.getGlobalBounds().contains(mouse))
                    mExpanded = true;
            }
        }
    }
    void draw(sf::RenderWindow& window) {
        window.draw(mMainRect);
        sf::Text text(mItems[mSelected], mFont, 20);
        text.setPosition(mMainRect.getPosition());
        text.setFillColor(sf::Color::Black);
        window.draw(text);
        if (mExpanded) {
            for (size_t i = 0; i < mItemRects.size(); ++i) {
                window.draw(mItemRects[i]);
                sf::Text itemText(mItems[i], mFont, 20);
                itemText.setPosition(mItemRects[i].getPosition());
                itemText.setFillColor(sf::Color::Black);
                window.draw(itemText);
            }
        }
    }
    int getSelected() const { return mSelected; }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DropList");
    window.setFramerateLimit(60);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) return -1; // убедитесь, что файл есть
    std::vector<std::string> items = {"Круг", "Квадрат", "Треугольник"};
    DropList list(font, {300, 50}, {200, 30}, items);

    sf::CircleShape circle(100); circle.setOrigin(100,100); circle.setPosition(400,350);
    sf::RectangleShape square(sf::Vector2f(200,200)); square.setOrigin(100,100); square.setPosition(400,350);
    sf::ConvexShape triangle; triangle.setPointCount(3); triangle.setPoint(0,{0,-100}); triangle.setPoint(1,{86.6,50}); triangle.setPoint(2,{-86.6,50});
    triangle.setOrigin(0,0); triangle.setPosition(400,350);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            list.handleEvent(event, window);
        }
        window.clear(sf::Color::Black);
        list.draw(window);
        int sel = list.getSelected();
        if (sel == 0) { circle.setFillColor(sf::Color::Red); window.draw(circle); }
        else if (sel == 1) { square.setFillColor(sf::Color::Green); window.draw(square); }
        else { triangle.setFillColor(sf::Color::Blue); window.draw(triangle); }
        window.display();
    }
}