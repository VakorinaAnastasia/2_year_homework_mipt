#pragma once
#include <iostream>

class Vector2f
{
private:
    float x;
    float y;

public:
    Vector2f(float x = 0, float y = 0) : x(x), y(y) {}
    
    float getX() const { return x; }
    float getY() const { return y; }

    Vector2f operator+(const Vector2f& other) const 
    {
        return Vector2f(x + other.x, y + other.y);
    }

    Vector2f operator-(const Vector2f& other) const 
    {
        return Vector2f(x - other.x, y - other.y);
    }

    Vector2f operator*(float scalar) const 
    {
        return Vector2f(x * scalar, y * scalar);
    }

    friend Vector2f operator*(float scalar, const Vector2f& vec) 
    {
        return vec * scalar;
    }

    float operator*(const Vector2f& other) const 
    {
        return x * other.x + y * other.y;
    }

    Vector2f operator+() const 
    {
        return *this;
    }

    Vector2f operator-() const 
    {
        return Vector2f(-x, -y);
    }

    bool operator==(const Vector2f& other) const 
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2f& other) const 
    {
        return !(*this == other);
    }

    Vector2f& operator+=(const Vector2f& other) 
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2f& operator-=(const Vector2f& other) 
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2f& operator*=(float scalar) 
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector2f& vec) 
    {
        out << "(" << vec.x << ", " << vec.y << ")";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Vector2f& vec) 
    {
        in >> vec.x >> vec.y;
        return in;
    }
};