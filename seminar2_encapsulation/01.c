#pragma once
#include "point.hpp"

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius) : center(center), radius(radius < 0 ? 0 : radius) {}
    
    Circle() : center(Point(0, 0)), radius(1) {}
    
    Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {}

    Point getCenter() const { return center; }
    float getRadius() const { return radius; }
    
    void setCenter(const Point& center) { this->center = center; }
    
    void setRadius(float radius) 
    { 
        this->radius = radius < 0 ? 0 : radius;
    }

    float area() const 
    {
        return 3.14159f * radius * radius;
    }

    float distance(const Point& p) const 
    {
        float distToCenter = center.distance(p);
        return distToCenter <= radius ? 0 : distToCenter - radius;
    }

    bool isColliding(const Circle& c) const 
    {
        return center.distance(c.center) <= (radius + c.radius);
    }

    void move(const Point& p) 
    {
        center = center + p;
    }
};
