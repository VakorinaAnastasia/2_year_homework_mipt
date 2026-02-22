#include <raylib.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

const float EPS = 18.0f;
const float WALL = 1.0f;

struct Body {
    Vector2 pos;
    Vector2 vel;
    float m;
    float q;
    Color c;
};

int main() {
    std::srand(std::time(0));
    int W = 600;
    int H = 600;
    InitWindow(W, H, "");
    SetTargetFPS(60);

    std::vector<Body> bodies;

    for (int i = 0; i < 5; i++) {
        Body b;
        b.pos.x = GetRandomValue(120, 480);
        b.pos.y = GetRandomValue(120, 480);
        b.vel.x = 0;
        b.vel.y = 0;
        b.m = GetRandomValue(10, 50) / 10.0f;
        b.q = GetRandomValue(-100, 100) / 10.0f;
        b.c = b.q > 0 ? RED : BLUE;
        bodies.push_back(b);
    }

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Body b;
            b.pos = GetMousePosition();
            b.vel.x = 0;
            b.vel.y = 0;
            b.m = 1.0f;
            b.q = -5.0f;
            b.c = BLUE;
            bodies.push_back(b);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Body b;
            b.pos = GetMousePosition();
            b.vel.x = 0;
            b.vel.y = 0;
            b.m = 10.0f;
            b.q = 5.0f;
            b.c = RED;
            bodies.push_back(b);
        }

        for (int i = 0; i < bodies.size(); i++) {
            Vector2 a = {0, 0};
            for (int j = 0; j < bodies.size(); j++) {
                if (i == j) continue;
                Vector2 d = {
                    bodies[j].pos.x - bodies[i].pos.x,
                    bodies[j].pos.y - bodies[i].pos.y
                };
                float r = sqrtf(d.x*d.x + d.y*d.y);
                if (r < EPS) continue;
                float F = (bodies[i].q * bodies[j].q) / r;
                a.x = a.x + (F * d.x / r) / bodies[i].m;
                a.y = a.y + (F * d.y / r) / bodies[i].m;
            }
            bodies[i].vel.x = bodies[i].vel.x + a.x * dt;
            bodies[i].vel.y = bodies[i].vel.y + a.y * dt;
        }

        for (int i = 0; i < bodies.size(); i++) {
            bodies[i].pos.x = bodies[i].pos.x + bodies[i].vel.x * dt;
            bodies[i].pos.y = bodies[i].pos.y + bodies[i].vel.y * dt;

            if (bodies[i].pos.x < 0) {
                bodies[i].pos.x = 0;
                bodies[i].vel.x = bodies[i].vel.x * -WALL;
            }
            if (bodies[i].pos.x > W) {
                bodies[i].pos.x = W;
                bodies[i].vel.x = bodies[i].vel.x * -WALL;
            }
            if (bodies[i].pos.y < 0) {
                bodies[i].pos.y = 0;
                bodies[i].vel.y = bodies[i].vel.y * -WALL;
            }
            if (bodies[i].pos.y > H) {
                bodies[i].pos.y = H;
                bodies[i].vel.y = bodies[i].vel.y * -WALL;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < bodies.size(); i++) {
            DrawCircleV(bodies[i].pos, 10.0f, bodies[i].c);
        }
        EndDrawing();
    }
    CloseWindow();
}