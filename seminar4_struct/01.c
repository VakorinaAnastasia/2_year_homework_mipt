#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};

typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};

typedef struct triangle Triangle;

void print_point(Point p)
{
    printf("(%.2f, %.2f)", p.x, p.y);
}

void print_triangle(Triangle* t)
{
    printf("{{%.2f, %.2f}, {%.2f, %.2f}, {%.2f, %.2f}}", 
           t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y);
}

double distance(Point p1, Point p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double get_triangle_perimeter(const Triangle* t)
{
    return distance(t->a, t->b) + distance(t->b, t->c) + distance(t->c, t->a);
}

Triangle moved_triangle(const Triangle* t, Point move_point)
{
    Triangle new_t = {
        {t->a.x + move_point.x, t->a.y + move_point.y},
        {t->b.x + move_point.x, t->b.y + move_point.y},
        {t->c.x + move_point.x, t->c.y + move_point.y}
    };
    return new_t;
}

void move_triangle(Triangle* t, Point move_point)
{
    t->a.x += move_point.x;
    t->a.y += move_point.y;
    t->b.x += move_point.x;
    t->b.y += move_point.y;
    t->c.x += move_point.x;
    t->c.y += move_point.y;
}

int main()
{
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));

    Point d = {1.0, 1.0};
    print_triangle(&t);
    printf("\n");
    move_triangle(&t, d);
    print_triangle(&t);
    printf("\n");
}