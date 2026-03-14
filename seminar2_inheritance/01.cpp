#include <iostream>
#include <cmath>

struct Vector2f {
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right) {
    return {left.x + right.x, left.y + right.y};
}

Vector2f operator*(Vector2f left, float right) {
    return {left.x * right, left.y * right};
}

Vector2f operator*(float left, Vector2f right) {
    return {left * right.x, left * right.y};
}

Vector2f& operator+=(Vector2f& left, Vector2f right) {
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right) {
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}

class Shape {
protected:
    Vector2f mPosition;
public:
    Shape() : mPosition{0, 0} {}
    Vector2f getPosition() const { return mPosition; }
    void setPosition(Vector2f newPosition) { mPosition = newPosition; }
    void move(Vector2f change) { mPosition += change; }
};

class Circle : public Shape {
    float mRadius;
public:
    Circle(float radius) : mRadius(radius) {}
    float calculatePerimeter() {
        return 2 * std::numbers::pi * mRadius;
    }
};

class Rectangle : public Shape {
    float mWidth;
    float mHeight;
public:
    Rectangle(float width, float height) : mWidth(width), mHeight(height) {}
    float calculatePerimeter() {
        return 2 * (mWidth + mHeight);
    }
};

class Triangle : public Shape {
    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;
public:
    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC)
        : mPointA(pointA), mPointB(pointB), mPointC(pointC) {}
    float calculatePerimeter() {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};

int main() {
    Circle a(10);
    std::cout << a.calculatePerimeter() << std::endl;

    Rectangle b(100, 200);
    std::cout << b.calculatePerimeter() << std::endl;

    Triangle c({5, 2}, {-7, 5}, {4, 4});
    std::cout << c.calculatePerimeter() << std::endl;

    // Тестируем move
    a.move({5, 5});
    b.move({-10, 20});
    c.move({3, -3});

    std::cout << "Circle position: " << a.getPosition() << std::endl;
    std::cout << "Rectangle position: " << b.getPosition() << std::endl;
    std::cout << "Triangle position: " << c.getPosition() << std::endl;
}