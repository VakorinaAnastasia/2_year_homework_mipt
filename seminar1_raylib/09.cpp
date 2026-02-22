#include <raylib.h>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Circle { Vector2 pos; Color col; };

int main() {
    std::srand(std::time(0));
    int width = 600;
    int height = 600;
    InitWindow(width, height, "");
    SetTargetFPS(60);

    std::vector<Circle> circles;
    float R = 18.0f;

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 m = GetMousePosition();
            circles.push_back({m, WHITE});
        }
        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 0; i < circles.size(); i++) {
                unsigned char r = GetRandomValue(0, 255);
                unsigned char g = GetRandomValue(0, 255);
                unsigned char b = GetRandomValue(0, 255);
                circles[i].col = (Color){r, g, b, 255};
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < circles.size(); i++) {
            DrawCircleV(circles[i].pos, R, circles[i].col);
        }
        EndDrawing();
    }
    CloseWindow();
}